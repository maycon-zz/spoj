#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

inline int compara(const void *a, const void *b)
{
	long long x = *(long long *)a;
	long long y = *(long long *)b;

	if (x == y) return 0;
	return x > y;
}

int main(void)
{
	int N, i, j, qt, pos, n;
	long long p[MAX][2], d[MAX];
	long long x, y;

	while (scanf("%d", &N) && N) {

		for (i = 0; i < N; i++) {
			scanf ("%ld %ld", &p[i][0], &p[i][1]);
		}

		qt = 0;

		for (i = 0; i < N; i++) {
			pos = 0;
			for (j = 0; j < N; j++) {
				x = p[i][0]  - p[j][0];
				y = p[i][1] - p[j][1];
				if (x*x + y*y) d[pos++] = x*x + y*y;
			}

			qsort(d, pos, sizeof (long long), compara);

			n = 1;
			for (j = 1; j < pos; j++) {
				if (d[j] != d[j-1]) {
					qt += (n * (n - 1)/2);
					n = 1;
				} else n++;
			}
			qt += (n * (n - 1)/2);
		}

		printf ("%ld\n", qt);

	}

	return 0;
}



