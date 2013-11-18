/**
 * Problem: UVa 247 - Calling Circles
 * Url: http://uva.onlinejudge.org/external/2/247.html
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
	
	
}
