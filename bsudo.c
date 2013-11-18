#include <stdio.h>
#include <string.h> // memset

#define LEN_TAB 9 // tamanho do tabuleiro
#define CHAR2INT(c) (c) - '0'


int main(void)
{
	int linhas[LEN_TAB], colunas[LEN_TAB];
	int n, i, j, k, v, tmp;
	char c;
	
	scanf ("%d%*[\r\n]", &n);
	
	while (n--)
	{
		memset(linhas, 0, sizeof(linhas));
		memset(colunas, 0, sizeof(colunas));
		
		for (i = 0; i < LEN_TAB; i++)
		{
			for (j = 0; j < LEN_TAB; j++)
			{
				scanf ("%c", &c);
				if (c != '0')
				{
					v = 1 << (CHAR2INT(c) - 1);
					linhas[i]  |= v;
					colunas[j] |= v;
				}
			}
			scanf ("%*[\r\n]");
		}

		for (i = 0; i < LEN_TAB; i++)
		{
			for (j = 0; j < LEN_TAB; j++)
			{
				tmp = 0;
				for (k = 1; k <= 9; k++)
				{
					v = (1 << (k - 1));
					if (((linhas[i] & v) > 0) && ((colunas[j] & v) > 0))
					{
						printf ("%d ", k);
						tmp = 1;
						break;
					}
				}
				if (tmp == 0)
				{
					printf ("0 ");
				}
			}
			printf ("\n");
		}
	}
	
	return 0;
}
