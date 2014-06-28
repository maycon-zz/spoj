#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
	int n=0,m=0;
	double v=0.00;
	while ( scanf( "%lf %d %d",&v,&n,&m ) && ( v != 0 ||  n != 0 || m != 0 ) ){
		if ( n%10000 == m%10000 ) 
			printf ("%.2lf\n",v*3000);
		else
			if ( n%1000 == m%1000 )
				printf ( "%.2lf\n",v*500 );
			else
				if ( n%100 == m%100 )
					printf ( "%.2lf\n",v*50 );
				else
					if ( n%100 == 0 || m%100 == 0 ) {
						if ( ceil( (n%100)/4.00 ) == 0 && ceil( (m%100/4.00) ) == 25 )
							printf ("%.2lf\n",v*16);
						else
							if ( ceil( (m%100)/4.00 ) == 0 && ceil( (n%100/4.00) ) == 25 )
								printf ("%.2lf\n",v*16);
					}else
						if ( ceil( (n%100)/4.00 ) == ceil( (m%100)/4.00 ) )
							printf ("%.2lf\n",v*16);
						else
							printf ("%.2lf\n",0);
	}
	return 0;
}
