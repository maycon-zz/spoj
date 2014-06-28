#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int v[5], n;

	scanf ("%d", &n);

	for (int T = 1; T <= n; ++T) {
		int pontos = 0;
		scanf ("%d %d %d %d %d", &v[0], &v[1], &v[2], &v[3], &v[4]);
		sort(v, v+5);

		if (v[1] == v[0]+1 && v[2] == v[1]+1 && v[3] == v[2]+1 && v[4] == v[3]+1)
			pontos = v[0] + 200;

		else if ((v[0] == v[1] && v[1] == v[2] && v[2] == v[3]) || (v[4] == v[1] && v[1] == v[2] && v[2] == v[3]))
			pontos = (v[0] == v[1] ? v[0] : v[4]) + 180;

		else if ((v[0] == v[1] && v[1] == v[2] && v[3] == v[4]) || (v[0] == v[1] && v[2] == v[3] && v[3] == v[4]))
			pontos = (v[0] == v[2] ? v[0] : v[4]) + 160;

		else if ((v[0] == v[1] && v[1] == v[2]) || (v[1] == v[2] && v[2] == v[3]) || (v[2] == v[3] && v[3] == v[4]))
			pontos = (v[0] == v[1] ? v[0] : (v[1] == v[2] ? v[1] : v[2])) + 140;

		else if ((v[0] == v[1] && v[2] == v[3]) || (v[0] == v[1] && v[3] == v[4]))
			pontos = 2*v[0] + 3*v[3] + 20;
		else if (v[1] == v[2] && v[3] == v[4])
			pontos = 2*v[1] + 3*v[3] + 20;

		else if (v[0] == v[1]) pontos = v[0];
		else if (v[1] == v[2]) pontos = v[1];
		else if (v[2] == v[3]) pontos = v[2];
		else if (v[3] == v[4]) pontos = v[3];

		printf ("Teste %d\n%d\n\n", T, pontos);
	}

	return 0;
}

