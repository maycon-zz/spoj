#include <stdio.h>

int main(void)
{
	int n;
	int a, b;
	int i;
	int m, s;
	int ini, fin, aux;
	int t = 1;
	
	while ((scanf ("%d", &n) != EOF) && n)
	{
		m = s = 0;
		ini = fin = aux = 1;
		
		for (i = 1;	i <= n;	i++)
		{
			scanf ("%d %d", &a, &b);			
			s += (a - b);

			if (s < 0)
			{
				aux = i+1; // inicio temporario
				s = 0;
			}

			// obtive uma soma maior
			if (s >= m)
			{
				ini = aux;
				fin = i;
				m = s;
			}
			
		}

		if (m == 0)
			printf ("Teste %d\nnenhum\n\n", t++);
		else
			printf ("Teste %d\n%d %d\n\n", t++, ini, fin);
	}
	
	return 0;
}
