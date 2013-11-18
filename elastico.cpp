#define _GLIBCXX_DEBUG

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#include <complex>

#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")
#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i = (c).begin(); i != (c).end(); ++i)

const double EPS = 1e-8;
const double INF = 1e12;


_inline(double cmp)(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}
	point operator +(point q) { return point(x + q.x, y + q.y); }
	point operator -(point q) { return point(x - q.x, y - q.y); }
	point operator *(double t) { return point(x * t, y * t); }
	point operator /(double t) { return point(x / t, y / t); }
	double operator *(point q) { return x * q.x + y * q.y; }
	double operator %(point q) { return x * q.y - y * q.x; }

	double cmp(point q) const {
		if (double  t = ::cmp(x, q.x)) return t;
		return ::cmp(y, q.y);
	}

	bool operator ==(point q) const { return cmp(q) == 0; }
	bool operator !=(point q) const { return cmp(q) != 0; }
	bool operator < (point q) const { return cmp(q) < 0; }

	friend ostream& operator <<(ostream& o, point p) {
		return o << "(" << p.x << ", " << p.y << ")";
	}
	static point pivot;
};

point point::pivot;

bool radial_lt(point p, point q) {
	point P = p - point::pivot, Q = q - point::pivot;
	double R = P % Q;
	if (cmp(R)) return R > 0;
	return cmp(P * P, Q * Q) < 0;
}

_inline(double ccw)(point p, point q, point r)
{
	return cmp((p - r) % (q - r));
}

typedef vector<point> polygon;

polygon convex_hull(vector<point>& T)
{
	int j = 0, k, n = T.size(); polygon U(n);
	
	for (k = n-2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k--);

	reverse((k+1) + all(T));
	for (int i = 0; i < n; i++) {
		// troque o >= por > para manter pontos colineares
		while (j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0) j--;
		U[j++] = T[i];
	}

	U.erase(j + all(U));
	return U;
}

int main(void)
{
	int n;
	
	while(1)
	{
		scanf ("%d", &n);
		if (!n) break;
		
		vector<point> P;
		double x, y;
		
		P.push_back(point(0, 0));
		while (n--)
		{
			scanf ("%lf %lf", &x, &y);
			P.push_back(point(x, y));
		}
		
		point::pivot = point(0,0);
		sort(all(P), radial_lt);

		
		int len, max = 0;
		
		do
		{	
			polygon R = convex_hull(P);
			len = R.size();
			if (len > max) max = len;

			point::pivot = point(0,0);
			sort(all(R), radial_lt);
			
			point nearest = R[len - 1];
			printf ("Remove (%.0lf %.0lf)\n", nearest.x, nearest.y);
			
			FOR(i,P)
			{
				if ((*i) == nearest)
				{
					
					P.erase(i);
					break;
				}
			}
		}
		while (len > 1);
					
		printf ("%d\n\n\n", max);
	}
	
	return 0;
}
