#include <cstdio>
#include <cstdlib>

int main(void) {
	int A;
	scanf ("%d", &A);
	printf ("%d\n", A - ((A - 1986) % 76) + 76);
	return 0;
}

