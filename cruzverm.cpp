/**
 * Problem: 3083. Produto da guerra (CRUZVERM)
 * Url: https://br.spoj.pl/problems/CRUZVERM/
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

int main(void)
{
	cout.precision(3);
	cout.setf(ios::fixed,ios::floatfield);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	int t, n;
	int u, v;
	
	cin >> t;
	while (t--)
	{
		cin >> n;
		
		cout << "n: " << n << endl;
		Graph g(n+1);
		
		REP(i,n-1)
		{
			cin >> u >> v;
			if (u > v) { int aux = u; u = v; v = aux; }
			g[u].push_back(Edge(u, v, 1));
			//g[v].push_back(Edge(v, u, 1));
		}
		
		int r = 0;
		REP(i, n-1)
		{
			cout << (i+1) << " -> " << g[(i+1)].size() << endl;
			//if (g[i].size() == 2) r++;
		}
				
		cout << "-------------" << endl;
	}
	
	return 0;
}
