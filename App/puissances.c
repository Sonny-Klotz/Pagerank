#include "puissances.h"

void calcul_f(double *f, Matrice *M) {
	
	int i, j;
	int compteur = 0 ; //1 si il trouve que des 0 sur ligne i sinon 0 
	for (i = 0; i < M->n; i++) {
		for (j = M->debCol[i]; j < M->debCol[i + 1]; j++) {	
			if (M->T[j].p != 0.0) { //on parcours la ligne i, si on trouve une valeur autre que 0 compteur = 1
				compteur = 1;
			}
		}
		if (compteur == 0) f[i] = 1;
		else f[i] = 0;
		compteur = 0;
	}		
}

double calcul_sigma(Matrice *M, double *piK) {
	
	int i;
	double sigma = 0.0;
	
	double *f = malloc(M->n * sizeof(double));
	calcul_f(f, M); 

	for ( i = 0; i < M->n; i++) {
		sigma = sigma + f[i] * piK[i];
	}
	
	free(f);
	return sigma;
}

int puissances(Matrice *M, double *piK, double *piKmoins1) {
	
	// k = nombre d'itérations (comme dans piK)
	int k = 0;
	int i, j;
	
	printf("# Iteration - Norme\n");
	double somme, norme, sigma;
	do {
		norme = 0.0;
		sigma = calcul_sigma(M , piK);
		//ancien pi prend nouveau pi 
		for (i = 0; i < M->n; i++) {
			piKmoins1[i] = piK[i];
			piK[i] = 0.0;
		}
		for (i = 0; i < M->n; i++) {
			
			//multiplication ligne colonne
			for (j = M->debCol[i]; j < M->debCol[i + 1]; j++) {
				piK[i] += piKmoins1[M->T[j].i] * M->T[j].p;
			}
			piK[i] = ALPHA * piK[i] + (1 - ALPHA + sigma * ALPHA) / M->n;
			norme += fabs(piKmoins1[i] - piK[i]);
		}
		
		//on incrémente l'itération
		k++;
		printf("%d %f\n", k, log(norme));
	}while(norme > 10e-6);
 	
 	return k;
}
