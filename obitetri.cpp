#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

#define EACH(it,v) for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

int main(void) {
	string nome;
	int ponto, maior, menor, pontos;
	int N, T = 0;

	while (1) {
		cin >> N;
		if (!N) break;

		vector<pair<int, string> > lista;

		while (N--) {
			cin >> nome;
			maior = -1; menor = 0x3f3f3f3f;	pontos = 0;

			for (int i = 0; i < 12; ++i) {
				cin >> ponto;
				pontos += ponto;
				if (ponto > maior) maior = ponto;
				if (ponto < menor) menor = ponto;
			}

			lista.push_back(make_pair(-(pontos - maior - menor), nome));
		}

		cout << "Teste " << ++T << endl;
		int old = -1, pos = 0, curr = 0;
		EACH(it,lista) {
			curr++;
			if (it->first != old) {
				pos = curr;
				old = it->first;
			}
			cout << pos << " " << -it->first << " " << it->second << endl;
		}
		cout << endl;
	}	

	return 0;
}
