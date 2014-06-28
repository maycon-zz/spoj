#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> Edges;
typedef map<int, Edges> Graph;

#define REP(i,a,b) for(int(i) = int(a); i < int(b); ++i)
#define EACH(it,x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define ALL(x) (x).begin(),(x).end()
#define EXIST(x,v) (find(ALL(v),(x))!=(v).end())

map<int, int> viz;

int cicle(Graph &g, int src) {
	queue<pii> Q;

	int prev = -1;
	Q.push(make_pair(src,0));
	while (!Q.empty()) {
		pii elem = Q.front();
		Q.pop();

		viz[elem.first] = 1;

		if ((elem.first == src) && (elem.second > 0)) {
			return elem.second;
		}

		EACH(it,g[elem.first]) {
			if (*it != prev) {
				Q.push(make_pair(*it, elem.second + 1));
				break;
			}
		}

		prev = elem.first;
	}

	return -1;
}

int main(void)
{
	int K, W, A, B;

	while (1) {
		scanf ("%d %d", &K, &W);
		if (!K && !W) break;

		Graph g;
		
		viz.clear();

		REP(i,0,W) {
			scanf ("%d %d", &A, &B);
			if (!EXIST(B, g[A])) {
				g[A].push_back(B);
				g[B].push_back(A);
			}
		}

		int fail = 0;

		EACH(it,g) {
			if (it->second.size() > 2) {
				fail = 1;
				printf ("N\n");
				break;
			}
		}

		if (fail) continue;

		EACH(it,g) {
			int v = it->first;

			if (!viz[v]) {
				int c = cicle(g, v);
				if (c != -1) {
					if (c != K) {
						printf ("N\n");
						fail = 1;
					}
					break;
				}
			}
		}

		if (!fail) printf ("Y\n");
	}

	return 0;
}

