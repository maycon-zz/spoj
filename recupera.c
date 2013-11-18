#include <stdio.h>

int main(void)
{
	int n, i, v, soma, foi;
	int t = 1;
	
	while (scanf ("%d", &n) != EOF)
	{
		soma = 0;
		foi = 0;
		for (i = 1; (i <= n) && !foi; i++)
		{
			if (soma == i)
			{
				printf ("Instancia %d\n%d\n\n", t++, soma);
				foi = 1;
			}

			scanf ("%d", &v);
			soma += v;
		}

		while (i <= n) { i++; scanf ("%*d"); }
		
		if (!foi)
		{
			printf ("Instancia %d\nnao achei\n\n", t++);
		}
	}
}
