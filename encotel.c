#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char c;

	while(scanf("%c", &c) != EOF)
	{
		if (isalpha(c))
			printf ("%d", (c - 'A')/3 - ((c == 'S') || (c == 'V') || (c >= 'Y')) + 2);
		else
			putc(c, stdout);
	}
	
	return 0;
}

