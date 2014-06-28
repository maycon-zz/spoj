#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int main(void)
{
	int N, X, Y;
	vector <pair<int, int> > pontos;

	scanf ("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf ("%d %d", &X, &Y);
		pontos.push_back(make_pair(X, Y));
	}

	double d = INF;
	for (int i = 0; i < N - 1; i++)
		for (int j = i+1; j < N; j++)
		{
			double x = pontos[i].first - pontos[j].first;
			double y = pontos[i].second - pontos[j].second;
			d = min(d, x*x + y*y);
		}

	if (d != INF) printf ("%.3f\n", sqrt(d));
	else printf ("0\n");

	return 0;
}


