#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <list>
#include <cstring>
#include <stack>

#define MAXN 101
#define INF 0x3f3f3f3f

using namespace std;

typedef int Weight;
typedef pair<int, Weight> Edge;
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int dfs(Graph &g, int o)
{
	stack<Edge> Q;
	int visited[MAXN][MAXN];
	int result = INF;

	memset(visited, 0, sizeof(visited));

	Q.push(make_pair(o, 0));

	while (!Q.empty())
	{
		Edge &e = Q.top();
		Q.pop();

		printf (">> %d <<\n", e.first);

		//if ((e.first == o) && (e.second != 0))
		//	return e.second;

		int len = g[e.first].size();
		for (int i = 0; i < len; i++)
		{
			Edge &e2 = g[e.first][i];

			if (visited[e.first][e2.first]) continue;
			visited[e.first][e2.first] = 1;
			//visited[e2.first][e.first] = 1;
			printf ("%d -> %d\n", e.first, e2.first);

			if (e2.first == o)
				result = min(result, e.second + e2.second);
				//return e.second + e2.second;

			Q.push(make_pair(e2.first, e.second + e2.second));
		}
	}

	return result;
}

int main(void)
{
	int T, N, M;
	int u, v, c;

	scanf ("%d", &T);
	while (T--)
	{
		scanf ("%d %d", &N, &M);
		Graph g(N+1);
		while (M--)
		{
			scanf ("%d %d %d", &u, &v, &c);
			g[u].push_back(make_pair(v, c));
			g[v].push_back(make_pair(u, c));
		}

		int result = INF;
	   	for (int i = 1; i <= N; i++)
		{
			int v = dfs(g, i);
			if (v > 0)
				result = min(result, v);
			printf ("\n");
		}

		printf ("%d\n", result);
	}

	return 0;
}


