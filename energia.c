#include <stdio.h>

#define LEN_MAX 101

void GoShadow(int m[LEN_MAX][LEN_MAX], int a[LEN_MAX], int n, int ini)
{
	int i;
	
	if (a[ini]) return;
	a[ini] = 1;
	
	for (i = 1; i <= n; i++)
		if (m[ini][i])
			GoShadow(m, a, n, i);	
}

int main(void)
{
	int m[LEN_MAX][LEN_MAX], a[LEN_MAX];
	int e, l, x, y, t;
	int i, j, falha;
	
	t = 1;
	while (scanf ("%d %d", &e, &l) && e && l)
	{
		for (i = 1; i <= e; i++)
		{
			a[i] = 0;
			for (j = i; j <= e; j++)
				m[i][j] = m[j][i] = 0;
		}
				
		for (i = 1; i <= l; i++)
		{
			scanf ("%d %d", &x, &y);
			m[x][y] = m[y][x] = 1;
		}

		GoShadow(m, a, e, 1);
		
		falha = 0;
		for (i = 1; (i <= e) && !falha; i++)
		{
			if (!a[i])
			{
				printf ("Teste %d\nfalha\n\n", t++);
				falha = 1;
			}
		}
		
		if (!falha)
			printf ("Teste %d\nnormal\n\n", t++);
	}
	
	return 0;
}
