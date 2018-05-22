#include "aitken.h"
void estimation(int n , double* piK , double* piKmoins1 , double* piKmoins2 )
{
	double g;
	double h;
	
	int i ;
	for(i = 0 ; i < n ; i++)
	{
		g = (piKmoins1[i] - piKmoins2[i]) * (piKmoins1[i] - piKmoins2[i]);
		h = piK[i] - 2 * piKmoins1[i] + piKmoins2[i];
		piK[i] = piK[i] - (g/h);
	}
}
int aitken(Matrice *M, double *piK, double *piKplus1) {
	
	return 0;
}
