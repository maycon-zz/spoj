#include <cstdio>
#include <cstring>
#include <cmath>

#define TAM 32000

using namespace std;

char primes[TAM];

void make_sieve()
{
	memset(primes, 0, sizeof(primes));
	primes[1] = 1;
	for (int i = 2; i < TAM; i++)
		if (primes[i] == 0)
			for (int j = i*2; j < TAM; j += i) primes[j] = 1;
}

int main(void)
{
	int t, i, f;
	int range[100001];

	make_sieve();

	scanf ("%d", &t);
	while (--t) {
		scanf ("%d %d", i, f);
		memset(range, 0, sizeof(range));
	}
	return 1;
}

