#include <stdio.h>
#include <string.h>

int main(void)
{
	int t, n, i, m;
	int v[10001];

	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		memset(v, 0, sizeof(int) * n);

		for (i = 1; i <= n; i++) {
			scanf ("%d", &m);
			v[m] = i;
		}

		int d = 0, aux;
		for (i = 1; i <= n; i++) {
			while (v[i] != i) {
				v[v[i]] = (v[v[i]] + v[i]) - (v[i]=v[v[i]]);
				d++;
			}
		}

		printf ("%d\n", d);

	}

	return 0;
}

