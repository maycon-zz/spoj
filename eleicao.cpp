#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	int n, voto, votos, vencedor, votos_vencedor;
	map < int, int > candidatos;
	
	scanf ("%d", &n);
	votos_vencedor = 0;
	while (n--)
	{
		scanf ("%d", &voto);
		votos = candidatos[voto]++;
		
		if (votos > votos_vencedor)
		{
			votos_vencedor = votos;
			vencedor = voto;
		}
	}
	
	printf ("%d\n", vencedor);
}

