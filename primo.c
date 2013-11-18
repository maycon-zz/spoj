#include <stdio.h>

int main(void)
{
	int n, i;
	
	scanf ("%d", &n);
	
	if (n < 0) n = -n;
	
	if ((n == 2) || (n == 3))
	{
		printf ("sim\n");
		return 0;
	}
	
	if ((n % 2 == 0) || (n % 3 == 0))
	{
		printf ("nao\n");
		return 0;
	}

	int p, max = sqrt(n) + 2;
	for (p = 5; p < max; p += 6)
		if ((n % p == 0) || (n % (p+2) == 0))
		{
			printf ("nao\n");
			return 0;
		}
		
	printf ("sim\n");

	return 0;
}
