#include <cstdio>

#define TAM 21

using namespace std;

int main(void)
{
	int B, N;
	int D, C, V;
	int R[TAM];
	int i;

	while (1) {
		scanf ("%d %d", &B, &N);
		if (!B && !N) break;
		for (i = 1; i <= B; i++) scanf ("%d", &R[i]);
		while (N--) {
			scanf ("%d %d %d", &D, &C, &V);
			R[D] -= V;
			R[C] += V;
		}

		for (i = 1; i <= B; i++)
			if (R[i] < 0) {
				printf ("N\n");
				break;
			}

		if (i > B) printf ("S\n");
	}

	return 0;
}

