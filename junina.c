#include <stdio.h>
#include <string.h>

#define MAXN 21

int main(void)
{
	int graph[MAXN][MAXN];
	int N;
	int aux, i, j, k, t = 0;

	while (1) {
		scanf ("%d", &N);
		if (!N) break;

		memset(graph, 0, sizeof(graph));

		for (i = 1; i <= N; i++) {
			
			while (scanf("%d", &j) && j) {
				graph[i][j] = 1;
				graph[j][i] = 1;
			}
		}

		int resp = 0;

		for (i = 1; i <= N; i++) {
			int qt = 0;
			printf ("pivot = %d\n", i);
			for (j = i+1; j <= N; j++) {
				if (!graph[i][j]) {
					printf ("%d like %d", j, i);
					qt++; // count j
					for (k = 2; k < j; k++) {
						if (!graph[k][i] && graph[k][j]) {
							qt--; // uncount j
							printf (", but %d unlike %d", j, k);
							break;
						}
					}
					printf ("\n");
				}	
			}
			printf ("\n");
			if (qt > resp) resp = qt;
		}

		printf ("Teste %d\n%d\n\n", ++t, resp);
	}

	return 0;
}
