#include <iostream>
#include <list>

using namespace std;

int main(void)
{
	int qt_a, qt_d, jog_a, jog_d;
	list<int> lst_a, lst_d;
	list<int>::iterator it;
	int fim, aux1, aux2;

	
	while (scanf ("%d %d", &qt_a, &qt_d) && qt_a && qt_d)
	{
		lst_a.clear();
		while (qt_a--)
		{
			scanf ("%d", &jog_a);
			lst_a.push_back(jog_a);
		}
		lst_a.sort();

		lst_d.clear();
		while (qt_d--)
		{
			scanf ("%d", &jog_d);
			lst_d.push_back(jog_d);
		}
		lst_d.sort();

		aux1 = lst_d.front(); lst_d.pop_front();
		aux2 = lst_d.front(); lst_d.pop_front();
		
		it = lst_a.begin();
		fim = 0;
		while (!fim && (it != lst_a.end()))
		{
			if (((*it > aux1) && (*it < aux2)) || ((*it == aux1) && (*it > aux2)))
			{
				printf ("Y\n");
				fim = 1;
			}
			
			it++;
		}
		
		if (!fim)
			printf ("N\n");
	}
	
	return 0;
}


