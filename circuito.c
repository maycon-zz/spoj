#include <stdio.h>
#include <string.h>

int main(void)
{
	int P, N, C;
	int n, i, j;
	int sum[1001], read[1001], ans;

	while (1) {
		scanf ("%d %d %d", &P, &N, &C);
		if (!P && !N && !C) break;

		memset(sum, 0, P * sizeof(int));
		memset(read, 0, P * sizeof(int));
		ans = 0;

		for (i = 0; i < N; ++i) {
			for (j = 0; j < P; j++) {
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

