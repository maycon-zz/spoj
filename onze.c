#include <stdio.h>
#define C2D(v) ((v) - '0')

int main(void)
{
	char c, oldc;
	int r, sinal, p;
	
	sinal = -1;
	r = p = 0;
	
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			puts(r % 11 == 0 ? " is a multiple of 11." : " is not a multiple of 11.");
			r = p = 0;
		}
		else
		{
			if (p || (c != '0'))
			{
				if ((p == 1) && (oldc = '0'))
					putc('0', stdout);
				putc(c, stdout);
			}
				
			r += (C2D( c ) * (sinal *= -1));
			p++;
		}
		oldc = c;
	}
	
	return 0;
}
