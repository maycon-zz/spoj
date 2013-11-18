#include <stdio.h>

int main(void)
{
	int n, i, s;
	
	scanf ("%d", &n);
	
	s = 0;
	while (n--)
	{
		scanf ("%d", &i);
		s += i;
	}
	
	printf ("%d\n", s);
	
	return 0;
}
