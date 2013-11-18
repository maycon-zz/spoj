#include <stdio.h>

const int dia = 24*60;

int main(void)
{
	int h1, m1, h2, m2;
	int t1, t2;
	
	while (1)
	{
		scanf ("%d %d %d %d", &h1, &m1, &h2, &m2);
		
		if (h1 + m1 + h2 + m2 == 0) break;
		
		t1 = h1*60 + m1;
		t2 = h2*60 + m2;
		
		printf ("%d\n", t2 - t1 + dia*(t1 >= t2));
	}
	
	return 0;
}