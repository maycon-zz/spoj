#include <cstdio>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

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

pair<Weight, Edges> minimumSpanningTree(const Graph &g, int r = 0) {
	int n = g.size();
	Edges T;
	Weight total = 0;

	vector<bool> visited(n);
	priority_queue<Edge> Q;
	Q.push( Edge(-1, r, 0) );
	
	while (!Q.empty())
	{
		Edge e = Q.top(); Q.pop();
		if (visited[e.dst]) continue;
		T.push_back(e);
		total += e.weight;
		visited[e.dst] = true;
		FOR(f, g[e.dst]) if (!visited[f->dst]) Q.push(*f);
	}
	
	return pair<Weight, Edges>(total, T);
}

bool compara(Edge a, Edge b)
{
	if (a.src != b.src) return a.src < b.src;
	return a.dst < b.dst;
}

int main(void)
{
	int v, a, t = 0;
	int src, dst, weight;
	
	while (1)
	{
		scanf ("%d %d", &v, &a);
		if (!v && !a) break;
		
		Graph g(v+1);
		while (a--)
		{
			scanf("%d %d %d", &src, &dst, &weight);
			g[src].push_back(Edge(src, dst, weight));
			g[dst].push_back(Edge(dst, src, weight));
		}
		
		pair<Weight, Edges> r = minimumSpanningTree(g, 1);
		Edges e = r.second;
		
		FOR(i, e)
		{
			if (i->src > i->dst)
			{
				int aux = i->src;
				i->src = i->dst;
				i->dst = aux;
			}
		}
		
		sort (e.begin(), e.end(), compara);
		
		printf ("Teste %d\n", ++t);
		for (int i = 1; i < e.size(); i++)
			printf ("%d %d\n", e[i].src, e[i].dst);
		printf ("\n");
	}
	
	return 0;
}
