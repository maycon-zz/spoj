#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LINHA 1001

char quad1[1001][1001], quad2[61][61];
unsigned long long quad[1001][1001], padrao[60];

int shift_and(unsigned long long *text, int text_len, unsigned int pattern_len, unsigned long long *bitmask, int *pos)
{
	int i;
	unsigned long long R = 0;

	for (i = 0; i < text_len; i++)
	{
		printf ("R = %lld\n", R);
		printf ("text[i] = %lld (0x%08x)\n", text[i], text[i]);
		printf ("bitmask[text[i]] = %lld\n", bitmask[text[i]]);
		R = ((R >> 1LL) | (1LL << (pattern_len - 1LL))) & bitmask[text[i]];
		if (R & 1) { (*pos) = i - pattern_len + 1 ; return 1; }
	}
	
	return 0;
}

long long *buildFail(unsigned long long *p, int m) {
	long long *fail = (long long*)malloc((m+1) * sizeof(long long)); // new long long[m+1];
	long long j = fail[0] = -1;
	for (int i = 1; i <= m; ++i) {
		while (j >= 0 && p[j] != p[i-1]) j = fail[j];
			fail[i] = ++j;
	}
	return fail;
}

int match(unsigned long long *t, int n, unsigned long long *p, int m, long long *fail) {
	//int n = strlen(t), m = strlen(p);
	int count = 0;
	for (int i = 0, k = 0; i < n; ++i) {
	while (k >= 0 && p[k] != t[i]) k = fail[k];
		if (++k >= m) {
			++count; // match at t[i-m+1 .. i]
			k = fail[k];
		}
	}
	return count;
}

int main(void)
{
	int n, m, t = 0;
	int i, j, k, lim;
	unsigned long long mask[256];
		
	while (scanf ("%d %d", &n, &m) != EOF)
	{
		for (i = 0; i < n; i++) scanf ("%s", quad1[i]);
		for (i = 0; i < m; i++) scanf ("%s", quad2[i]);

		lim = (n-m)+1;
		
		// Inicializa zerado
		for (i = 0; i < m; i++) padrao[i] = 0;
		for (i = 0; i < lim; i++) for (j = 0; j < lim; j++) quad[i][j] = 0;
		memset(mask, 0, sizeof(mask));
		
		for (i = 0; i < m; i++) for (j = 0; j < m; j++)
			padrao[j] |= ((1 << i)*(quad2[i][j] == '|'));

		for (i = 0; i < n; i++) for (j = 0; j < m; j++)
			quad[0][i] |= ((1LL << j) * (quad1[j][i] == '|'));

		for (i = 1; i < lim; i++) for (j = 0; j < n; j++)
			quad[i][j] = (quad[i-1][j] >> 1) | ((quad1[i+1][j] == '|') << (m-1));

		//for (i = 0; i < m; i++)
		//	mask[(int)padrao[i]] |= (1LL << (m - i - 1LL));
/*
		for (i = 0; i < m; i++)
			printf ("%lld ", padrao[i]);
		printf ("\n\n");
		
		for (i = 0; i < lim; i++)
		{
			for (j = 0; j < n; j++)
				printf ("%lld ", quad[i][j]);
			printf ("\n");
		}
		printf ("\n");
		
		for (i = 0; i < 256; i++)
			if (mask[i] != 0)
				printf ("[%d | %lld] ", i, mask[i]);
		printf ("\n\n");
*/
		int pos, foi = 0;
		
		printf ("Instancia %d\n", ++t);

		long long *fail = buildFail(padrao, m);
		
		//for (i = lim-1; i >= 0; i--)
		for (i = (lim-1); i >= 0; i--)
		{
			//if (shift_and(quad[i], n, m, mask, &pos))
			if (match(quad[i], n, padrao, m, fail))
			{
				foi = 1;
				printf ("%d %d\n", i, pos);
			}
		}

		if (!foi)
			printf ("nenhuma ocorrencia\n");
		printf ("\n");
	}
	
	return 0;
}
