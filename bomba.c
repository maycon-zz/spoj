#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define LIM 20

typedef struct
{
	int x, y;
}
Ponto;


double dist( double ax, double ay, double bx, double by )
{
    return sqrt( ( ax - bx ) * ( ax - bx ) + ( ay - by ) * ( ay - by ) );
}

int compara(const void *a, const void *b)
{
	return *(float *)a - *(float *)b;
}

int main(void)
{
	Ponto p[LIM];
	float dist[LIM][LIM];
	int n, m;
	int i, j;
	
	while (1)
	{
		scanf ("%d %d", &n, &m);
		if (!n && !m) break;
		
		for (i = 0; i < n; i++)
			scanf ("%d %d", &p[i].x, &p[i].y);

	}
	return 0;
}
