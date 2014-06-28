#include <stdio.h>

int main(void)
{
	int n, i, v, soma, achou, resultado;
	int t = 1;
	
	while (scanf ("%d", &n) != EOF)
	{
		soma = 0;
		achou = 0;
		
		for (i = 0; i < n; i++)
		{
			scanf ("%d", &v);
			if (!achou && (soma == v))
			{
				achou = 1;
				resultado = soma;
			}
			soma += v;
		}
		
		if (achou)
			printf ("Instancia %d\n%d\n\n", t++, resultado);
		else
			printf ("Instancia %d\nnao achei\n\n", t++);
	}

	return 0;
}

