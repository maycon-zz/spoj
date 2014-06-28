#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,a,b) for(int i = int(a); i < int(b); ++i)
#define RREP(i,a,b) for(int i = int(a); i > int(b); --i)
#define MAX 1001


string operator+(string &s1, string &s2)
{
	int len1 = s1.size();
	int len2 = s2.size();
	int len = max(len1, len2);

	if (len1 < len2) s1 = string(len2 - len1, '0') + s1;
	else if (len2 < len1) s2 = string(len1 - len2, '0') + s2;

	int v1 = 0, d;
	string resp;
	for (int i = len - 1; i >= 0; --i) {
		d = (s1[i] - '0') + (s2[i] - '0') + v1;
		resp = string(1, '0' + (d % 10)) + resp;
		v1 = (d > 9);
	}
	if (v1) resp = "1" + resp;

	return resp;
}

string operator/(string &s1, int n)
{
	int d = 0;
	int sz = s1.size();
	string resp;

	REP(i, 0, sz) {
		d = 10*d + (s1[i] - '0');
		if (resp.size() || int(d/n))
			resp.append(1, '0' + int(d/n));
		d %= n;
	}

	if (resp.size() == 0) resp = "0";

	return resp;
}

int main(void)
{
	int N, F, I = 0;
	vector<string> V(MAX);

	while (1) {
		cin >> N >> F;
		if (!N && !F) break;

		string valor, soma;
		REP(i,0,N) {
			cin >> valor;
			soma = soma + valor;
		}
		cout << "Bill #" << (++I) << " costs " << soma << ": each friend should pay " << (soma / F) << endl << endl;
	}

	return 0;
}
