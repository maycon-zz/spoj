#include <stdio.h>

const int max_len = 52*26;

int main(void)
{
	int crivo[max_len];
	
	char c;
	int s, i, j, l;

	//----------------------------------------
	// monta o crivo de eratostenes
	//----------------------------------------
	memset (crivo, 0, sizeof(crivo));
	for (i = 2, l = sqrt(max_len); i < l; i++)
	{
		if (!crivo[i])
		{
			for (j = i*i; j < max_len; j += i)
			{
				crivo[j] = 1;
			}
				
		}
	}
	
	//----------------------------------------
	// Resolve os problemas
	//----------------------------------------
	s = 0;
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			printf ("%s\n", (crivo[s] ? "It is not a prime word." : "It is a prime word."));			
			s = 0;
		}
		else
		{
			s += ((tolower(c) == c) ? (c - 'a' + 1) : (c - 'A' + 27));
		}
	}
	
	return 0;
}
