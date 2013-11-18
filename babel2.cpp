/**
 * Problem: 3238 - Babel
 * Url: http://br.spoj.pl/problems/BABEL/
 *
 * Author: Maycon Maia Vitali
 * Contact: maycon.ppgi.ufes at gmail dot com
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>

#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>


using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

#define INF 0x3f3f3f3f

typedef int Weight;

struct Edge {
    int src, dst;
    Weight weight;
	string word;
    Edge(int src, int dst, Weight weight) :
        src(src), dst(dst), weight(weight), word("") { }

    Edge(int src, int dst, Weight weight, string word) :
        src(src), dst(dst), weight(weight), word(word) { }
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
        vector<Weight> &dist, vector<int> &prev) {

    int n = g.size();
    dist.assign(n, INF); dist[s] = 0;
    prev.assign(n, -1);
    priority_queue<Edge> Q; // "e < f" <=> "e.weight > f.weight"

    for (Q.push(Edge(-2, s, 0)); !Q.empty(); )
    {
        Edge e = Q.top(); Q.pop();
        if (prev[e.dst] != -1) continue;
        prev[e.dst] = e.src;

        FOR(f,g[e.dst]) {
            if ((dist[f->dst] > e.weight+f->weight) && (e.word != (*f).word)) {
                dist[f->dst] = e.weight+f->weight;
                Q.push(Edge(f->src, f->dst, e.weight+f->weight, (*f).word));
            }
        }
    }
}

int getid(map<string, int> &m1, string &s)
{
	int &r = m1[s];
	if (r == 0)	r = m1.size();
	return r - 1;
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);	

	int n;
	string nome1, nome2, nome3;
	int src, dst, id_src, id_dst;

	while (1)
	{
		cin >> n;
		if (!n) break;		
		
		Graph graph(n*2 + 3);
		map<string, int> nomes;
		map<int, string> palavras;
		vector<Weight> dist;
		vector<int> prev;

		cin >> nome1 >> nome2;
		
		src = getid(nomes, nome1);
		dst = getid(nomes, nome2);
		
		while (n--)
		{
			cin >> nome1 >> nome2 >> nome3;
			id_src = getid(nomes, nome1);
			id_dst = getid(nomes, nome2);
			
			int weight = nome3.size();
			graph[id_src].push_back(Edge(id_src, id_dst, weight, nome3));
			graph[id_dst].push_back(Edge(id_dst, id_src, weight, nome3));			
		}

		
		shortestPath(graph, src, dist, prev);
		
		if (dist[dst] == INF)
			cout << "impossivel" << endl;
		else
			cout << dist[dst] << endl;
	}
	
	return 0;
}
