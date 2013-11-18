#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 7

int main(void)
{
	int m[MAX][MAX], list[MAX*MAX], visited[MAX], exists_vertex[MAX];
	int n, i, j, k, t = 0;
	int a, b;
	
	
	while (1)
	{
		scanf ("%d", &n);
		if (!n) break;
	
		memset(m, 0, sizeof(m));
		memset(exists_vertex, 0, sizeof(exists_vertex));
		
		for (i = 0; i < n; i++)
		{
			scanf ("%d %d", &a, &b);
			m[a][b] = ++m[b][a];
			exists_vertex[a] = 1;
			exists_vertex[b] = 1;
		}
		printf ("Teste %d\n", ++t);

		int impar = 0;
		for (i = 0; i < MAX; i++)
		{
			int grau = 0;
			for (j = 0; j < MAX; j++) if (m[i][j] && (i != j)) grau += m[i][j];
			if (grau % 2 == 1) impar++;
		}
	
		if ((impar != 0) && (impar != 2))
		{
			printf ("nao\n\n");
			continue;
		}

		memset (visited, 0, sizeof(visited));

		for (k = 0; k < MAX && !exists_vertex[k]; k++);
	
		i = 0; j = 0;
		list[j++] = k;
		while (i < j)
		{
			for (k = 0; k < MAX; k++)
			{
				if (m[list[i]][k] && !visited[k])
				{
					visited[k] = 1;
					list[j++] = k;
				}
			}
			i++;
		}
		
		int error = 0;
		
		for (i = 0; (i < MAX) && !error; i++)
			if (exists_vertex[i] && !visited[i]) error = 1;
		
		if (error)
			printf ("nao\n\n");
		else
			printf ("sim\n\n");
	}
	
	return 0;
}