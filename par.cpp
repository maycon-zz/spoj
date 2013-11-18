#include <iostream>
#include <cstdio>

using namespace std;

#define LEN_NAME 11

int main(void)
{
	int n, v1, v2, t = 0;
	char name1[LEN_NAME], name2[LEN_NAME];
	
	while (1)
	{
		scanf ("%d", &n);
		if (!n) break;
		
		printf ("Teste %d\n", ++t);
		
		scanf ("%s %s", name1, name2);
		while (n--){
			scanf ("%d %d", &v1, &v2);
			printf ("%s\n", (((v1 + v2) % 2) == 0 ? name1 : name2));
		}
		printf ("\n");
	}
	
	return 0;
}
