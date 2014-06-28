#include <cstdio>	
#include <string>	
#include <cstring>
#include <vector>	
#include <algorithm>
#include <map>		
#include <utility>	
#include <cmath>
#include <queue>	
#include <stack>
#include <set>		
#include <deque>
#include <iostream>
#include <sstream>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) (int((x).size()))
const int INF = 0x3F3F3F3F;
const double PI = 2*acos(0);
const double EPS = 1e-10;

inline int cmp(double x, double y=0, double tol=EPS){
    return (x<=y+tol) ? (x+tol<y) ? -1 : 0 : 1;
}


typedef int Weight;

struct Edge {
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight) :
         src(src), dst(dst), weight(weight) { }
};

bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight :
           e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

pair<Weight, Edges> minimumSpanningForest(const Graph &g) {
    int n = g.size();
    UnionFind uf(n);
    priority_queue<Edge> Q[3];
    REP(u, n) EACH(e, g[u]) if (u < e->dst) Q[e->weight == 1235 ? 0 : (e->weight == 8977 ? 1 : 2)].push(*e);
    
    
    for (int i = 1; i <= 2; i++) EACH(e, Q[i]) Q[0].push(*e);

    Weight total = 0;
    Edges F;
    while (F.size() < n-1 && !Q.empty()) {
        Edge e = Q.top(); Q.pop();
        if (uf.unionSet(e.src, e.dst)) {
            F.push_back(e);
            total += e.weight;
        }
    }
    return pair<Weight, Edges>(total, F);
}

int main(){
    int n, m;
    int u, v, w;
    int instancia = 1;
    
    while (scanf("%d %d", &n, &m) != EOF) {
        Graph g(n+1);
        
        while (m--) {
            scanf ("%d %d %d", &u, &v, &w);
            g[u].push_back(Edge(u, v, w));
            g[v].push_back(Edge(v, u, w));
        }
        
        pair<Weight, Edges> mst = minimumSpanningForest (g);
        printf ("Instancia %d\n%d\n\n", instancia++, mst.first);
    }
       
    return 0;
}



