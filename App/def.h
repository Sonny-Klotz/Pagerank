#ifndef DEF_H
#define DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define ALPHA 0.85

typedef struct {
	int i;
	int j;
	double p;
}Element;

typedef struct {
	int m;
	Element *T; //tableau d'elements
	int n; //taille de la matrice carre
	int *debCol;
}Matrice;

#endif
