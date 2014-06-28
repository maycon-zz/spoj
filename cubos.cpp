#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <list>
#include <cstring>

using namespace std;

#define REP(i,a,b) for(int i = int(a); i < int(b); ++i)
#define IT(x) __typeof((x).begin())
#define EACH(it,v) for(IT(v) it = (v).begin(); it != (v).end(); ++it)

struct dice {
	int f, t, b, c, d, e;
	dice(int f, int t, int b, int c, int d, int e) :
		f(f), t(t), b(b), c(c), d(d), e(e) {}

	void left() {
		int _f = d, _d = t, _t = e, _e = f;
		f = _f; d = _d; t = _t; e = _e;
	}

	void right() { left(); left(); left(); }

	void up() {
		int _f = b, _b = t, _t = c, _c = f;
		f = _f; b = _b; t = _t; c = _c;
	}

	void down() { up(); up(); up(); }

	void rot() {
		int _c = e, _e = b, _b = d, _d = c;
		c = _c; e = _e; b = _b; d = _d;
	}

	bool equal(dice &D) {
		return ((f == D.f) && (c == D.c) && (b == D.b) && (t == D.t) && (d == D.d) && (e == D.e));
	}

	bool operator==(dice &d2) {
		queue<dice> Q;
		short int visited[10][10][10][10][10][10];

		memset(visited, 0, sizeof(visited));
		visited[d2.f][d2.t][d2.e][d2.d][d2.c][d2.b] = 1;

		Q.push(d2);
		// printf ("[%d, %d, %d, %d, %d, %d]\n", c, f, d, t, e, b);
		while (!Q.empty()) {
			dice &D = Q.front();
			// printf ("   [%d, %d, %d, %d, %d, %d]\n", D.c, D.f, D.d, D.t, D.e, D.b);
			if (equal(D))
				break;

			D.left();
			if (!visited[D.f][D.t][D.e][D.d][D.c][D.b]) {
				visited[D.f][D.t][D.e][D.d][D.c][D.b] = 1;
				Q.push(D);
			}

			D.right(); D.up();
			if (!visited[D.f][D.t][D.e][D.d][D.c][D.b]) {
				visited[D.f][D.t][D.e][D.d][D.c][D.b] = 1;
				Q.push(D);
			}

			Q.pop();
		}

		return (!Q.empty());;
	}
};

int main(void) {
	int n;
	int v;
	int c, f, d, t, e, b;
	while (1) {
		cin >> n;
		if (!n) break;

		vector<dice> vd;
		while (n--) {
			cin >> c >> f >> d >> t >> e >> b;
			dice D(f, t, b, c, d, e);

			int insert = 1;
#if 0
			EACH(it,vd) {
				if (D == *it) {
					insert = 0;
					break;
				}
			}
#endif	
			if (insert)
				vd.push_back(D);
		}

		cout << vd.size() << endl;

	}

	return 0;
}

