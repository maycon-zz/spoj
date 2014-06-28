#include <cstdio>

using namespace std;

int main(void)
{
	int t = 1, n, v, s;

	while (1)
	{
		scanf ("%d", &n);
		if (!n) break;
		s = 0;
		while (n--) { scanf ("%d", &v); s += v; }
		printf ("Teste %d\n%d\n\n", t++, s);
	}

	return 0;
}
