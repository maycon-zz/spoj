#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 1000
#define PI (2*acos(0))
#define R2G(a) ((180*a)/PI)

const double EPS=1e-9;

typedef struct {
	int x, y;
} Ponto;

int cmp_dbl(const void *a, const void *b) {
	double x = *(double *)a;
	double y = *(double *)b;
	if (fabs(x - y) <= EPS) return 0;
	return x < y ? -1 : 1;
}

int main(void)
{
	Ponto p[MAXN];
	int t, n, i, j, k, r, m;
	int tg0, tg45, tg90, tg;

	scanf ("%d", &t);
	while(t--) {
		scanf ("%d", &n);
		for (i = 0; i < n; i++) {
			scanf ("%d %d ", &p[i].x, &p[i].y);
		}

		if (n < 3) { printf ("%d\n", n); continue; }

		m = 0;
		for (i = 0; i < n-m; i++) {
			for (j = i+1, k = 0; j < n; j++) {
				tg = (int)R2G(atan2(p[j].x - p[i].x, p[j].y - p[i].y));				
				printf ("%d\n", tg);
			}
		}

		printf ("%d\n", m);
	}

	return 0;
}
