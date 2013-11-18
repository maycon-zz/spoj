#include <iostream>
#include <list>
#include <queue>
#include <string>

#define MAX_LEN_NOME 15
#define QT_PTOS      12

using namespace std;

class ClasseCompara
{
	public:
		bool operator() (pair<int, string> a, pair<int, string>b) const
		{
			if (a.first != b.first)
				return a.first < b.first;
			return a.second > b.second;
		}
};

int main(void)
{
	pair<int, string> jogador;
	priority_queue< pair<int, string>, vector< pair<int, string> >, ClasseCompara> jogadores;
	
	char nome[MAX_LEN_NOME+1];
	int n, i, last, t, pos;
	int max, min, soma, pto;
	
	t = 1;
	while (scanf("%d", &n) && n)
	{
		while (n--)
		{
			scanf ("%s", nome);
			
			min = 1001; max = 0; soma = 0;
			for (i = 0; i < QT_PTOS; i++)
			{
				scanf ("%d", &pto);
				soma += pto;
				if (pto > max) max = pto;
				if (pto < min) min = pto;
			}
			
			soma -= (max + min);
			
			jogadores.push(pair<int, string> (soma, nome));
		}

	
		printf ("Teste %d\n", t++);

		pos = 1;
		i = 1;
		last = jogador.first;
		
		while (!jogadores.empty())
		{
			jogador = pair<int, string> (jogadores.top());
			
			if (last != jogador.first)
			{
				pos = i;
				last = jogador.first;
			}

			printf ("%d %d %s\n", pos, jogador.first, jogador.second.c_str());
			jogadores.pop();
			i++;
		}
		printf ("\n");
	}
	
	return 0;
}
