#include <iostream>
#include <cstdio>
#include <cstring>

#define MAX 10004

using namespace std;

int main(void)
{
	char c[MAX], v[MAX];
	int n, i;

	while (1)
	{
		scanf ("%d", &n);
		if (!n) break;

		scanf ("%s", c);

		memset(v, 3, MAX);
		for (i = 0; i < n; i++)
		{
			if (c[i] == 'X')
			{
				if (v[i-1+2] > 0) v[i-1+2]--;
				if (v[i-2+2] > 0) v[i-2+2]--;
				if (v[i+1+2] > 0) v[i+1+2]--;
				if (v[i+2+2] > 0) v[i+2+2]--;
				v[i+2] = 0;
			}
		}

		int soma = 0;
		for (i = 2; i < (n+2); i++)
		{
			printf ("%d ", v[i]);
			soma += v[i];
		}
		printf ("(%d)\n", soma);

	}
	return 0;
}

