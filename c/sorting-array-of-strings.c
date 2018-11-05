#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort_by_length(const char* a, const char* b);

int is_equal(const char* a, const char* b) {
    if (strlen(a) == strlen(b)) {
        for (int i = 0; i < strlen(a); i++) {
            if(a[i] != b[i]) return 0;
        }
    } else {
        return 0;
    }

    return 1;
}

int lexicographic_sort(const char* a, const char* b) {
    if (is_equal(a, b)) return 0;

    int min_letters = strlen(a) < strlen(b) ? strlen(a) : strlen(b);
    for (int i = 0; i < min_letters; i++) {
        if (a[i] != b[i]) return a[i] - b[i];
    }

    return sort_by_length(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return -lexicographic_sort(a, b);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int *chars_a = (int *) calloc(256, sizeof(int)),
        *chars_b = (int *) calloc(256, sizeof(int)),
        count_a = 0,
        count_b = 0;

    for (int i = 0; i < strlen(a); ++i) {
        if (chars_a[a[i]] == 0) count_a++;
        chars_a[a[i]]++;
    }

    for (int i = 0; i < strlen(b); ++i) {
        if (chars_b[b[i]] == 0) count_b++;
        chars_b[b[i]]++;
    }

    if (count_a == count_b) return lexicographic_sort(a, b);
    else return count_a - count_b;
}


int sort_by_length(const char* a, const char* b) {
    if (strlen(a) == strlen(b)) return lexicographic_sort(a, b);
    else return strlen(a) - strlen(b);
}

void swap(char **xp, char **yp) 
{ 
    char *temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
   int i, j; 
   for (i = 0; i < len-1; i++)       
       for (j = 0; j < len-i-1; j++)  
           if (cmp_func(arr[j], arr[j+1]) > 0) 
              swap(&arr[j], &arr[j+1]); 
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
