#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

double area(const triangle* tr) {
    double p = (tr->a + tr->b + tr->c) / 2.0;
    return sqrt(p * (p - tr->a) * (p - tr->b) * (p - tr->c));
}

int compare(const void *a, const void *b) {
    if (area(a) - area(b) > 0) return 1;
    if (area(a) - area(b) < 0) return -1;
    return 0;
}

void sort_by_area(triangle* tr, int n) {
    qsort(tr, n, sizeof(triangle), compare); 
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
