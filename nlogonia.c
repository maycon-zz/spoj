#include <stdio.h>

int main(void)
{
	int k, n, m;
	int x, y;
	
	while ((scanf("%d", &k) != EOF) && k)
	{
		scanf ("%d %d", &n, &m);
		while (k--)
		{
			scanf ("%d %d", &x, &y);
			
			if ((n == x) || (m == y))
			{
				printf ("divisa\n");
			}
			else if ((n < x) && (m < y))
			{
				printf ("NE\n");
			}
			else if ((n > x) && (m < y))
			{
				printf ("NO\n");
			}
			else if ((n > x) && (m > y))
			{
				printf ("SO\n");
			}
			else
			{
				printf ("SE\n");
			}
		}
	}
	
	return 0;
}
