#include <stdio.h>

#define MAX_RESOLUTION 100

int main(void)
{
	int n, m, x, y;
	int tv_image[MAX_RESOLUTION][MAX_RESOLUTION];
	int i, j;
	int corr_x, corr_y;
	int t = 1;

	while (1)
	{
		scanf ("%d %d", &m, &n);
		
		if (!n && !m) break;
		
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf ("%d", &tv_image[i][j]);
			}
		}

		corr_x = corr_y = 0;
		while (1)
		{
			scanf ("%d %d", &x, &y);
			if (!x && !y) break;
			
			corr_x -= x;
			corr_y += y;
		}
		
		if (corr_x < 0) corr_x = (corr_x % m) + m;
		if (corr_y < 0) corr_y = (corr_y % n) + n;
		
		printf ("Teste %d\n", t++);
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf ("%d", tv_image[(i + corr_y) % m][(j + corr_x) % n]);
				if (j < (n - 1)) putc (' ', stdout);
			}
			printf ("\n");
		}
		printf ("\n");
	}
	
	return 0;
}
