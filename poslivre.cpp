#include <cstdio>

using namespace std;

#define MAXN 100
#define MAX 501

int main(void)
{
	int W, H, N;
	int X1, Y1, X2, Y2;

	int M[MAX][MAX];

	while (1)
	{
		scanf ("%d %d %d", &W, &H, &N);
		if (!W && !H && !N) break;

		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++)
				M[i][j] = 0;

		while (N--)
		{
			scanf ("%d %d %d %d", &X1, &Y1, &X2, &Y2);

			int aux;

			if (X1 > X2) { aux = X1; X1 = X2; X2 = aux; }
			if (Y1 > Y2) { aux = Y1; Y1 = Y2; Y2 = aux; }

			for (int i = Y1; i <= Y2; i++)
				for (int j = X1; j <= X2; j++)
					M[i][j] = 1;
		}

		int result = 0;
		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++)
				result += (M[i][j] == 0);

		if (result == 0)
			printf ("There is no empty spots.\n");
		else if (result == 1)
			printf ("There is one empty spot.\n");
		else
			printf ("There are %d empty spots.\n", result);
	}

	return 0;
}

