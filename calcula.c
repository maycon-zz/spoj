#include <stdio.h>

int main(void)
{
	int a, n;
	int i, r;
	char c;
	
	a = 1;
	while(scanf ("%d ", &n) && n)
	{	
		scanf ("%d", &r);
	
		while (--n)
		{
			scanf ("%c%d", &c, &i);
			if (c == '+') r += i;
			else  		  r -= i;
		}
		
		printf ("Teste %d\n%d\n\n", a++, r);
	}
	return 0;
}
