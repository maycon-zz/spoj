#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 1000
#define PI (2*acos(0))

int cmp_dbl(const void *a, const void *b) {
	double x = *(double *)a;
	double y = *(double *)b;
	if (x == y) return 0;
	return x < y ? -1 : 1;
}

int main(void)
{
	int x[MAXN], y[MAXN];
	int t, n, i, j, k, r, m;
	double coef[MAXN], c;

	scanf ("%d", &t);
	while(t--) {
		scanf ("%d", &n);
		for (i = 0; i < n; i++) {
			scanf ("%d %d ", &x[i], &y[i]);
		}

		if (n < 3) { printf ("%d\n", n); continue; }

		for (i = 0, m = 0; i < n-m; i++) {
			for (j = i+1, k = 0; j < n; j++) {
				c = atan2(x[j] - x[i], y[j] - y[i]);
				if (c <= 0) c += PI;
				coef[k++] = c;
			}

			qsort(coef, k, sizeof(double), cmp_dbl);
			for (j = 1, r = 2; j < k; j++) {
				if (coef[j] == coef[j-1]) r++;
				else {
					if (r > m) m = r;
					r = 2;
				}
			}
			if (r > m) m = r;
		}

		printf ("%d\n", m);
	}

	return 0;
}
