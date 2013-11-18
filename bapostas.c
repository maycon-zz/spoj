#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main(void)
{
	int n, v;
	int max, sum;
	
	while ((scanf ("%d", &n) != EOF) && n)
	{
		max = sum = 0;
		
		while (n--)
		{
			scanf ("%d", &v);			
			sum += v;
			sum = MAX(sum, 0);
			max = MAX(max, sum);
		}

		if (max)
			printf ("The maximum winning streak is %d.\n", max);
		else
			printf ("Losing streak.\n");
			
	}
	
	return 0;
}
