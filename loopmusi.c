#include <stdio.h>

#define MAX 10003

int main(void)
{
	int n, i, r;
	int v[MAX];
	int sent_atu, sent_ant;
	
	while (1)
	{
		scanf ("%d", &n);
		if (!n) break;

		for (i = 0; i < n; i++)
			scanf ("%d", &v[i]);

		v[n++] = v[0];
		v[n] = v[1];
		
		sent_ant = (v[0] < v[1]);
		r = 0;
		
		for (i = 1; i < n; i++)
		{
			sent_atu = (v[i] < v[i+1]);
			r += (sent_ant != sent_atu);
			sent_ant = sent_atu;
		}
		
		printf ("%d\n", r);
	}
	
	return 0;
}
