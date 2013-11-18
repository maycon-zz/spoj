#include <cstdio>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

#define INF 0x3f3f3f3f

typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
		e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;


pair< vector<int>, Weight > maisLonge (Graph g, int src, vector<bool> &visited)
{
	Weight max_weight;
	pair< vector<int>, Weight > result;
	pair< vector<int>, Weight > recursion;
		
	result.second = 0;
	result.first.push_back(src);
	
	printf ("src = %d\n", src);
	FOR(it, g[src])
	{
		if (!visited[it->dst])
		{
			visited[it->dst] = true;
			recursion = maisLonge(g, it->dst, visited);
			visited[it->dst] = false;
			
			if (recursion.second > result.second)
			{
				printf ("-> %d\n", it->dst);
				result.first.pop_back();
				result.first.push_back(it->dst);
				result = recursion;
			}
		}
	}
	
	return result;
}

int main(void)
{
	int n;
	int src, dst;
	
	while(1)
	{
		scanf ("%d", &n);
		if (!n) break;
		
		Graph g(n+1);
		
		n--;
		while (n--)
		{
			scanf ("%d %d", &src, &dst);
			printf ("leu %d %d\n", src, dst);
			g[src].push_back(Edge(src, dst, 1));
			g[dst].push_back(Edge(dst, src, 1));
		}
		
		printf ("E la vamos nos!!\n");
		vector <bool> visited (n+1);

		pair< vector<int>, Weight > r = maisLonge (g, src, visited);
	}
	
	printf ("sai\n");
	return 0;
}
