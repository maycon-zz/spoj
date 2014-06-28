#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 1001

int main(void)
{
	int N;

	while (scanf("%d", &N) && N) {
		long long p[MAX][2];
		long long x, y;

		for (int i = 0; i < N; i++) {
			scanf ("%ld %ld", &p[i][0], &p[i][1]);
		}

		int qt = 0;

		for (int i = 0; i < N; i++) {
			long long d[MAX];
			int pos = 0;

			for (int j = 0; j < N; j++) {
				x = p[i][0]  - p[j][0];
				y = p[i][1] - p[j][1];
				if (x*x + y*y) d[pos++] = x*x + y*y;
			}

			sort(&d[0], &d[pos]);
			for (int j = 0; j < pos; j++) printf ("%ld ", d[j]);
			printf ("\n");
			int n = 1;
			for (int j = 1; j < pos; j++) {
				if (d[j] != d[j-1]) {
					qt += (n * (n - 1)/2);
					n = 1;
				} else n++;
			}
			qt += (n * (n - 1)/2);
		}

		printf ("%ld\n", qt);

	}

	return 0;
}



