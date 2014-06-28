#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

#define MOD(a,b) ((((a) % (b)) + (b)) % (b))
#define MAX 100001

using namespace std;

int main(void)
{
	map <string, int> teclas;

	teclas["C"]  = teclas["B#"] = 0;
	teclas["C#"] = teclas["Db"] = 1;
	teclas["D"]  = 2;
	teclas["D#"] = teclas["Eb"] = 3;
	teclas["E"]  = teclas["Fb"] = 4;
	teclas["F"]  = teclas["E#"] = 5;
	teclas["F#"] = teclas["Gb"] = 6;
	teclas["G"]  = 7;
	teclas["G#"] = teclas["Ab"] = 8;
	teclas["A"]  =  9;
	teclas["A#"] = teclas["Bb"] = 10;
	teclas["B"]  = teclas["Cb"] = 11;

	int n, m, i;
	int vn[MAX], vm[MAX];
	char nota[3], sn[MAX], sm[MAX];

	while (1)
	{
		scanf ("%d %d", &n, &m);
		if (!n && !m) break;

		for (i = 0; i < n; i++)
		{
			scanf ("%s", nota);
			vn[i] = teclas[string(nota)];
		}

		for (i = 0; i < m; i++)
		{
			scanf ("%s", nota);
			vm[i] = teclas[string(nota)];
		}

		for (i = 1; i < n; i++)
			sn[i-1] = 'A' + MOD(vn[i] - vn[i-1], 12);
		sn[i-1] = 0;

		for (i = 1; i < m; i++)
			sm[i-1] = 'A' + MOD(vm[i] - vm[i-1], 12);
		sm[i-1] = 0;

		if (strstr(sn, sm)) puts ("S");
		else puts("N");
	}

	return 0;
}

