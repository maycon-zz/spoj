#include <stdio.h>

#define MAX_LEN 102

int main(void)
{
	int trafego[MAX_LEN];
	int a, v;
	int o, d;
	int maior_trafego;
	int solucao;
	int i, l, t = 1;

	memset(trafego, 0, sizeof(trafego));
	
	while ((scanf("%d %d", &a, &v) != EOF) && a)
	{
		maior_trafego = 0;
		
		for (i = 1; i <= v; i++)
		{
			scanf ("%d %d", &o, &d);
			
			trafego[o]++;
			trafego[d]++;
		}
		
		for (i = 1; i <= a; i++)
		{
			if (trafego[i] > maior_trafego)
			{
				maior_trafego = trafego[i];
			}
		}
		
		printf ("Teste %d\n", t++);
		for (i = 1; i <= a; i++)
		{
			if (trafego[i] == maior_trafego)
				printf ("%d ", i);
				
			trafego[i] = 0;
		}
	
		printf ("\n\n");
	}
	return 0;
}
