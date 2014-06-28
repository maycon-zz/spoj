#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef vector < vector <int> > Graph;

int main(void)
{
	int N, M;
	int V, W, P;

	while (1) {
inicio:
		scanf ("%d", &N);
		if (!N) break;

		scanf("%d", &M);

		Graph g1(N+1);
		Graph g2(N+1);

		for (int i = 0; i < M; i++) {
			scanf ("%d %d %d", &V, &W, &P);
			g1[V].push_back(W);
			g2[W].push_back(V);

			if (P == 2) {
				g1[W].push_back(V);
				g2[V].push_back(W);
			}
		}

		int visited[N+1];
		queue<int> Q;

		memset(visited, 0, sizeof(visited));
		Q.push(1);
		while (!Q.empty()) {
			int e = Q.front();
			Q.pop();
			printf ("Trata %d\n", e);
			if (!visited[e]) {
				visited[e]++;
				for (int i = 0; i < g1[e].size(); i++)
					Q.push(g1[e][i]);
			}
		}
		for (int i = 1; i <= N; i++)
			if (visited[i] == 0) {
				printf ("indo %d = 0\n", i);
				goto inicio;
			}

		memset(visited, 0, sizeof(visited));
		Q.push(1);
		visited[1] = 1;
		while (!Q.empty()) {
			int e = Q.front();
			Q.pop();
			if (!visited[e]) {
				visited[e]++;
				for (int i = 0; i < g2[e].size(); i++)
					Q.push(g2[e][i]);
			}
		}
		for (int i = 1; i <= N; i++)
			if (visited[i] == 0) {
				printf ("0\n");
				goto inicio;
			}


		printf ("1\n");
	}

	return 0;
}

