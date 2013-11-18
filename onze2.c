#include <stdio.h>

#define C2D(v) ((v) - '0')
#define MAX_LEN 10001

int main(void)
{
	char buf[MAX_LEN];
	int r, sinal, p;
	
	while ((scanf("%s", buf) != EOF) && ((buf[0] != '0') || buf[1]))
	{
		for (r = p = 0, sinal = -1; buf[p]; p++)
			r += (C2D( buf[p] ) * (sinal *= -1));
		printf ("%s %s\n", buf, (r % 11 == 0 ? "is a multiple of 11." : "is not a multiple of 11."));
	}
	return 0;
}
