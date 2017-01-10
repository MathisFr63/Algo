#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int jour;
	int mois;
	int annee;
}Date;

typedef struct{
	char nom[20];
	char prenom[20];
	Date naissance;
	char etab[100];
	// char *c;
	char c[5];
}Etudiant;

typedef struct{
	char *num;
	int etat;
}Chambre;

// int charger(Chambre tabChambre[],int max);
Etudiant lireEtu(FILE *fe);
void afficheT(Etudiant etu);
Etudiant *ChargeEtudiants(char * nomFichier,int *nbEt);
int nbIUT(Etudiant * tEtu,int nbEt);
void affChamb(Chambre tabChambre[],char bat,char etage,int nbCh);
void suppr(char *nom,char *prenom,Chambre tabChambre[],int nbCh,Etudiant tEtu[],int *nbE);
void sauveTEtudiants(Etudiant *tEtud,char *nomfich,int nbEt);