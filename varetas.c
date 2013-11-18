#include <stdio.h>
#include <math.h>

int main(void)
{
	int n;
	int c, v;
	int t, r;
	
	while (1)
	{
		scanf("%d", &n);

		if (!n) break;

		t = r = 0;
	
		while (n--)
		{
			scanf("%d %d ", &c, &v);

			if (v >= 4)
			{
				// Divido as varetas em quadrados acumulados em (t)otal
				t += floor(v / 4);
				
				// Calculo quantas varetas sobraram
				v %= 4;
			}
	
			// Se existir resto que forme dois lados do retangulo
			if (r >= 2)
			{
				// Verifico se pode formar mais um retangulo com o restante
				// das varetas atuais
				if (v >= 2)
				{
					t++;
					r = 0; // nao tem mais resto =P
				}
			}
			else
			{
				// salvo o resto como sendo o restante das varetas atuais
				r = v;
			}
		}
		
		// Vai sombra!!
		printf ("%d\n", t);
	}
	
	return 0;
}
