#include <stdio.h>

int main(void)
{
	int n, v_ant, v, r, t = 1;
	
	while(scanf("%d", &n) != EOF)
	{
		v_ant = 0;
		r = 1;
		
		printf ("Case #%d:", t++);
		
		while (n--)
		{
			scanf ("%d", &v);
			printf (" %d", v);
			if ( v < v_ant ) r = 0;
			v_ant = v;
		}
		
		if (r)
			printf ("\nThis is an A-sequence.\n");
		else
			printf ("\nThis is not an A-sequence.\n");
	}
	
	return 0;
}
