/**
 * Problema: Spoj-BR CUBO ( https://br.spoj.pl/problems/CUBO/ )
 * Author: Maycon Maia Vitali ( maycon at hacknroll dot com )
 * Date: 2011-07-23
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

#define REP(i,a,b) for(int(i) = int(a); i < int(b); ++i)
#define TYPE(x) __typeof(x)
#define EACH(it,x) for (TYPE((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define MP(a,b) make_pair(a,b)

const int MAX_SIZE = 21;
const int INF = 0x3f3f3f3f;

typedef pair<int,int> pii;

typedef struct State {
	State(pii S, pii B, int moves, int jerks):
		S(S), B(B), moves(moves), jerks(jerks) {}

	pii S, B;
	int moves, jerks;
} State;


int main(void)
{
	char map[MAX_SIZE][MAX_SIZE];
	int map_min[MAX_SIZE][MAX_SIZE][2]; // 0 -> moves, 1 -> jerks
	
	int r, c, len, t = 0;
	pii T, B, S;

	int dl[] = {-1, 0, 0, 1};
	int dc[] = {0, 1, -1, 0};

	while (1) {
		scanf ("%d %d", &r, &c);
		if (!r && !c) break;

		memset(map_min, 0x3f, sizeof(map_min));

		REP(i,0,r) {
			scanf ("%s", map[i]);
			len = strlen(map[i]);
			REP(j,0,len) {
				switch(map[i][j]) {
					case 'S': S = MP(i,j); break;
					case 'B': B = MP(i,j); break;
					case 'T': T = MP(i,j); break;
				}
			}
		}

		int min_moves = INF;
		int min_jerks = INF;

		queue<State> Q;
		Q.push(State(S, B, 0, 0));
	
		while (!Q.empty()) {
			State &state = Q.front();
			Q.pop();
			printf ("(%d %d) (%d %d) %d %d\n", state.S.first, state.S.second,
					state.B.first, state.B.second, state.moves, state.jerks);

			if (map_min[state.B.first][state.B.second][1] < state.jerks) 
				continue;

//#if 0
			printf ("%d == %d | %d < %d\n",
					map_min[state.B.first][state.B.second][1], state.jerks,
					map_min[state.B.first][state.B.second][0], state.moves);
//#endif
			if (map_min[state.B.first][state.B.second][1] == state.jerks)
				if (map_min[state.B.first][state.B.second][0] < state.moves)
					continue;


			map_min[state.B.first][state.B.second][0] = state.moves;
			map_min[state.B.first][state.B.second][1] = state.jerks;

			REP(i,0,4) {
				int nl = state.S.first + dl[i];
				int nc = state.S.second + dc[i];
				int nl2 = state.S.first + 2*dl[i];
				int nc2 = state.S.second + 2*dc[i];


				if ((nl < 0) || (nc < 0) || (nl >= r) || (nc >= c)) continue;
				if (map[nl][nc] == '#') continue;

				printf ("    (%d %d)[%c] (%d %d)[%c]\n", nl, nc, map[nl][nc], nl2, nc2, map[nl2][nc2]);

				if (nl == state.B.first && nc == state.B.second) {
					if ((nl2 < 0) || (nc2 < 0) || (nl2 >= r) || (nc2 >= c)) continue;
					if (map[nl2][nc2] == '#') continue;
					Q.push(State(MP(nl,nc), MP(nl2,nc2), state.moves + 1, state.jerks + 1));
				}
				else {
					Q.push(State(MP(nl,nc), state.B, state.moves + 1, state.jerks));
				}
			}
		}

		if (map_min[T.first][T.second][0] == INF)
			printf ("Instancia %d\nImpossivel\n\n", ++t);
		else 
			printf ("Instancia %d\n%d %d\n\n", ++t, map_min[T.first][T.second][0], map_min[T.first][T.second][1]);
	}

	return 0;
}

