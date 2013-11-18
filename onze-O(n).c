#include <stdio.h>
#define C2D(v) ((v) - '0')

#define MAX_LEN 1001

int main(void)
{
	char c;
	int r, sinal, p, imp;
	char buf[MAX_LEN];

	sinal = -1;
	r = p = imp = 0;

	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			if (!imp)
				break;
				
			puts(r % 11 == 0 ? " is a multiple of 11." : " is not a multiple of 11.");
			r = p = imp = 0;
			sinal = -1;
		}
		else
		{
			r += (C2D( c ) * (sinal *= -1));
			
			buf[p++] = c;
			if (c != '0') imp = 1;
			
			if (imp)
				putc(c, stdout);
		}
	}
	
	return 0;
}
