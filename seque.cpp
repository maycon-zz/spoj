#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define EACH(x,it) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define ALL(x) (x).begin(), (x).end()

#define MAXN 600

using namespace std;

typedef struct Tupla {
	int i, j, h, v;

	Tupla(int i, int j, int h, int v) :
		i(i), j(j), h(h), v(v)  {}

	bool operator<(const Tupla &t) const {
		return (h * v) > (t.h * t.v);
	}

} Tupla;

int main(void)
{
	int M[MAXN][MAXN], pd[MAXN][MAXN][2];
	int n, m, i, j, r;

	while (1) {
		scanf ("%d %d", &n, &m);
		vector<Tupla> T;

		if (!n && !m) break;

		r = -1;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf ("%d", &M[i][j]);
				
				pd[i][j][0] = (i == 0 ? 1 : (M[i-1][j] < M[i][j] ? pd[i-1][j][0] + 1 : 1));
				pd[i][j][1] = (j == 0 ? 1 : (M[i][j-1] < M[i][j] ? pd[i][j-1][1] + 1 : 1));

				if (pd[i][j][0] > r) r = pd[i][j][0];
				if (pd[i][j][1] > r) r = pd[i][j][1];

				T.push_back(Tupla(i, j, pd[i][j][0], pd[i][j][1])); 
			}
		}

		sort(ALL(T));

		vector<pair<int, int> > bl;

		EACH(T, it) {
			if (it->v * it->h < r) break;
			EACH(bl, it2) {
				if ((it2->first >= (it->i + it->v + 1)) &&
							(it2->first <= it->i) && 
								(it2->second >= (it->j + it->h + 1)) &&
							 		(it2->second <= it->j)) {
					break;
				}

			}

			int ant = -1, err = 0;
			for (i = it->i - it->v + 1; i <= it->i; i++) {
				for (j = it->j - it->h + 1; j <= it->j; j++) {
					if (M[i][j] <= ant) {
						err = 1;
						bl.push_back(make_pair(i, j));
						break;
					}
					ant = M[i][j];
				}
				if (err) break;
			}
			if (!err) {
				if (it->v * it->h > r) r = it->v * it->h;
				break;
			}
		}

		printf ("%d\n", r);
	}

	return 0;

}
