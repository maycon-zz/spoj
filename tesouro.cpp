#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
	int x, y, n, v, t = 0;
	double totf;
	int toti;

	while (1) {
		scanf ("%d %d %d", &x, &y, &n);
		if (!x && !y && !n) break;

		totf = x + y;

		queue<int> ini;
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &v);
			totf += (double)v;
			ini.push(v);
		}

		totf /= 2;
		if (ceil(totf) != floor(totf)) {
			printf ("Teste %d\nN\n\n", ++t);
			continue;
		}

		toti = (int)totf - max(x, y);

		queue<pair<queue<int>, int> > Q;
		Q.push(make_pair(ini, 0));
		while (!Q.empty()) {
			pair<queue<int>, int> elem = Q.front();
			if (elem.second == toti) {
				printf ("Teste %d\nS\n\n", ++t);
				break;
			}
			
			Q.pop();

			int len = elem.first.size();
			for (int i = 0; i < len; ++i) {
				int nv = elem.first.front();
				elem.first.pop();
				Q.push(make_pair(elem.first, elem.second + nv));
				elem.first.push(nv);
			}
		}

		if (!Q.empty()) {
			printf ("Teste %d\nN\n\n", ++t);
		}

	}

	return 0;
}

