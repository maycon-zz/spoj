#include <stdio.h>
#include <string.h>

#define MAX      1000000
#define SQRT_MAX 1000

int main(void)
{
	int crivo[SQRT_MAX];
	int p, i, j;
	
	// monta o Crivo de Erastotenes
	{
		int crivo_tmp[SQRT_MAX];

		memset(crivo_tmp, 0, sizeof(crivo_tmp));
		
		crivo[0] = 1;
		crivo[1] = 1;
		crivo[2] = 0;
		p = 3;
		
		for (i = 3; i < SQRT_MAX; i++)
		{
			if (!crivo_tmp[i])
			{
				printf ("%d ", i);
				crivo[p++] = i;
				for (j = i*2; j < MAX; j += i)
				{
					crivo_tmp[j]++;
				}
			}
		}
		
		while (i < MAX)
		{
			if (!crivo[i]) crivo[p++] = i;
			i++;
		}
	}
	
	for (i = 0; i < 30; i++)
	{
		printf ("%d ", crivo[i]);
	}
	
	return 0;
}

