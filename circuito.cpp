#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
	int P, N, C;
	int n;
	int sum[1001], read[1001], ans;

	while (1) {
		scanf ("%d %d %d", &P, &N, &C);
		if (!P && !N && !C) break;

		memset(sum, 0, sizeof(sum));
		memset(read, 0, sizeof(read));
		ans = 0;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < P; j++) {
				scanf ("%d", &n);
				if (n) {
					sum[j]++;
					if (sum[j] >= C && !read[j]) {
						ans++;
						read[j] = 1;
					}
				} else
					sum[j] = read[j] = 0;
			}
		}

		printf ("%d\n", ans);
	}

	return 0;
}

