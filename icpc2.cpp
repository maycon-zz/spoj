#include <cstdlib>
#include <cstring>
#include <cmath>
//#include <cinttypes>
//#include <ctype>

#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>

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

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;

_inline(int cmp)(double x, double y = 0, double tol = EPS) {
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

	int cmp(point q) const {
		if (int t = ::cmp(x, q.x)) return t;
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

double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }

typedef pair<point, double> circle;

bool in_circle(circle C, point p){
	return cmp(abs(p - C.first), C.second) <= 0;
}

point circumcenter(point p, point q, point r) {
	point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
	return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}

circle spanning_circle_n(vector<point>& P, vector<point>& R)
{
	int np = P.size(), nr = R.size();
	circle C;
	
	if ( (np == 0) || (nr == 3) )
	{
		if (nr == 1)
		{
			C.first = R[0];
			C.second = 0;
		}
		else if (nr == 2)
		{
			C.first = (R[0] + R[1]) / 2;
			C.second = abs(R[0] - R[1]) / 2;
		}
		else if (nr == 3)
		{
			double x1 = R[0].x, y1 = R[0].y;
			double x2 = R[1].x, y2 = R[1].y;
			double x3 = R[2].x, y3 = R[2].y;

			double ma = (y2 - y1) / (x2 - x1);
			double mb = (y3 - y2) / (x3 - x2);
			
			double cx = (ma * mb * (y1 - y3) + mb * (x1 + x2) - ma * (x2 + x3)) / (2 * (mb - ma));
			double cy = (-1 / ma) * (cx - (x1 + x2) / 2) + (y1 + y2) / 2;
			
			C.first = point(cx, cy);
			C.second = abs(C.first - R[2]);
		}
	}
	else
	{
		point p = P.back();
		P.pop_back();
		C = spanning_circle_n(P, R);
		
		if (!in_circle(C, p))
		{
			R.push_back(p);
			C = spanning_circle_n(P, R);
			R.pop_back();
		}
		
		P.push_back(p);
	}
	
	return C;
}


int main(void)
{
	int n;
	double x, y;
	int t = 0;
	
	while (1)
	{
		scanf ("%d", &n);
		if (!n) break;
		
		vector<point> p, r;
		
		for (int i = 0; i < n; i++)
		{
			scanf ("%lf %lf", &x, &y);
			p.push_back(point(x,y));
		}

		circle c = spanning_circle_n(p, r);
		printf ("Instancia %d\n%.02f %.02f %.02f\n\n", ++t, c.first.x, c.first.y, c.second);		
	}
	return 0;
}
