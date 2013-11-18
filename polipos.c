#include <stdio.h>
#include <string.h>

#define TAM  1001

int main(void)
{
	int carros[TAM];
	int n, i;
	int carro, pos, npos, erro;
	
	while (1)
	{
		scanf ("%d", &n);
		if (!n) break;
		
		memset (carros, 0, n * sizeof(int));
		erro = 0;
		for (i = 0; i < n; i++)
		{
			scanf ("%d %d", &carro, &pos);
			npos = i+pos;
			
			if (!erro)
			{
				if ((npos < 0) || (npos >= n) || carros[npos])
					erro = 1;
				else
					carros[npos] = carro;
			}
		}
		
		if (erro)
			printf ("-1\n");
		else
		{
			for (i = 0; i < n; i++)
				printf ("%d ", carros[i]);
			printf ("\n");
		}
	}
	
	return 0;
}