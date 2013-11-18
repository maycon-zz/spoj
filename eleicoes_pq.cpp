#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> votos;
	int n, voto;
	int vencedor, votos_vencedor;
	int i, j, qtde, pivo;
	
	scanf ("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &voto);
		votos.push_back(voto);
	}
	
	sort(votos.begin(), votos.end());
	
	votos_vencedor = 0;
	for (i = 0; i < n; i = j)
	{
		qtde = 1;
		pivo = votos[i];

		for (j = i+1; (j < n) && (votos[j] == pivo); j++)
			qtde++;

		if (qtde > votos_vencedor)
		{
			votos_vencedor = qtde;
			vencedor = votos[j-1];
		}
	}
	
	printf ("%d\n", vencedor);
	
	return 0;
}
