#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 1000

const double EPS=1e-9;

typedef struct {
	int x, y;
} Ponto;

//   .-         -.
//   | x1  y1  1 |
// D | x2  y2  1 | = x1*y2 + y1*x3 + x2*y3 - x1*y3 - y1*x2 - y2*x3 == 0
//   | x3  y3  1 |
//   '-         -'

int main(void)
{
	Ponto p[MAXN];
	int t, n, d;
	int i, j, k, r, m;

	scanf ("%d", &t);
	while(t--) {
		scanf ("%d ", &n);
		for (i = 0; i < n; i++) {
			scanf ("%d %d ", &p[i].x, &p[i].y);
		}

		if (n < 3) { printf ("%d\n", n); continue; }
		
		m = 0;
		for (i = 0; i < n - m; i++) {
			for (j = i+1; j < n-1; j++) {
				r = 2; // qt de colineares
				d = p[i].x * p[j].y - p[i].y*p[j].x;
				for (k = j+1; k < n; k++) {
					 //if (d + p[i].y*p[k].x  + p[j].x*p[k].y - p[j].y*p[k].x  - p[i].x*p[k].y == 0) r++;
					 if (d + p[k].x*(p[i].y - p[j].y)  + p[k].y*(p[j].x  - p[i].x) == 0) r++;
				}
				if (r > m) m = r;
			}
		}

		printf ("%d\n", m);
	}

	return 0;
}
