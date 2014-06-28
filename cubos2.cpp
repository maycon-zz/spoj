#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <list>

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

	void up() {
		int _f = b, _b = t, _t = c, _c = f;
		f = _f; b = _b; t = _t; c = _c;
	}

	void rot() {
		int _c = e, _e = b, _b = d, _d = c;
		c = _c; e = _e; b = _b; d = _d;
	}

	int id() {
		return 100000*f + 10000*t + 1000*b + 100*c + 10*d + e;
	}

	int less_id() {
		int ret_id = id();
		REP(i,0,2) {
			REP(j,0,4) {
				REP(k,0,4) {
					if (id() < ret_id){
						ret_id = id();
					}
					rot();
				}
				left();
			}
			up();
		}
		return ret_id;
	}
};

int main(void) {
	int n;
	int v;
	int c, f, d, t, e, b;

	while (1) {
		cin >> n;
		if (!n) break;

		set<int> vd;
		while (n--) {
			cin >> c >> f >> d >> t >> e >> b;
			dice D(f, t, b, c, d, e);
			vd.insert(D.less_id());
		}

		cout << vd.size() << endl;

	}

	return 0;
}


