#include <stdio.h>

int main(void)
{
	int n, i, p, winner, t = 1;
	
	while (1)
	{
		scanf ("%d", &n);
		if (!n) break;
		for (i = 1; i <= n; i++)
		{
			scanf ("%d", &p);
			if (p == i) winner =  p;
		}
		printf ("Teste %d\n%d\n\n", t++, winner);
	}
	
	return 0;
}
