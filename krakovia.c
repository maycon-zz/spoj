#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 25

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

void reverse(char *s) {
	int i, sz = strlen(s), sz2 = sz/2;
	char aux;

	for (i = 0; i < sz2; ++i) {
		aux = s[i];
		s[i] = s[sz - (i + 1)];
		s[sz - (i + 1)] = aux;
	}
}

// d = d + s
void add(char *d, char *s)
{
	int szd = strlen(d), szs = strlen(s);
	int lim = MAX(szd, szs);
	int i, vai = 0, dig;

	if (szd < lim) for (i = szd; i < lim; ++i) d[i] = '0';
	else if (szs < lim) for (i = szs; i < lim; ++i) s[i] = '0';
	s[lim] = d[lim] = '\0';
	
	for (i = 0; i < lim; i++) {
		dig = (d[i] - '0') + (s[i] - '0') + vai;
		d[i] = '0' + (dig % 10);
		vai = (dig > 9);
	}
	d[i] = '\0';
	if (vai) { d[i] = '1'; d[i+1] = '\0'; }
}

// d = d / s
void idiv(char *s, int v)
{
	int r = 0, p = 0, i, d, sz = strlen(s);

	for (i = 0; i < sz; ++i) {
		r = 10*r + (s[i] - '0');
		d = r/v;
		if (p || d) s[p++] = '0' + d;
		r %= v;
	}
	s[p] = '\0';
	if (!p) strcpy(s, "0");
}

int main(void)
{
	int N, F, t = 0;
	char V[TAM], soma[TAM], partes[TAM];

	int i;

	while (1) {
		scanf ("%d %d ", &N, &F);
		if (!N && !F) break;

		V[0] = soma[0] = '\0';
		for (i = 0; i < N; ++i) {
			scanf ("%s", V);
			reverse(V);
			add(soma,V);
		}

		reverse(soma);
		strcpy(partes,soma);
		idiv(partes, F);

		printf ("Bill #%d costs %s: "
				"each friend should pay %s\n\n", ++t, soma, partes);
	}

	return 0;
}

