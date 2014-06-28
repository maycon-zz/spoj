#include <iostream>
#include <queue>

#define MAX_LEN 	50002
#define MAX_COIN	101

#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

/**
 * V		- Valor em centavos
 * moedas[] - Lista de possiveis moedas
 * n		- Quantidade de moedas
 * atu		- Qual o valor temos atualmente
 * aux		- Profundidade na arvore
 */
int calculaQtMoedas(int V, int moedas[MAX_LEN], int n, int atu, int aux)
{
	queue< pair<int,int> > fila;	// cada elemento vai ter <profundidade, valor>
	pair<int,int> elem;
	int i, novoIndice, novoValor;
	int d[MAX_LEN];
	
	memset(d, 0x7f, sizeof(d));
	
	fila.push( pair<int,int>(0 , 0) );
	while (!fila.empty())
	{
		elem = fila.front();
		fila.pop();
		
		if (elem.second == V)
			return elem.first;
		
		for (i = 0; i < n; i++)
		{
			novoIndice = elem.first+1;
			novoValor  = elem.second + moedas[i];
			
			if (novoValor == V)
				return novoIndice;
			
			if ((novoValor < V) && (novoIndice < d[novoValor]))
			{
				d[novoValor] = novoIndice;
				fila.push( pair<int,int>(novoIndice , novoValor) );
			}
		}
		
		
	}
	
	return 0;
}

int main(void)
{
	int v, n;
	int moedas[MAX_LEN];
	int i, r;
	
	while ((scanf("%d", &v) != EOF) && v)
	{
		scanf ("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf ("%d", &moedas[i]);
		}
		
		r = calculaQtMoedas(v, moedas, n, 0, 0);
		if (r > 0)
			printf ("%d\n", r);
		else
			printf ("Impossivel\n");
	}
	
	return 0;
}

