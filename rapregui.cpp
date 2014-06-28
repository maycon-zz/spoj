#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

#define MAX_Q 8

using namespace std;

int main(void)
{
	int dl[] = {1,  0, 0, -1, /**/ -1, 1,  1, -1, /**/ 2, 0,  0, -2, /**/ -2, 2, -2,  2,  1, 1, -1, -1, /**/ -2, -2,  2, 2};
	int dc[] = {0, -1, 1,  0, /**/ -1, 1, -1,  1, /**/ 0, 2, -2,  0, /**/  1, 1, -1, -1, -2, 2, -2,  2, /**/ -2,  2, -2, 2};
	int de[] = {2,  2, 2,  2, /**/  3, 3,  3,  3, /**/ 5, 5,  5,  5, /**/  6, 6,  6,  6,  6, 6,  6,  6, /**/  7,  7,  7, 7};

	char block[1001][1001], viz[1001][1001];
	int c, r, c1, c2, r1, r2, w;

	while (1) {
		scanf ("%d %d", &c, &r);
		if (!c && !r) break;

		memset(block, 0, sizeof(block));
		memset(viz, 0, sizeof(viz));

		scanf ("%d %d %d %d ", &c1, &r1, &c2, &r2);
		pair<int, int> src(r1,c1);
		pair<int, int> dst(r2,c2);
		
		scanf ("%d", &w);
		while (w--) {
			scanf ("%d %d %d %d ", &c1, &r1, &c2, &r2);
			for (int i = r1; i <= r2; i++)
				for (int j = c1; j <= c2; j++)
					block[i][j] = 1;
		}

#if 0
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++)
				printf ("%d ", block[i][j]);
			printf ("\n");
		}
		printf ("\n");
#endif


		queue<pair<int, pair<int, int> > > Qv[MAX_Q];

		viz[src.first][src.second] = 1;
		Qv[0].push(make_pair(0, src));

		int q = 0, old_q = -1, done = 0;
		while(q != old_q) {
			queue<pair<int, pair<int, int> > > &Q = Qv[q];

			q = (q + 1) % MAX_Q;
			if (Q.empty()) continue;
			old_q = q;

			while (!Q.empty()) {
				pair<int, pair<int, int> > elem = Q.front();

				//printf ("(%d, %d) = %d\n", elem.second.first, elem.second.second, -elem.first);			
				if (elem.second == dst) {
					printf ("%d\n", -elem.first);
					done = 1;
					break;
				}
				
				viz[elem.second.first][elem.second.second] = 1;

				Q.pop();

				for (int i = 0; i < 24; i++) {
					int nl = elem.second.first + dl[i];
					int nc = elem.second.second + dc[i];
					int ne = -elem.first + de[i];

					/* limites */
					//printf ("  %-2d (%d, %d) = %d [%d]\n", i, nl, nc, ne, block[nl][nc]);
					if (nl < 1 || nc < 1 || nl > r || nc > c) continue;
					if (block[nl][nc] || viz[nl][nc]) continue;

					printf ("    %-2d [[%d]] (%d, %d) = %d (%d + %d [%d][%d]\n", i, nc % MAX_Q, nl, nc, ne, -elem.first, de[i], dl[i], dc[i]);
					Qv[nc % MAX_Q].push(make_pair(-ne, make_pair(nl, nc)));
				}
			}
			if (done)  break;
		}

		if (q == old_q) printf ("impossible\n");
	}

	return 0;
}

