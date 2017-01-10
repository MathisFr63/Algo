#include <stdio.h>
#include "tp.h"
#include <stdlib.h>

RESULTAT lireResultat(FILE *fe){
	RESULTAT r;
	fscanf(fe,"%s %s %f",r.nom,r.code,&r.moy);
	return r;
}

RESULTAT * chargeTresultat(char *nomfich,int *nbres){
	FILE *fe=fopen(nomfich,"r");
	RESULTAT * tRes;
	int i;

	if(fe==NULL){
		printf("Erreur lors de l'ouverture du ficher %s !\n",nomfich);
		*nbres=-1;
		return;
	}

	fscanf(fe,"%d",nbres);
	tRes=(RESULTAT *)malloc(*nbres * sizeof(RESULTAT));
	if (tRes==NULL){
		printf("Problème de Mémoire !\n");
		exit(1);
	}
	for (i=0;i<*nbres && i<10;i++){
		tRes[i]=lireResultat(fe);
	}
	fclose(fe);
	return tRes;
}

void afficheT(RESULTAT tRes[],int nbres){
	int i;

	printf("Nom\tCode\tMoyenne\n");
	for (i=0;i<nbres;i++){
		printf("%s\t%s\t%.1f\n",tRes[i].nom,tRes[i].code,tRes[i].moy);
	}
}

int test(void){
	char nomfich[20];
	RESULTAT *tabr[10];
	int nbres,i;

	printf("Quel est le nom du fichier dans lequel se trouve vos données ?");
	scanf("%s",nomfich);
	printf("Nom du fichier : %s\n",nomfich);
	*tabr=chargeTresultat(nomfich,&nbres);
	if (nbres<0){
		return -1;
	}
	afficheT(*tabr,nbres);
	for (i=0;i<nbres;i++){
		free(tabr[i]);
	}
	return 0;
}