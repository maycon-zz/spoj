#include <cstdio>
#include <map>

using namespace std;

inline long int next(long int v, int t, int qt_bits)
{
	int bit = (__builtin_popcount(v & t) % 2);
	return ((bit << (qt_bits - 1)) | (v >> 1)) & ((1 << qt_bits) - 1);
}

int main(void)
{
	int N, T, I, F, mask;
	int bit;

	while (1)
	{
		scanf ("%d %d", &N, &T);
		if (!T && !N) break;
		
		mask = 0;
		for (int i = 0; i < T; i++)
		{
			scanf ("%d", &bit);
			mask |= (1 << bit);
		}

		scanf ("%x %x", &I, &F);

		register long int state1 = I;
		register long int state2 = next(state1, mask, N);
		register long int state3 = next(state2, mask, N);
		register long int trans = 0;
		while ((state1 != state2) && (state1 != state3) && 
				(state1 != F) && (state2 != F) && (state3 != F))
		{
			state1 = next(state1, mask, N);
			state2 = next(state3, mask, N); //next(next(state2, mask, N), mask, N);
			state3 = next(state2, mask, N);

			trans++;
		}

		if (state1 == F) printf ("%ld\n", trans);
		else if (state2 == F) printf ("%ld\n", 1 + 2*trans);
		else if (state3 == F) printf ("%ld\n", 2 + 2*trans);
		else printf ("*\n");
	}

	return 0;
}

