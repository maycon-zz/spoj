/**
 * Author: Maycon Maia Vitali
 * Problem: http://br.spoj.pl/problems/ATAFUL/
 * Reference: http://pessoal.sercomtel.com.br/matematica/geometria/geom-areas/geom-areas-circ.htm
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#define PI (2*acos(0))
#define RAD(a) ((a)*(PI/180))
#define EPS 1e-9
#define pow2(a) ((a)*(a))

void rotacionaPonto (double *x, double *y, double ang)
{
	double senAng = sin(ang);
	double cosAng = cos(ang);
	double x2 = (*x)*cosAng - (*y)*senAng;
	double y2 = (*x)*senAng + (*y)*cosAng;
	
	//printf ("sen = %lf / cos = %lf\n", senAng, cosAng);
	
	(*x) = x2;
	(*y) = y2;
}

double calculaArea (double x1, double x2, double x3)
{
	return 0;
}

int main(void)
{
	double x, y, r;		// circunferencia em C(x, y) e raio 'r'
	double p, q, a, t;		// canhao em P(p, q), a = curvatura, t = emparelhamento
	
//	x = y = 1;
//	rotacionaPonto (&x, &y, RAD(135 + 270));
//	printf ("%lf %lf\n", x, y);
//	return 0;
	
	while (1)
	{
		scanf ("%lf %lf %lf", &x, &y, &r);
		if (!x && !y && !r) break;
		
		scanf ("%lf %lf %lf %lf", &p, &q, &a, &t);
		
		// Tranlada o canhhao para o centro
		x -= p; y -= q;
		p = q = 0;
#ifdef DEBUG		
		printf ("Apos transladar (%.0lf, %.0lf)\n", x, y);
#endif		
		
		// Rotaciona, colocando a bissetriz do angulo do canhão no eixo x.
		rotacionaPonto (&x, &y, -RAD(a));
#ifdef DEBUG		
		printf ("Apos rotacionar (%.0lf, %.0lf)\n", x, y);
#endif		
		// Obtem o coeficiente algular (m) das retas que atravessam a cincunferencia,
		// assim suas funções serão y = x*m e y = -y*m, para que possamos iguala-la
		// a equacao da cincunferencia e achar tais pontos
		double m = tan(RAD(t/2));

		double area_nao_destruida;
		double area_total, area_setor, area_triangulo;
		double delta, x1 = 0, x2 = 0, y1, y2;
		double l, ang;
		
		area_total = PI*r*r;
		area_nao_destruida = 0;
		
		for (int i = 0; i < 2; i++)
		{
#ifdef DEBUG
			printf ("Coeficiente angular: %lf\n", m);
#endif
			double A, B, C;
			A = m*m + 1;
			B = -2*x - 2*y*m;
			C = x*x + y*y - r*r;

			delta = B*B - 4*A*C;
			if ((delta < 0) && (delta >= -EPS)) delta = 0;
		
			if (delta >= 0)
			{
				x1 = (-B + sqrt(delta))/(2*A);
				x2 = (-B - sqrt(delta))/(2*A);

				y1 = x1*m;
				y2 = x2*m;

#ifdef DEBUG				
				printf ("P1(%lf, %lf) P2(%lf, %lf)\n", x1 , y1, x2, y2);
#endif
				
				if ((x1 < 0) || (x2 < 0))
				{
					area_nao_destruida = area_total;
					break;
				}
				
							
				l = sqrt(pow2(x2 - x1) + pow2(y2 - y1));			
				ang = acos((2*pow2(r) - pow2(l))/(2*pow2(r)));
				area_triangulo = (r*r*sin(ang))/2;
				area_setor = (ang*r*r)/2;

#ifdef DEBUG
				printf ("Distancia: %lf\n", l);					
				printf ("Angulo: %lf (%lf)\n", ang, ang*180/PI);
				printf ("Area Total: %lf\n", area_total);
				printf ("Area Triangulo: %lf\n",  area_triangulo);
				printf ("Area Setor: %lf\n",  area_setor);
#endif					
				if (y - m*x > EPS)
					area_nao_destruida += area_total - area_setor + area_triangulo;
				else
					area_nao_destruida += (area_setor - area_triangulo);

#ifdef DEBUG
				printf ("\n");
#endif
			}
			else
			{
				if ((i == 0) && (abs(y/x) - m > EPS))
				{
					printf ("Caso 1\n");
					area_nao_destruida = area_total;
					break;
				}
				else if ((i == 1) && (abs(y/x) - m < EPS))
				{
					printf ("Caso 2\n");
					area_nao_destruida = area_total;
					break;
				}
			}
			
			m = -m;
		}
	
		printf ("%.1lf\n", area_total - area_nao_destruida);
#ifdef DEBUG
		printf ("\n\n");
#endif
	}
	
	return 0;
}

