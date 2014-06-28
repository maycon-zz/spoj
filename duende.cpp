#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define REP(i,a,b) for(int i = int(a); i < int(b); ++i)
#define MP make_pair
#define MAX 10

typedef pair<int,int> pii;

int main(void)
{
	int N, M;
	int map[MAX][MAX], viz[MAX][MAX];
	pii src;

	int dl[] = {0, 0, -1, 1};
	int dc[] = {-1, 1, 0, 0};

	scanf ("%d %d ", &N, &M);
	REP(i,0,N) REP(j,0,M) {
		scanf("%d ", &map[i][j]);
		if (map[i][j] == 3) src = MP(i,j);
	}

	queue<pair<int, pii> > Q;
	Q.push(MP(0, src));
	while (!Q.empty()) {
		pair<int, pii> &elem = Q.front();
		Q.pop();

		if (map[elem.second.first][elem.second.second] == 0) {
			printf ("%d\n", elem.first);
			break;
		}

		viz[elem.second.first][elem.second.second] = 1;

		REP(i,0,4) {
			int nl = elem.second.first + dl[i];
			int nc = elem.second.second + dc[i];
			int nd = elem.first + 1;

			if (nl < 0 || nc < 0 || nl >= N || nc >= M) continue;
			if (viz[nl][nc] || map[nl][nc]) continue;
			Q.push(MP(nd, MP(nl, nc)));
		}
	}

	return 0;
}

