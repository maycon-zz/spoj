#include <stdio.h>

int main(void)
{
	int t, n;
	int a, b;
	int sum1, sum2;
	
	t = 1;
	while ((scanf ("%d", &n) != EOF) && n)
	{
		printf ("Teste %d\n", t++);
		sum1 = sum2 = 0;
		while (n--)
		{
			scanf ("%d %d", &a, &b);
			sum1 += a;
			sum2 += b;
			
			printf ("%d\n", sum1 - sum2);
		}
		
		printf ("\n");
	}
	
	return 0;
}
