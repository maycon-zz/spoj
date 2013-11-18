#include <stdio.h>

int main(void)
{
	unsigned long long n, i, r;
	scanf ("%lld", &n);
	if (!n) printf ("1\n");
	else
	{
		for (i = 2, r = n; (i < n) && (r *= i); i++);
		printf ("%lld", r);
	}

	return 0;
}

