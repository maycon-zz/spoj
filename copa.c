#include <stdio.h>

int main(void)
{
	int total, pontos;
	char time[100];
	int times, jogos, i;
	
	while (1)
	{
		scanf ("%d %d ", &times, &jogos);
		if (!times && !jogos) break;
		
		total = 0;
		while (times--)
		{
			scanf ("%s %d ", time, &pontos);
			total += pontos;
		}
		
		printf ("%d\n", 3*jogos - total);
	}
	
	return 0;
}
