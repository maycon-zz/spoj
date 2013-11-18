#define _GLIBCXX_DEBUG

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>

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

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-10;

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

double dist(point p1, point p2)
{
   return sqrt( (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) );
}

point b;

bool compara(point p1, point p2)
{
	//if (p1.x != p2.x) return p1.x < p2.x;
	//return p1.y < p2.y;
	return (dist(p1, b) < dist(p2, b));
}

circle spanning_circle(vector<point>& T, int ini, int fin) {
	//random_shuffle(all(T));
	circle C(point(), -INFINITY);
	for (int i = ini; i < fin; i++) if (!in_circle(C, T[i])) {
		C = circle(T[i], 0);
		for (int j = ini; j < i; j++) if (!in_circle(C, T[j])) {
			C = circle((T[i] + T[j]) / 2, abs(T[i] - T[j]) / 2);
			for (int k = ini; k < j; k++) if (!in_circle(C, T[k])) {
				point o = circumcenter(T[i], T[j], T[k]);
				C = circle(o, abs(o - T[k]));
			}
		}
	}
	return C;
}


int main(void)
{
	int n, m;
	double x, y;
	double cx, cy;
	int t = 0;
	int i, j, k, l, qt;
	double min;
	
	cout.precision(3);
	cout.setf(ios::fixed,ios::floatfield);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	
	while (1)
	{
		scanf ("%d %d", &n, &m);
		if (!n && !m) break;
		
		vector<point> p;
		circle C1, C2;
	
		for (i = 0; i < n; i++)
		{
			scanf ("%lf %lf", &x, &y);
			p.push_back(point(x,y));
		}
		
		sort(p.begin(), p.end());

		min = INF;
		for (i = 0; i < n-m; i++)
		{
			circle c = spanning_circle(p, 0, m);
			if (c.second < min)
				min = c.second;
		}
		cout << min << endl;		
	}

	return 0;
}
