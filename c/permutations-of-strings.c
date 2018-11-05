// Algorithm reference:
// https://www.bernardosulzbach.com/lexicographic-permutations/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **s, int i, int j) {
    char *tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}

void reverse(char **s, int i, int j) {
    for (int offset = 0; offset < (j - i + 1) / 2; offset++) {
        swap(s, i + offset, j - offset);
    }
}

int next_permutation(int n, char **s)
{
    if (n == 1) {
        return 0;
    }

    int i = n - 2;
    while (i >= 0) {
        if (strcmp(s[i], s[i + 1]) < 0) {
            break;
        }

        --i;
    }

    if (i < 0) return 0;

    int j = n - 1;

    while (j > i + 1 && !(strcmp(s[j], s[i]) > 0)) {
        --j;
    }

    swap(s, i, j);
    reverse(s, i + 1, n - 1);

    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
