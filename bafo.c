#include <stdio.h>

int main(void)
{
	int n, a, b, sa, sb, t=1;
	
	while (scanf("%d", &n) && n)
	{
		sa = sb = 0;
		
		while (n--)
		{
			scanf ("%d %d", &a, &b);
			sa += a;
			sb += b;
		}
		
		if (sa > sb)
			printf ("Teste %d\nAldo\n\n", t++);
		else
			printf ("Teste %d\nBeto\n\n", t++);
	}
	return 0;
}
