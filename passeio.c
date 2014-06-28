#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXP 151

int P, L, I;
int altura[MAXP];
int grafo[MAXP][MAXP*(MAXP-1)];
int qt[MAXP];
int viz[MAXP];
int pd[MAXP];

int dfs(int v) {
	int i, d = 0, m = 0;
	if (pd[v]) return pd[v];
	if (viz[v]) return 0;

	viz[v] = 1;
	for (i = 0; i < qt[v]; i++) {
		d = 1 + dfs(grafo[v][i]);
		if (d > m) m = d;
	}
	viz[v] = 0;	
	pd[v] = m;

	return m;
}

int main(void)
{
	int i, a, b, t = 0;

	while (1) {
		scanf ("%d %d %d ", &P, &L, &I);
	
		for (i = 0; i <= P; i++) {
			viz[i] = qt[i] = pd[i] = 0;
		}

		if (!P && !L && !I) break;
		for (i = 1; i <= P; i++) scanf("%d ", &altura[i]);

		for (i = 0; i < L; i++) {
			scanf ("%d %d", &a, &b);
			if (altura[b] < altura[a]) grafo[a][qt[a]++] = b;
		}

		printf ("Teste %d\n%d\n\n", ++t, dfs(I));
	}
}

