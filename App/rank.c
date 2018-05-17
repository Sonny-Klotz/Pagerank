#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int i;
	int j;
	double p;
}Element;

typedef struct {
	int m;
	Element *T;//tableu d'element
	int n;//taille matrice carre
	int *debCol;
}Matrice;

void echanger(Element *T, int a, int b)
{
	Element temp = T[a];
	T[a] = T[b];
	T[b] = temp;
}

void quickSort(Element *T, int debut, int fin)
{
    int gauche = debut - 1;
    int droite = fin + 1;
    const int pivot = T[debut].j;
    
    if(debut >= fin)
        return;

    while(1)
    {
        do droite--; while(T[droite].j > pivot);
        do gauche++; while(T[gauche].j < pivot);

        if(gauche < droite)
            echanger(T, gauche, droite);
        else break;
    }
    quickSort(T, debut, droite);
    quickSort(T, droite+1, fin);
}

void init_element(Element *e, int i, int j, double p) {
	e->i = i;
	e->j = j;
	e->p = p;
}

void init_matrice(Matrice *M, int m, int n) {
	M->m = m;
	M->T = malloc(m * sizeof(Element));
	M->n = n;
	M->debCol = malloc((n + 1) * sizeof(int));
	int i ;
	for(i = 0; i < n + 1; i++) {
		M->debCol[i] = 0;
	}
}

void free_matrice(Matrice *M) {
	free(M->T);
	free(M->debCol);
}

void affiche(Matrice *M) {
	printf("Tableau T\n");
	printf("Nb éléments : %d\n", M->m);
	int i  = 0;
	for( i = 0; i < M->m; i++)
		printf("%*d %*d %lf\n", 2, M->T[i].i + 1, 2, M->T[i].j + 1, M->T[i].p); 

	printf("\n");
	printf("Tableau debCol\n");
	printf("Nb éléments : %d\n", M->n);
	for( i = 0; i < M->n; i++)
		printf("%*d %*d\n", 2, i + 1, 2, M->debCol[i]);
}

void majDebutColonnes(Matrice *M) {
	int tmp, somme;
	somme = 0;
	int i;
	for( i = 0; i < M->n + 1; i++) {
		tmp = M->debCol[i];
		M->debCol[i] = somme;
		somme += tmp;
	}
}

void import_matrice_td1(FILE *web, Matrice *M) {
	int n, m, d, count, ligne, colonne;
	double proba;
	
	Element tmp;
	
	fscanf(web, "%d\n%d\n", &n, &m);
	init_matrice(M, m, n);
		
	count = 0;
	int i ;
	int j ;
	for(i = 0; i < n; i++) {
		
		fscanf(web, "%d %d ", &ligne, &d);
		
		for(j = 0; j < d; j++) {
			
			fscanf(web, "%d %lf ", &colonne, &proba);
			init_element(&tmp, ligne - 1, colonne - 1, proba);
			
			M->T[count++] = tmp;
			++M->debCol[colonne - 1];
		}
	}
	majDebutColonnes(M);
	quickSort(M->T, 0, m - 1);
}

void calcul_distribution_td1(Matrice *M) {
	double *piN = malloc(M->n * sizeof(double));
	double *piA = malloc(M->n * sizeof(double));
	int i, j;
	for (i = 0; i < M->n; i++) {
		piN[i] = 0.0;
		piA[i] = 1.0 / (double) M->n;
	}	
	
	double somme, norme;
	do {
		norme = 0.0;
		for ( i = 0; i < M->n; i++) {
			//multiplication ligne colonne
			for ( j = M->debCol[i]; j < M->debCol[i + 1]; j++) {
				piN[i] += piA[M->T[j].i] * M->T[j].p;
			}
			norme += fabs(piN[i] - piA[i]);
			//printf("%lf\n", fabs(piN[i] - piA[i]));
		}
		//ancien pi prend nouveau pi
		int k;
		for (k = 0; k < M->n; k++) {
			piA[k] = piN[k];
			piN[k] = 0.0;
		}
		//printf("norme : %lf\n", norme);
	}while(norme > 10e-6);
	
	printf("Distribution Pi\n");
	for( i = 0; i < M->n; i++)
		printf("%lf ", piA[i]);
	printf("\n");
	
	free(piN);
	free(piA);
}


void calcul_f(double *f, Matrice *M ) {
	int i;
	int j;
	int compteur = 0 ;//1 si il trouve que des 0 sinon  si il trouve une valeur autre que 0 on lui affecte 0 
	for ( i = 0; i < M->n; i++) {
		for ( j = M->debCol[i]; j < M->debCol[i + 1]; j++) {
			double a = M->T[j].p;
			
			if (M->T[j].p != 0.0)//on parcours la ligne avec les valeurs , si on trouve une valeur autre que 0 compteur = 1
			{
				compteur = 1;
				
			}
			//printf("valeur de M->T[j].p :  %lf pour j : %d et la valeur du compteur :%d \n" , a , j , compteur);
		}
		if (compteur == 0)
		{
			f[i] = 1;
		}
		else 
		{
			f[i] = 0;
		}
		compteur = 0;
		//printf("la valeur de de f [i]: %lf pour i : %d  \n" , f[i] , i );
	}
		
}

double calcul_sigma(Matrice *M ,double *f , double *piA )
{
	int i;
	double sigma;
	for ( i = 0; i < M->n; i++) {
		sigma = sigma + f[i]*piA[i];
		//printf("la valeur de de f [i]: %lf pour i : %d  \n" , f[i] , i );
	}
	//printf("la valeur de sigma est : %lf \n" , sigma);
	return sigma;
	
}

void calcul_distribution_td2(Matrice *M) {
	double alpha = 0.85;
	double sigma; //sigma = piA * transposee(f)
	double *f = malloc(M->n * sizeof(double));
	calcul_f(f, M); 
	//f(i) = 1 si d+(i) = 0, 0 sinon
	int i, j ;
	double *piN = malloc(M->n * sizeof(double));
	double *piA = malloc(M->n * sizeof(double));
	for (i = 0; i < M->n; i++) {
		piN[i] = 0.0;
		piA[i] = 1.0 / (double) M->n;
	}	
	double somme, norme;
	do {
		norme = 0.0;
		sigma = calcul_sigma(M ,f , piA );
		for ( i = 0; i < M->n; i++) {
			//multiplication ligne colonne
			for (j = M->debCol[i]; j < M->debCol[i + 1]; j++) {
				piN[i] += piA[M->T[j].i] * M->T[j].p;
			}
			piN[i] = alpha * piN[i] + (1 - alpha + sigma * alpha) / M->n;
			norme += fabs(piN[i] - piA[i]);
		}
		//ancien pi prend nouveau pi
		int k ; 
		for (k = 0; k < M->n; k++) {
			piA[k] = piN[k];
			piN[k] = 0.0;
		}
		//norme;
		//printf("norme : %lf\n", norme);
	}while(norme > 10e-6);
	
	printf("Distribution Pi\n");
	for(i = 0; i < M->n; i++)
		printf("%lf\n", piA[i]);
	
	free(piN);
	free(piA);
 	free(f);
}

int main(int argc, char *argv[]) {
	
	Matrice *M;
		
	FILE *web = NULL;
	web = fopen(argv[1], "r");///modife pour nom fichier je prend le 1er
	
	if(web != NULL) {

		
		M = malloc(sizeof(Matrice));
		import_matrice_td1(web, M);
		affiche(M);
		
		//calcul_distribution_td1(M);
		calcul_distribution_td2(M);
		
		free_matrice(M);
		free(M);
		fclose(web);
	}
	else
		printf("Erreur fichier en argument.\n");
	return 0;
}
