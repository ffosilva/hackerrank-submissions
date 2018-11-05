#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_BUFFER 9995  // len("1000 ") * 1999

int line_values[1001];

int n_lin_col(int val) {
    return (val * 2) - 1;
}

void get_line(int val, int line_num, char **output) {
    char *line = (char *) calloc(MAX_BUFFER, sizeof(char));
    *output = line;
    int w = n_lin_col(val);
    int min_val = val - (line_num - 1);
    if (min_val < 1) {
        min_val = 2 + abs(min_val);
    }

    int cursor = 0, num = val, pos = w / 2;

    for (int i = 1; i <= w; i++) { 
        cursor += sprintf(line + cursor, " %d", num);
        line_values[i] = num;

        if (num > min_val && i <= w / 2) {
            num -= 1;
        } else if (i > w/2) {
            num = line_values[pos--];
        }
    }
}

int main() 
{

    int n;
    scanf("%d", &n);

    char *line_str;
    for (int i = 1; i <= n_lin_col(n); ++i) {
        get_line(n, i, &line_str);
        printf("%s\n", line_str + 1);
        free(line_str);
    }

    return 0;
}
