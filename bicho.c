#include <stdio.h>

int main(void)
{
	
	int m, gm, n, gn;
	double v, r;
	
	while (1)
	{
		scanf ("%lf %d %d", &v, &n, &m);

		if (!v && !n && !m)
			break;
		
		r = 0;

		if ((m % 10000) == (n % 10000)) r = 3000;
		else if ((m % 1000) == (n % 1000)) r = 500;
		else if ((m % 100) == (n % 100)) r = 50;
		else
		{
			// Calcula os grupos
			gm = (int)ceil((m % 100) / 4.0f);
			gn = (int)ceil((n % 100) / 4.0f);
			
			// caso seja 00, deve ir para o grupo 25
			if (!gm) gm = 25;
			if (!gn) gn = 25;
					
			// Pertencem ao mesmo grupo
			if (gm == gn) r = 16;
		}
		
		printf ("%.02lf\n", r * v);
	}

	return 0;
}
