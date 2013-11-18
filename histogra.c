#include <stdio.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define MAX_LARGURA 100000
#define MAX_ALTURA	1000000000

int main(void)
{
	int n;
	int i;
	int m, s;
	int ini, fin, aux;
	int area, maior_area;
	int altura, menor_altura;
	
	while ((scanf ("%d", &n) != EOF) && n)
	{
		m = 0;
		s = 0;
		aux = 1;
		menor_altura = 1000000000;
		maior_area = 0;
		area = 0;
		ini = fin = 1;
		
		for (i = 1;	i <= n;	i++)
		{
			scanf ("%d", &altura);
			
			menor_altura = MIN(menor_altura, altura);
			area = menor_altura*(fin - ini + 1);
			maior_area = MAX(maior_area, area);
			
			printf ("%d) menor altura: %d / area = * %d = %d / maior area = %d\n", i, menor_altura, (fin - ini + 1), area, maior_area);
			if (area < maior_area)
			{
				aux = i+1;
				s = 0;
			}
			else if (area >= maior_area)
			{
				ini = aux;
				fin = i;
				m = s;
			}
		}
		
		printf ("%d\n", maior_area);
	}
	
	return 0;
}

