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

int main(void)
{
	int K, W, A, B;

	while (1) {
		scanf ("%d %d", &K, &W);
		if (!K && !W) break;

		Graph g;
		
		REP(i,0,W) {
			scanf ("%d %d", &A, &B);
			if (!EXIST(B, g[A])) {
				g[A].push_back(B);
				g[B].push_back(A);
			}
		}

		int fail = 0;
		EACH(it,g) {
			if (it->second.size() < 2) {
				printf ("N\n");
				fail = 1;
				break;
			}
		}

		if (!fail) printf ("S\n");
	}

	return 0;
}

