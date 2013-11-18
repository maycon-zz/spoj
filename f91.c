#include <stdio.h>

int main(void)
{
	int n;

	while(1)
	{
		scanf("%d", &n);
		if (!n) break;
		
		if (n > 100)
			printf ("f91(%d) = %d\n", n, n - 10);
		else
			printf ("f91(%d) = 91\n", n);
		
	}

	return 0;
}

