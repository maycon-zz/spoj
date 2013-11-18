#include <cstdlib>
#include <cstring>
#include <cmath>
//#include <cinttypes>
//#include <ctype>

#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i = (c).begin(); i != (c).end(); ++i)

#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define MIN(a,b) ((a) < (b) ? (a) : (b))

const int INF = 0x3F3F3F3F;
const int NULO = -1;

int main(void)
{
	int n;
	int prim_x, prim_y;
	int ult_x, ult_y;
	int x, y;
	
	while(1)
	{
		scanf ("%d", &n);
		if (!n) break;

		map<int, int> juizes_x;
		map<int, int> juizes_y;
		
		n--;
		scanf ("%d %d", &prim_x, &prim_y);
		ult_x = prim_x;
		ult_y = prim_y;
		while(n--)
		{
			scanf ("%d %d", &x, &y);
			if ((ult_x == x) && (!juizes_y[y]))
			{
				juizes_x[x] = 1;
			}
			else if ((ult_y == y) && (!juizes_x[x]))
			{
				juizes_y[y] = 1;
			}
			ult_x = x;
			ult_y = y;
		}
		
		if (prim_x == x) juizes_x[x] = 1;
		else if (prim_y == y) juizes_y[y] = 1;
		
		int i, r = 0;
		FOR(i,juizes_x) r += i->second;
		FOR(i,juizes_y) r += i->second;
		
		printf ("%d\n", r);

	}
	
	return 0;
}
