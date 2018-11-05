#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n, sum = 0;
    scanf("%d", &n);
    while (n > 9) {
        sum += n % 10;
        n /= 10;
    }

    sum += n;

    printf("%d\n", sum);
    return 0;
}
