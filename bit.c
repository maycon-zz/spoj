#include <stdio.h>

int main(void)
{
	int i = 1, n;	

	while (scanf ("%d", &n) && n)
	{
		printf ("Teste %d\n%5$d %4$d %3$d %2$d\n", i++, n % 5, (n %= 10)/5, (n %= 50)/10, (n / 50));
	}
	
	return 0;
}

