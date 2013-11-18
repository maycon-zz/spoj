#include <iostream>
#include <list>

using namespace std;

int main(void)
{
	list<char> s;
	list<char>::iterator it1, it2;

	int i, n, p;
	
	while (1)
	{
		scanf ("%d %d%*[\r\n]", &n, &p);
		
		if (!n && !p)
			break;
			
		s.clear();
		
		for (i = 0; i < n; i++)
			s.push_back (getchar());
		
		it2 = s.begin();
		while ((it2 != s.end()) && p)
		{
			it1 = it2;
			it2++;
			if (*it1 < *it2)
			{
				p--;
				s.erase(it1);
				if (it2 != s.begin())
				{
					it2--;
				}
			}
		}
		
		while(p--)
			s.pop_back();
		
		it1 = s.begin();
		while (it1 != s.end())
		{
			printf ("%c", *it1);
			it1++;
		}

		printf ("\n");
	}
	
	return 0;
}
