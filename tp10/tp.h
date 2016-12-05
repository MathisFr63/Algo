#include <stdio.h>
#include <string.h>

typedef struct{
	char nom[21];
	char code[6];
	float moy;
}Resultat;

Resultat lireResultat(FILE *fe);
Resultat * chargeTResultat(char *nomfich,int *nbres);
void afficheT(Resultat tRes[],int nbres);
int test(void);
void sauveTResultats(Resultat *tres,int nbres);
Resultat *restaureTresultat(char *nomfich, int nbres);