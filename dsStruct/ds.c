#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ds.h"

Etudiant lireEtu(FILE *fe){
	Etudiant etu;
	fgets(etu.nom,20,fe);
	if(etu.nom[strlen(etu.nom)-1]=='\n')
		etu.nom[strlen(etu.nom)-1]='\0';
	fgets(etu.prenom,20,fe);
	if(etu.prenom[strlen(etu.prenom)-1]=='\n')
		etu.prenom[strlen(etu.prenom)-1]='\0';
	fscanf(fe,"%d%d%d",&etu.naissance.jour,&etu.naissance.mois,&etu.naissance.annee);
	fscanf(fe,"%s ",etu.etab);
	fscanf(fe,"%s ",etu.c);
	return etu;
}

void afficheT(Etudiant etu){
	printf("%s\t%s\t%d/%d/%d\t\t%s\t\t%s\n",etu.nom,etu.prenom,etu.naissance.jour,etu.naissance.mois,etu.naissance.annee,etu.etab,etu.c);
}

Etudiant *ChargeEtudiants(char * nomFichier,int *nbEt){
	FILE *fe=fopen(nomFichier,"r");
	Etudiant * tEtu;
	int i;

	if(fe==NULL){
		printf("Erreur lors de l'ouverture du ficher %s !\n",nomFichier);
		exit(1);
	}

	fscanf(fe,"%d ",nbEt);
	tEtu=(Etudiant *)malloc(*nbEt * sizeof(Etudiant));
	if (tEtu==NULL){
		printf("Problème de Mémoire !\n");
		exit(1);
	}
	for (i=0;i<*nbEt;i++){
		tEtu[i]=lireEtu(fe);
	}
	fclose(fe);
	return tEtu;
}

int nbIUT(Etudiant * tEtu,int nbEt){
	int nbI;
	if(nbEt==1){
		if (strcmp(tEtu[0].etab,"IUT")==0)
			return 1;
		else
			return 0;
	}
	if (strcmp(tEtu[nbEt-1].etab,"IUT")==0)
		nbI++;
	nbI=nbIUT(tEtu,nbEt-1);
	return nbI;
}

void affChamb(Chambre tabChambre[],char bat,char etage,int nbCh){
	int i;

	for(i=0;i<nbCh;i++){
		if(tabChambre[i].num[0]==etage && tabChambre[i].num[3]==bat)
			printf("%s\n",tabChambre[i].num);
	}
}

void suppr(char *nom,char *prenom,Chambre tabChambre[],int nbCh,Etudiant tEtu[],int *nbE){
	int i;
	char *chambre;

	for(i=0;i<*nbE;i++){
		if (strcmp(tEtu[i].nom,nom)==0 && strcmp(tEtu[i].prenom,prenom)==0){
			strcpy(chambre,tEtu[i].c);
			for(i;i<*nbE;i++){
				tEtu[i]=tEtu[i+1];
			*nbE--;
			}
		}
	}
	for(i=0;i<nbCh;i++){
		if (strcmp(tabChambre[i].num,chambre)==0){
			tabChambre[i].etat=0;
		}
	}
}

void sauveTEtudiants(Etudiant *tEtud,char *nomfich,int nbEt){
	int i;
	FILE *fs=fopen(nomfich,"wb");

	if(fs==NULL){
		printf("Erreur lors de l'ouverture du fcichier\n");
		exit(1);
	}

	fprintf(fs,"%d\n",nbEt);
	for(i=0;i<nbEt;i++){
		fwrite(&tEtud[i],sizeof(Etudiant),1,fs);
	}
	fclose(fs);
}