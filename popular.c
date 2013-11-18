#include <stdio.h>
#include <string.h>

#define MAX 100

int main(void)
{
	int n, i, j;
	int val_max;
	int v[MAX], t;
	
	memset(v, 0, sizeof(v));

	while ((scanf("%d", &n) != EOF) && n)
	{
		
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf ("%d", &t);
				v[j] += t;
			}
		}
		
		val_max = 0;
		for (i = 0; i < n; i++)
		{
			if (v[i] > val_max)
			{
				val_max = v[i];
			}
			
			v[i] = 0;
		}
		
		printf ("%d\n", val_max);
	}

	return 0;
}
