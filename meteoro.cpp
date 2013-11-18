#include <stdio.h>
#include <math.h>

int main(void)
{
	int x1, y1, x2, y2;
	int n, t = 1, r;
	int x, y;

	while (1)
	{
		scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		if (!x1 && !y1 && !x2 && !y2)
			break;
			
		scanf ("%d", &n);
		
		r = 0;
		while (n--)
		{
			scanf ("%d %d", &x, &y);
			
			if ( (x >= x1) && (x <= x2) && (y >= y2) && (y <= y1) )
				r++;
		}
		
		printf ("Teste %d\n%d\n\n", t++, r);
	}
	
	return 0;
}
