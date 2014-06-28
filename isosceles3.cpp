#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define EACH(it,x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)

int main(void)
{
	int N;

	while (scanf("%d", &N) && N) {
		vector<pair<long int, long int> > p;
		long long x, y;

		for (int i = 0; i < N; i++) {
			scanf ("%ld %ld", &x, &y);
			p.push_back(make_pair(x, y));
		}

		int qt = 0;

		for (int i = 0; i < N; i++) {
			vector<long long> d;
			map<long long, int> m;

			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				x = p[i].first  - p[j].first;
				y = p[i].second - p[j].second;
				if (x*x + y*y == 0) continue;
				m[x*x + y*y]++;
			}

			EACH(it,m) {
				qt += (it->second * (it->second - 1)/2);
			}
		}

		printf ("%ld\n", qt);

	}

	return 0;
}



