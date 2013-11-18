#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x1, y1;
	int x2, y2;
	
	while((scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF) && x1)
	{
		if ((x1 == x2) && (y1 == y2))
			printf ("0\n");
		else if ((x1 == x2) || (y1 == y2) || (abs(x2 - x1) == abs(y2 - y1)))
			printf ("1\n");
		else
			printf ("2\n");
	}
	
	return 0;
}
