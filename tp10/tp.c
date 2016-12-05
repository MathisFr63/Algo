#include <stdio.h>
#include "tp.h"
#include <stdlib.h>


Resultat lireResultat(FILE *fe){
	Resultat r;
	fscanf(fe,"%s %s %f",r.nom,r.code,&r.moy);
	return r;
}

Resultat * chargeTResultat(char *nomfich,int *nbres){
	FILE *fe=fopen(nomfich,"r");
	Resultat * tRes;
	int i;

	if(fe==NULL){
		printf("Erreur lors de l'ouverture du ficher %s !\n",nomfich);
		*nbres=-1;
		return;
	}

	fscanf(fe,"%d",nbres);
	tRes=(Resultat *)malloc(*nbres * sizeof(Resultat));
	if (tRes==NULL){
		printf("Problème de Mémoire !\n");
		exit(1);
	}
	for (i=0;i<*nbres;i++){
		tRes[i]=lireResultat(fe);
	}
	fclose(fe);
	return tRes;
}

void afficheT(Resultat tRes[],int nbres){
	int i;

	printf("Nom\tCode\tMoyenne\n");
	for (i=0;i<nbres;i++){
		printf("%s\t%s\t%.1f\n",tRes[i].nom,tRes[i].code,tRes[i].moy);
	}
}

int test(void){
	char nomfich[20];
	Resultat *tRes[10];
	int nbres,i;

	printf("Quel est le nom du fichier dans lequel se trouve vos données ?");
	scanf("%s",nomfich);
	*tRes=chargeTResultat(nomfich,&nbres);
	if (nbres<0){
		return -1;
	}
	sauveTResultats(*tRes,nbres);
	free(*tRes);
	*tRes=restaureTresultat(nomfich,nbres);
	afficheT(*tRes,nbres);
	free(*tRes);
	return 0;
}

void sauveTResultats(Resultat *tres,int nbres){
	FILE *fe=fopen("save.don","wb");

	fprintf(fe,"%d\n",nbres);
	fwrite(tres,sizeof(Resultat),nbres,fe);
	fclose(fe);
}

Resultat *restaureTresultat(char *nomfich, int nbres){
	FILE *fe=fopen("save.don","rb");
	Resultat *tres;

	fscanf(fe,"%d ",&nbres);
	tres=(Resultat *)malloc(nbres * sizeof(Resultat));
	if (tres==NULL){
		printf("Problème de Mémoire !\n");
		fclose(fe);
		exit(1);
	}
	fread(tres,sizeof(Resultat),nbres,fe);
	fclose(fe);
	return tres;
}