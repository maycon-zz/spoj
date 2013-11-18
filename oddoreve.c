#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int main(void)
{
	int qt_odd_mary, qt_even_mary;
	int qt_odd_john, qt_even_john;
	int n, i, v;
	int sol;
	
	while (1)
	{
		scanf ("%d", &n);
		if (!n) break;

		qt_odd_mary  = qt_odd_john  = 0;
		qt_even_mary = qt_even_john = 0;
		
		for (i = 0; i < n; i++)
		{
			scanf ("%d", &v);
			if (v % 2) qt_even_mary++; else qt_odd_mary++;
		}
		
		for (i = 0; i < n; i++)
		{
			scanf ("%d", &v);
			if (v % 2) qt_even_john++; else qt_odd_john++;
		}

		//sol = n - MIN(qt_even_mary, qt_odd_john) - MIN(qt_odd_mary, qt_even_john);
		sol = abs(qt_even_mary - qt_odd_john);
		
		printf ("%d\n", sol);		
	}
	
	return 0;
}
