#include <stdio.h>

int main(void)
{
	int l, n_atu, n_ant, s;
	int i;

	while (1)
	{
		scanf ("%d %d ", &n_ant, &l);
		if (n_ant == 0) break;

		for (s = 0, i = 0; i < l; i++)
		{
			scanf ("%d ", &n_atu);

			if (n_atu < n_ant)
			{
				s += (n_ant - n_atu);
			}

			n_ant = n_atu;
		}

		printf ("%d\n", s);
	}
	
	return 0;
}
