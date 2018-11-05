#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char buffer[1001];
    int count[11], pos;

    for (pos = 1; pos <= 10; ++pos) {
        count[pos] = 0;
    }

    scanf("%[^\n]", buffer);

    for (pos = 0; pos < strlen(buffer); pos++) {
        if (buffer[pos] >= 48 && buffer[pos] <= 57) {
            count[buffer[pos] - 47] += 1;
        }
    }

    for (pos = 1; pos <= 10; ++pos) {
        printf("%d ", count[pos]);
    }

    printf("\n");

    return 0;
}

