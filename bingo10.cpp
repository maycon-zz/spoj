#include <set>
#include <map>
#include <vector>
#include <cstdio>

#define ABS(x) ((x) < 0 ? -(x) : (x))

using namespace std;

int main(void)
{
	unsigned int N, B, b, val;

	while (1) {
		scanf ("%d %d", &N, &B);
		if (!N && !B) break;

		set<int> S;
		vector<int> V;

		for (unsigned int i = 0; i < B; ++i) {
			scanf ("%d", &b);
			V.push_back(b);
		}

		for (unsigned int i = 0; i < B-1; ++i)
			for (unsigned int j = i+1; j < B; ++j) {
				val = ABS(V[i] - V[j]);
				if (val <= N) S.insert(val);
			}

		printf (S.size() == N ? "Y\n" : "N\n");
	}

	return 0;
}

