#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

#define TAM 301

using namespace std;

typedef vector< vector<int> > Graph;

int C, V, X, Y;
int visited[TAM], pass[TAM];

pair<bool, int> do_the_fest(Graph &g, int s)
{
	int r = 0;
	if (visited[s]) return make_pair(false, 0);
	visited[s] = 1;

	for (int i = 0; i < g[s].size(); i++) {
		pair <bool, int> tmp = do_the_fest(g, g[s][i]);
		if (tmp.first)
			r += 2 + tmp.second;
	}

	return make_pair(pass[s] || r > 0, r);
}

int main(void)
{
	int t = 0;

	while (1)
	{
		scanf ("%d %d", &C, &V);
		if (!C && !V) break;

		Graph g(C+1);
		for (int i = 0; i < C-1; i++) {
			scanf ("%d %d", &X, &Y);
			g[X].push_back(Y);
			g[Y].push_back(X);
		}

		memset(pass, 0, sizeof(pass));
		for (int i = 0; i < V; i++) {
			scanf ("%d", &X);
			pass[X] = 1;
		}

		memset(visited, 0, sizeof(visited));
		pair<bool, int> r = do_the_fest(g, 1);

		printf ("Teste %d\n%d\n\n", ++t, r.second);
	}

	return 0;
}

