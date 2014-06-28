#include <cstdio>
#include <map>
#include <cmath>

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

		map<int, long int> MAP;
		int m = (int)ceil(sqrt(1 << (N - 1)));
		int value = I;
		for (int j = 1; j < m; j++) {
			MAP[j] = value;
			value = next(value, mask, N);
		}
	}

	return 0;
}
