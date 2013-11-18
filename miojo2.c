#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main(void)
{
	int t, a, b, r;
	int n1, n2;
	
	scanf ("%d %d %d", &t, &a, &b);
	r  = 0;
	n1 = a;
	n2 = b;

	while ((a != t) && (b != t))
	{
		if (a > b)
		{
			r += b;
			a -= b;
			b = n2;
		}
		else
		{
			r += a;
			b -= a;
			a = n1;

		}
	}

	printf ("%d\n", r + ((a == t) ? a : b));
	return 0;
}
