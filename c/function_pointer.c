#include <stdio.h>

void test(int x, int (*func)(const char *format, ...)) {
    func("%d\n", x);
}

void main() {
    test(10, printf);
}
