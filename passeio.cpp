#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAXN 151

using namespace std;

typedef vector<int> Edge;
typedef vector<Edge> Graph;

int visited[MAXN];
int dist[MAXN];

int bfs(Graph &g, int orig)
{
	queue< pair<int, int> > Q;

	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));

	Q.push(make_pair(orig, 0));
	visited[orig] = 1;

	int result = 0;

	while (!Q.empty())
	{
		pair<int, int> &item = Q.front();
		Q.pop();
		int len = g[item.first].size();
		printf ("%d -> %d\n", item.first, item.second);
		result = max(result, item.second);

		for (int i = 0; i < len; i++)
		{
			int dst = g[item.first][i];

			if (!visited[dst] && (item.second+1 > dist[dst]))
			{
				printf ("dst = %d\n", dst);
				dist[dst] = item.second+1;
				Q.push(make_pair(dst, dist[dst]));
				visited[dst] = 1;
			}
		}
	}

	return result;
}

int main(void)
{
	int P, L, I;
	int alt[MAXN];
	int orig, dest;
	int teste = 0;

	while (1)
	{
		scanf ("%d %d %d", &P, &L, &I);
		if (!P && !L && !I) break;

		for (int i = 1; i <= P; i++)
			scanf("%d", &alt[i]);

		Graph g(P+1);

		for (int i = 0; i < L; i++)
		{
			scanf ("%d %d", &orig, &dest);
			if (alt[orig] > alt[dest])
			{
				g[orig].push_back(dest);
			}
		}

		for (int i = 1; i < g.size(); i++)
		{
			printf ("%d -> ", i);
			for (int j = 0; j < g[i].size(); j++)
				printf ("%d ", g[i][j]);
			printf ("\n");
		}
		printf ("\n");

		printf ("Teste %d\n%d\n\n", ++teste, bfs(g, I));


	}

	return 0;
}

