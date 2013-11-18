#include <stdio.h>

int main(void)
{
	int t, a, b, ta, tb;

	scanf ("%d %d %d ", &t, &a, &b);
	
	ta = tb = 0;
	
	while (((ta % a) != t) && ((tb % b) != t))
	{
		ta += b;
		tb += a;		
	}
	
	printf ("%d\n", ((ta % a) == t) ? ta : tb);

	return 0;
}
