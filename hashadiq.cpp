#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

typedef struct
{
	int cod;
	string fname;
	string lname;
	string bday;
	string tel;
} INFO;

#define MAX_LINE_LEN 100000

int main(void)
{
	map<int, INFO> bd;
	map<int, INFO>::iterator it;
	INFO *pbd;
	string fname, lname, bday, tel, cmd;
	int cod;

	while (cin >> cmd)
	{
		if (cmd == "add")
		{
			cin >> cod >> fname >> lname >> bday >> tel;
			pbd = &bd[cod];

			if (pbd->cod == cod)
				printf ("ID %d ja cadastrado.\n", cod);
			else
			{

				pbd->cod = cod;
				pbd->fname = fname;
				pbd->lname = lname;
				pbd->bday = bday;
				pbd->tel = tel;
			}
		}
		else if (cmd == "del")
		{
			cin >> cod;
			it = bd.find(cod);
			if (it == bd.end())
				printf ("ID %d nao existente.\n", cod);
			else
				bd.erase(it);
		}
		else if (cmd == "info")
		{
			cin >> cod;
			it = bd.find(cod);
			if (it == bd.end())
				printf ("ID %d nao existente.\n", cod);
			else
			{
				cout << it->second.cod << endl;
				cout << it->second.fname << " " << it->second.lname << " " << it->second.bday << " " << it->second.tel << endl;
			}
		}
		else if (cmd == "query")
		{
			char line[MAX_LINE_LEN  + 1];
			cin.getline(line, MAX_LINE_LEN);

		}
	}

	return 0;
}
