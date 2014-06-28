#include <cstdio>


int main(void)
{
	int p[41], j[40];
	int n, m, g, a, b;
	char c;

	while (scanf("%d %d %d", &n, &m, &g) && (n+m+g)) {
		for (int i = 0; i < 40; i++)
			p[i] = j[i] = 0;

		for (int i = 0; i < g; i++) {
			scanf ("%d %c %d", &a, &c, &b);
			j[a]++; j[b]++;
			if (c == '=') {
				p[a]++;
				p[b]++;
			}
			else
				p[b] += 2;
		}

		for (int i = 0; i < n; i++) {
			printf ("Time %d / Jogos %d / Pontos %d\n", i, j[i], p[i]);
		}

		int ok = 1, max = p[0] + 2*(g - j[0]);
		for (int i = 1; (i < n) && ok; i++) {
			if (p[i] >= max) ok = 0;
		}
		printf (ok ? "Y\n" : "N\n");
	}

	return 0;
}

