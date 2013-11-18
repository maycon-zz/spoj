#include <stdio.h>

#define MAX 31

int main(void)
{
	int n, t = 0;
	
	while (1)
	{
		scanf ("%d", &n);
		if (!n) break;
		
		printf ("Teste %d\n%d\n\n", ++t, (1 << n) - 1);
	}
		
	return 0;
}
