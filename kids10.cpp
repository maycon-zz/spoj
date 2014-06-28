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

map<int, int> viz;

int cicle(Graph &g, int src) {
	queue<pii> Q;
	Q.push(make_pair(src,0));
	while (!Q.empty()) {
		pii elem = Q.front();
		Q.pop();
		if ((elem.first == src) && (elem.second > 0)) {
			if (elem.second > 2) return elem.second;
			continue;
		}
		if (viz[elem.first]) continue;
		viz[elem.first] = 1;
		EACH(it,g[elem.first]) Q.push(make_pair(*it, elem.second + 1));
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
			g[A].push_back(B);
			g[B].push_back(A);
		}

		int fail = 0;
		EACH(it,g) {
			sort(ALL(it->second));
			it->second.erase(unique(ALL(it->second)), it->second.end());

			if (it->second.size() > 2) {
				fail = 1;
				break;
			}
		}

		if (fail) {
			printf ("N1\n");
			break;
		}

		EACH(it,g) {
			int v = it->first;
			
			if (!viz[v]) {
				int c = cicle(g, v);
				printf ("-> %d %d %d\n", v, c, K);
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

