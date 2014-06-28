#include <cstdio>
#include <stack>
#include <vector>

#define MP make_pair

using namespace std;


/*
 *        #      
 *      # #      
 *      # #   # #
 *  #   # #   # #
 *  # # # # # # #
 *  2 1 4 5 1 3 3
 */

typedef pair<int, int> pii;

int solve(vector<int> &V) {
	stack<pii> S;
	int n = V.size() + 1, num, area;
	int i, j, resp = 0;

	V.push_back(0);
	for (i = 0; i < n; i++) {
		num = V[i];
		if (S.empty()) {
			S.push(MP(1, num));
		} else {
			for (j = 1; !S.empty() && S.top().second > num; j++) {
				area = S.top().second * j;
				printf ("-> %d\n", area);
				if (area > resp) resp = area;
				S.pop();
			}
			if (S.empty()) {
				S.push(MP(1, num));
			} else {
			}
			//while (j--)
			//	stack[pos++] = num;
		}
	}

	return resp;
}

int main(void)
{
	int n, num;

	while (scanf("%d", &n) && n) {
		vector<int> V;
		while (n--) {
			scanf ("%d", &num);
			V.push_back(num);
		}
		printf ("%d\n", solve(V));
	}
	return 0;
}

