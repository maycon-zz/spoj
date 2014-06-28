#include <cstdio>
#include <stack>
#include <vector>

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
	int stack[100001], pos = 0;
	int n = V.size() + 1, num, area;
	int i, j, resp = 0;

	V.push_back(0);
	for (i = 0; i < n; i++) {
		num = V[i];
		if (pos == 0) {
			stack[pos++] = num;
		} else {
			for (j = 1; pos && stack[pos-1] > num; j++) {
				area = stack[pos-1] * j;
				if (area > resp) resp = area;
				pos--;
			}
			while (j--)
				stack[pos++] = num;
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

