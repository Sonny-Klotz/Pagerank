#include "puissances.h"

int puissances(Matrice *M, double *piK, double *piKplus1) {
	
	// k = nombre d'itérations (comme dans piK)
	int k = 0;
	int i, j;
	
	printf("# Iteration - Norme\n");
	double somme, norme, sigma;
	do {
		norme = 0.0;
		sigma = calcul_sigma(M , piK);
		
		for (i = 0; i < M->n; i++) {
			
			//multiplication ligne colonne
			for (j = M->debCol[i]; j < M->debCol[i + 1]; j++) {
				piKplus1[i] += piK[M->T[j].i] * M->T[j].p;
			}
			piKplus1[i] = ALPHA * piKplus1[i] + (1 - ALPHA + sigma * ALPHA) / M->n;
			norme += fabs(piKplus1[i] - piK[i]);
		}
		
		//ancien pi prend nouveau pi 
		for (i = 0; i < M->n; i++) {
			piK[i] = piKplus1[i];
			piKplus1[i] = 0.0;
		}
		
		//on incrémente l'itération
		k++;
		printf("%d %f\n", k, log(norme));
	}while(norme > 10e-6);
 	
 	return k;
}
