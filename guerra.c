#include <stdio.h>
#include <math.h>


int dseg[][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
int dplano[][3] = {{0, 1, 2}, {0, 1, 3}, {1, 2, 3}};

int rebelde[4][3];
int imperio[4][3];

double dist_pontos(int i, int j)
{
}

int main(void)
{
	int T, i, j;

	scanf ("%d", &T);

	while (T--) {
		for (i = 0; i < 4; i++)
			scanf ("%d %d %d", &rebelde[i][0], &rebelde[i][1], &rebelde[i][2]);

		for (i = 0; i < 4; i++)
			scanf ("%d %d %d", &imperio[i][0], &imperio[i][1], &imperio[i][2]);

		double d = 0x3f3f3f3f, d2;

		// ponto <-> ponto
		for (i = 0; i < 4; i++)
			for (j = 0, j < 4; j++) {
				d2 = dist_pontos(i, j);
				if (d2 < d) d = d2;
			}

		// seg <-> seg
		for (i = 0; i < 6; i++)
			for (j = 0; j < 6; j++) {
				d2 = dist_seg(i, j);
				if (d2 < d) d = d2;
			}

		// plano <-> plano
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++) {
				d2 = dist_plano(i, j);
				if (d2 < d) d = d2;
			}

		// seg <-> ponto
		for (i = 0; i < 6; i++)
			for (j = 0; j < 4; j++) {
				d2 = dist_seg_ponto1(i, j);
				if (d2 < d) d = d2;
				d2 = dist_seg_ponto2(i, j);
				if (d2 < d) d = d2;
			}

		// seg <-> ponto
		for (i = 0; i < 6; i++)
			for (j = 0; j < 3; j++) {
				d2 = dist_seg_plano1(i, j);
				if (d2 < d) d = d2;
				d2 = dist_seg_plano2(i, j);
				if (d2 < d) d = d2;
			}

		// seg <-> ponto
		for (i = 0; i < 4; i++)
			for (j = 0; j < 3; j++) {
				d2 = dist_ponto_plano1(i, j);
				if (d2 < d) d = d2;
				d2 = dist_ponto_plano2(i, j);
				if (d2 < d) d = d2;
			}

		printf ("%,02lf\n", d);

	}

	return 0;
}

