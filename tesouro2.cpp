#include <cstdio>

#define MAXN 1001

using namespace std;

int n;
int M[MAXN][MAXN];	 // matriz
int V[MAXN];		 // valores
int pd[MAXN];

int do_read()
{
	int a, b;
	
	scanf ("%d", &n);
	if (n == 0) return 0;
	
	for (int i = 0; i < n; i++)
	{
		pd[i] = -1;
		for (int j = 0; j < n; j++)
			M[i][j] = 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		scanf ("%d", &V[i]);
		scanf ("%d", &a);
		while (a--)
		{
			scanf ("%d", &b);
			M[i][b - 1] = 1;
		}
	}

	return 1;
}

int backtrack(int o)
{
	if (pd[o] >= 0) return pd[o];
	int v, max = 0;
	for (int i = 0; i < n; i++)
	{
		if (M[o][i])
		{
			v = backtrack(i);
			if (v > max) max = v;
		}
	}
	pd[o] = V[o] + max;
	return pd[o];
}

int go()
{
	int max = 0, v;
	for (int i = 0; i < n; i++)
	{
		v = backtrack(i);
		if (v > max) max = v;
	}
	return max;
}

int main(void)
{
	while (do_read())
	{
		printf ("%d\n", go());
	}
	return 0;
}

