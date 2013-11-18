#include <stdio.h>

int main(void)
{
	float A, G, Ra, Rg;	
	scanf ("%f %f %f %f", &A, &G, &Ra, &Rg);
	printf ("%c\n", (A / Ra) < (G / Rg) ? 'A' : 'G');	
	return 0;
}
