#include <stdio.h>

#define MAX_CARD 100001
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main(void)
{
	int a, b, c;
	int alice[MAX_CARD], beatriz[MAX_CARD];
	int ta, tb, i, min, max;
	
	while (1)
	{
		scanf ("%d %d", &a, &b);
		
		if (!a && !b) break;
		
		memset(alice,   0, sizeof(alice));
		memset(beatriz, 0, sizeof(beatriz));
		
		ta = tb = max = 0;
		min = MAX_CARD;
		
		while (a--)
		{
			scanf ("%d", &c);			
			alice[c] = 1;
			max = MAX(max, c);
			min = MIN(min, c);
		}
		
		while (b--)
		{
			scanf ("%d", &c);
			beatriz[c] = 1;
			max = MAX(max, c);
			min = MIN(min, c);
		}

			
		
		for (i = min; i <= max; i++)
		{
			if (alice[i] && !beatriz[i])
				ta++;
			else if (!alice[i] && beatriz[i])
				tb++;
		}
		
		printf ("%d\n", MIN(ta, tb));
	}
	
	return 0;
}