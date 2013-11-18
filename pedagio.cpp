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

void shortestPath(const Graph &g, int s,
	vector<Weight> &dist, vector<int> &prev, int max) {
	int n = g.size();
	
	dist.assign(n, INF); dist[s] = 0;
	prev.assign(n, -1);
	priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"
	
	for (Q.push(Edge(-2, s, 0)); !Q.empty(); ) {
		Edge e = Q.top(); Q.pop();
		if (prev[e.dst] != -1) continue;
			prev[e.dst] = e.src;
			FOR(f,g[e.dst]) {
			Weight accum = e.weight+f->weight;
			if ((dist[f->dst] > accum) && (accum <= max)){
				dist[f->dst] = accum;
				Q.push(Edge(f->src, f->dst, accum));
			}
		}
	}
}

int main(void)
{
	int c, e, l, p, t = 0;
	int src, dst;
	
	while(1)
	{
		scanf ("%d %d %d %d", &c, &e, &l, &p);
		if (!c) break;
		
		Graph g(c+1);
		
		while (e--)
		{
			scanf ("%d %d", &src, &dst);
			g[src].push_back(Edge(src, dst, 1));
			g[dst].push_back(Edge(dst, src, 1));
		}
		
		vector<Weight> dist;
		vector<int> prev;
		
		shortestPath(g, l, dist, prev, p);
		
		printf ("Teste %d\n", ++t);
		for (int i = 1; i < dist.size(); i++)
			if ((dist[i] <= p) && (i != l)) printf ("%d ", i);
		printf ("\n\n");
		
	}
	
	return 0;
}
