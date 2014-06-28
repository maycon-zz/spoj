#include <cstdio>
#include <cmath>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

double dist(pair<int, int> p1, pair<int, int> p2)
{
	double a, b;

	a = (double)abs(p1.first - p2.first);
	b = (double)abs(p1.second - p2.second);

	return sqrt(a*a + b*b);
}

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
			d = min(d, dist(pontos[i], pontos[j]));

	if (d != INF) printf ("%.3f\n", d);
	else printf ("0\n");

	return 0;
}
