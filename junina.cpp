#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>

using namespace std;

typedef set<int> Edges;
typedef vector<Edges> Graph;

int main(void)
{
	int N;
	int aux, t = 0;

	while (1) {
		scanf ("%d", &N);
		if (!N) break;

		Graph g(N+1);
		for (int i = 1; i <= N; i++) {
			
			while (scanf("%d", &aux) && aux) {
				g[i].insert(aux);
			}
		}

		int resp = 0;

		for (int i = 1; i <= N; i++) {
			int qt = 0;
			for (int j = 1; j <= N; j++) {
				
			}

			if (qt > resp) resp = qt;
		}

		printf ("Teste %d\n%d\n\n", ++t, resp);
	}

	return 0;
}
