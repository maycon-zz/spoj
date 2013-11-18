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

_inline(float cmp)(float x, float y = 0, float tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
	float x, y;
	point(float x = 0, float y = 0): x(x), y(y) {}
	point operator +(point q) { return point(x + q.x, y + q.y); }
	point operator -(point q) { return point(x - q.x, y - q.y); }
	point operator *(float t) { return point(x * t, y * t); }
	point operator /(float t) { return point(x / t, y / t); }
	float operator *(point q) { return x * q.x + y * q.y; }
	float operator %(point q) { return x * q.y - y * q.x; }

	float cmp(point q) const {
		if (float  t = ::cmp(x, q.x)) return t;
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

float abs(point p) { return hypot(p.x, p.y); }
float arg(point p) { return atan2(p.y, p.x); }

typedef pair<point, float> circle;

bool in_circle(circle C, point p){
	return cmp(abs(p - C.first), C.second) <= 0;
}

point circumcenter(point p, point q, point r) {
	point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
	return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}

circle spanning_circle(vector<point>& T) {
	int n = T.size();
	random_shuffle(all(T));
	circle C(point(), -INFINITY);
	for (int i = 0; i < n; i++) if (!in_circle(C, T[i])) {
		C = circle(T[i], 0);
		for (int j = 0; j < i; j++) if (!in_circle(C, T[j])) {
			C = circle((T[i] + T[j]) / 2, abs(T[i] - T[j]) / 2);
			for (int k = 0; k < j; k++) if (!in_circle(C, T[k])) {
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
	float x, y;
	int t = 0;
	int i, j, k, l, qt;
	float min;
	
	cout.precision(3);
	cout.setf(ios::fixed,ios::floatfield);
	
	while (1)
	{
		//cin >> n >> m;
		scanf ("%d %d", &n, &m);
		if (!n && !m) break;
		
		vector<point> p;
		circle C1, C2;
		
		cx = cy = 0;
		for (i = 0; i < n; i++)
		{
			//cin >> x >> y;
			scanf ("%f %f", &x, &y);
			cx += x; cy += y;
			p.push_back(point(x,y));
		}
		
		cx /= n;
		cy /= n;

		min = INF;
		for (i = 0; i < n-2; i++)
		{
			for (j = i+1; j < n-1; j++)
			{
				C1 = circle((p[i] + p[j]) / 2, abs(p[i] - p[j]) / 2);
				if (C1.second > min) continue;
				
				for (qt = 0, l = 0; (l < n) && (qt < m); l++) if (in_circle(C1, p[l])) qt++;
				if ((qt == m) && (C1.second < min)) min = C1.second;

				for (k = j+1; k < n; k++)  if (!in_circle(C1, p[k]))
				{
					point o = circumcenter(p[i], p[j], p[k]);
					C2 = circle(o, abs(o - p[k]));
					if (C2.second > min) continue;
					
					for (qt = 0, l = 0; (l < n) && (qt < m); l++) if (in_circle(C2, p[l])) qt++;
					if ((qt == m) && (C2.second < min)) min = C2.second;
				}
			}
		}
		
		cout << min << endl;
		
	}
	return 0;
}
