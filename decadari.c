#include <stdio.h>

#define CTOD(x) ((x) - '0')

const int total_seg_gmt = 100;
const int total_min_gmt = 60*100;
const int total_hor_gmt = 60*60*100;

const int total_seg_dec = 100;
const int total_min_dec = 100*100;
const int total_hor_dec = 100*100*100;


int main(void)
{
	char hmsc[8];
	int hora_gmt;
	unsigned double hora_dec;
	int h, m, s, c;
	
	while (scanf("%s", hmsc) != EOF)
	{
		hora_gmt = (CTOD(hmsc[0])*10 + CTOD(hmsc[1]))*total_hor_gmt +
		           (CTOD(hmsc[2])*10 + CTOD(hmsc[3]))*total_min_gmt +
				   (CTOD(hmsc[4])*10 + CTOD(hmsc[5]))*total_seg_gmt +
				   (CTOD(hmsc[6])*10 + CTOD(hmsc[7]));
		
		hora_dec = hora_gmt * 8640000 / 10000000;
		
		printf ("%f\n", hora_dec);
		
		
		//printf ("%02d:%02d:%02d:%02d -> %d\n", h, m, s, c, hora_gmt);
	}
}
