#include <stdio.h>
#include <string.h>

#define PD_LEN 1501
#define TAM 1000001
#define Char2Digit(c) ((c) - '0')


int main(void)
{
	int pd[PD_LEN];
	char k[TAM];
	int t, i, len, num;
	
	pd[0] = 0; pd[1] = 1;
	for (t = 2; t < PD_LEN; t++)
		pd[t] = (pd[t-1] + pd[t-2]) % 1000;
	
	fscanf (stdin, "%d", &t);
	while (t--)
	{
		gets (k);
		puts(k);
		len = strlen(k);
		
		
		for (num = 0, i = 0; i < len; i++)
			num = (10*num + Char2Digit(k[i])) % 1500;

		printf ("%03d\n", pd[num]);
	}
	
	return 0;
}