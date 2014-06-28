#include <cstdio>
#include <cmath>
#include <vector>

#define TAM 1000

using namespace std;

vector<int> monta_crivo (int n)
{
	vector<int> numbers(n*n, 1), ret;
	
	for (int i = 2; i < n; i++)
		if (numbers[i] == 1)
		{
			ret.push_back(i);
			for (int j = i*2; j < n*n; j += i)	numbers[j] = 0;
		}

	return ret;
}

int main(void)
{
	vector<int> crivo = monta_crivo(TAM);
	int N, C;

	//for (int i = 0; i < crivo.size(); i++) printf ("%d ", crivo[i]);
	//printf ("\n");
	

	while (1)
	{
		scanf ("%d", &N);
		if (N == 0) break;

		C = N;

		int ret = 0;
		for (int i = 0; (i < crivo.size()) && N; i++)
		{
			if (N % crivo[i] == 0)
			{
				while (N % crivo[i] == 0) { ret++; printf ("%d ", crivo[i]); N /= crivo[i]; }
			}
		}
		//if (N) ret++;

		printf ("%d : %d\n", C, ret);
	}

	return 0;
}


