#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i,a,b) for(int i = int(a); i < int(b); ++i)
#define TYPE(x) __typeof((x))
#define EACH(it,v) for(TYPE((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define IN(i,a,b) ((i >= a) && (i <= b))

struct SEQ {
	int l, c, val, d;
	vector<int> seq;
	int sum;

	SEQ(int l, int c) : l(l), c(c) { val = sum = 0; }
};

int seq[4][3] = {
	{ 1,  2,  3},
	{ 4,  5,  6},
	{ 7,  8,  9},
	{-1,  0, -1}
};

int poskb[10][2] = {
	{3, 1}, {0, 1}, {0, 2}, {0, 3}, {1, 1}, // 0, 1, 2, 3, 4
	{1, 2}, {1, 3}, {2, 1}, {2, 2}, {2, 3}  // 5, 6, 7, 8, 9
};

int dc[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dl[] = {-1,  0,  1, -1, 1, -1, 0, 1};

int process(int S, int D) {
	int r = 0;

	REP(i,0,10) {
		queue<SEQ> Q;
		Q.push(SEQ(poskb[i][0],poskb[i][1]));

		while (!Q.empty()) {
			SEQ &e = Q.front();
			if (e.sum == S) {
				EACH(it,e.seq) cout << *it << " ";
				cout << endl;
				r = 1;
				break;
			}
			REP(i, 0, 8) {
				int nl = e.l + dl[i];
				int nc = e.c + dc[i];

				if (!IN(nl, 0, 3) || !IN(nc, 0, 2) || seq[nl][nc] == -1) continue;

			}

			Q.pop();
		}

	}
	return r;
}

int main(void) {
	int S, D, t = 0;

	cin >> S >> D;

	cout << "#" << (++t) << endl;
	if (!process (S, D))
		cout << "Impossivel" << endl;

	return 0;
}
