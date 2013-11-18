#include <stdio.h>
#include <math.h>

#define MAX_PD 20

double pd[MAX_PD];

double func(int n)
{
	if (n < MAX_PD)
	{
		if (!pd[n])
			pd[n] = (func(n - 1) * 2) - 1;
		
		return pd[n];
	}
	else
		return (func(n - 1) * 2) - 1;
}

int main(void)
{
	double n;
	int t = 1;

	pd[0] = 2;
	
	while ((scanf("%lf", &n) != EOF) && (n != -1))
	{
		printf ("Teste %d\n%.0lf\n\n", t++, pow(func(n), 2));
	}
	return 0;
}
