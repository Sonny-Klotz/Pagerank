#include "def.h"
#include "matrice.h"
#include "puissances.h"
#include "aitken.h"

int main(int argc, char *argv[]) {
	
	Matrice *M;
	time_t debut, fin;
		
	FILE *web = NULL;
	web = fopen(argv[1], "r");
	
	if(web != NULL) {
		
		//##### initialisation de la matrice #####
		
		M = malloc(sizeof(Matrice));
		import_matrice(web, M); fclose(web);
		//affiche(M);
		
		double *piK = malloc(M->n * sizeof(double));
		double *piKplus1 = malloc(M->n * sizeof(double));
		double *piKplus2 = malloc(M->n * sizeof(double));
		init_distrib(M->n, piK, piKplus1, piKplus2);
		
		
		
		//##### calcul des pertinences #####
		
		time(&debut);
		
		int nbIterations = puissances(M, piK, piKplus1);
		//int nbIterations = aitken(M, piK, piKplus1, piKplus2);
		
		time(&fin);
		printf("%d %f", nbIterations, difftime(fin, debut));
		
		
		
		free_matrice(M); free(M);
		free(piK); free(piKplus1); free(piKplus2);
	}
	else
		printf("Erreur fichier en argument.\n");
	return 0;
	
	return 0;
}
