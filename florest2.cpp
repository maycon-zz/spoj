#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void)
{
	int n = 0, lim, r, v;

	scanf ("%d", &n);
	lim = (int)sqrt(n);

	r = 0;
	for (int x = 2; x <= lim; x++) {
		if ((v = (-x + 1 - n) % (1 - 2*x)) == 0)
			r += (x <= v);
		//((-x + 1 - n) % (1 - 2*x) == 0);
		//double v = (double)(-x + 1 - n)/(1 - 2*x);
		//if ((floor(v) == ceil(v)) && (x <= v)) r++;
	}

	printf ("%d\n", r/2);

	return 0;
}

