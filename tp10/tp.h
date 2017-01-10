#include <stdio.h>
#include <string.h>

typedef struct{
	char nom[21];
	char code[6];
	float moy;
}RESULTAT;

RESULTAT lireResultat(FILE *fe);
RESULTAT * chargeTresultat(char *nomfich,int *nbres);
void afficheT(RESULTAT tRes[],int nbres);
int test(void);