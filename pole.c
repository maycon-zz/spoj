#include <stdio.h>

#define MAX 10000

typedef struct
{
	int x, y, h;
} Poste;


int main(void)
{
	Poste postes[MAX];
	int n, i;
	
	while (1)
	{
		scanf ("%d", &n);
		if (!n) break;
		
		for (i = 0; i < n; i++)
			scanf ("%d %d %d", &postes[i].x, &postes[i].y, &postes[i].h);
			
		qsort(postes, n, sizeof(Poste), compara_postes);
	}
	
	return 0;
}