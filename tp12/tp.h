#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char nom[20];
	int nbmo;
	int nbma;
	int nbmb;
	int nbtm;
}Pays;



int chargeFresult(Pays *tpays[], int nbmax);
int recherche(Pays *tPays[],int nb,char *nom);
void affiche (Pays **tpays,int nb);
int rechmin(Pays *tpays[],int nbpays);
void triselect(Pays *tpays[],int nbpays);
int miseajour(Pays *tpays[],int nbpays,char *nomFich);
void sauvegarde(Pays *tpays[],int nbpays);