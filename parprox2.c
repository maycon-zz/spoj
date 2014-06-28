#include <stdio.h>
#include <math.h>

#define MAXN 1001

int main(void)
{
	int N, P[MAXN][2];
	int i;

	scanf ("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf ("%d %d", &P[i][0], &P[i][1]);

	return 0;
}

