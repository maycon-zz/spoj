#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXN 1000

const double EPS=1e-9;
	
int table[100001][100001];

int main(void)
{
	int t, x, y;
	int i, n;

	scanf ("%d", &t);
	while(t--) {
		scanf ("%d ", &n);

		memset(table, 0, sizeof(table));

		for (i = 0; i < n; i++) {
			scanf ("%d %d ", &x, &y);
			if (table[x][y]) {
				int a = 1, b = 0;
				printf ("%d\n", a/b);
			}
			table[x][y] = 1;
		}

	}

	return 0;
}
