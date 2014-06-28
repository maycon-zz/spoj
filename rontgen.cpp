#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int main(void)
{
	int T, K;
	char S[2000], tmp[100];;
	int v[10], len;

	scanf ("%d", &T);
	while (T--) {
		scanf ("%s %d ", S, &K);
		printf ("%s\n", S);
		K--;

		while (K--) {
			len = strlen(S);
			memset(v, 0, sizeof(v));

			memset(S, 0, sizeof(S));
			for (int i = 0; i < 10; ++i) {
				if (v[i] == 0) continue;
				sprintf(tmp, "%d%d", v[i], i);
				strcat(S, tmp);
			}

			printf ("%s\n", S);
		}


		printf ("\n");
	}

	return 0;
}

