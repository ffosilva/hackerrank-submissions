#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

#define MIN_N 2

void calculate_the_maximum(int n, int k) {
    int a_and_b, a_or_b, a_xor_b;
    int max_a_and_b = 0, max_a_or_b = 0, max_a_xor_b = 0;

    for (int a = 1; a < n; ++a) {
        for (int b = a + 1; b <= n; ++b) {
            a_and_b = a & b;
            a_or_b  = a | b;
            a_xor_b = a ^ b;

            if (a_and_b > max_a_and_b && a_and_b < k) max_a_and_b = a_and_b;
            if (a_or_b > max_a_or_b && a_or_b < k) max_a_or_b = a_or_b;
            if (a_xor_b > max_a_xor_b && a_xor_b < k) max_a_xor_b = a_xor_b;
        }
    }

    printf("%d\n%d\n%d\n", max_a_and_b, max_a_or_b, max_a_xor_b);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}

