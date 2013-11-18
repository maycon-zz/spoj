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
		m = 0;
		s = 0;
		aux = 1;
		
		for (i = 1;	i <= n;	i++)
		{
			scanf ("%d %d", &a, &b);			
			s += (a - b);

			if (s < 0)
			{
				aux = i+1;
				s = 0;
			}
			else if (s >= m)
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
