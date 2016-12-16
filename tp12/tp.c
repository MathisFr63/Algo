#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"

int chargeFresult(Pays *tpays[], int nbmax){
	FILE *fe=fopen("joresult.don","r");
	int i=0;

	if(fe==NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		exit(1);
	}
	fscanf(fe,"%s %d %d %d",tpays[i]->nom,&tpays[i]->nbmo,&tpays[i]->nbma,&tpays[i]->nbmb);
	tpays[i]->nbtm=tpays[i]->nbmo+tpays[i]->nbma+tpays[i]->nbmb;
	while(feof(fe)==0 && i<nbmax){
		printf("%d\n",i);
		printf("%s\t%d\t%d\t%d\n",tpays[i]->nom,tpays[i]->nbmo,tpays[i]->nbma,tpays[i]->nbmb);
		// printf("Pays : %s\n",tpays[i]->nom);
		fscanf(fe,"%s %d %d %d",tpays[i]->nom,&tpays[i]->nbmo,&tpays[i]->nbma,&tpays[i]->nbmb);
		i++;
	}
	fclose(fe);
	return i;
}

void affiche (Pays **tpays,int nb){
	int i;

	printf("Nom\tOr\tArgent\tBronze\n");
	for(i=0;i<nb;i++){
		printf("%s\t%d\t%d\t%d\t%d\n",tpays[i]->nom,tpays[i]->nbmo,tpays[i]->nbma,tpays[i]->nbmb,tpays[i]->nbtm);
	}
}

int recherche(Pays *tPays[],int nb,char *nom){
	int deb=0,fin=nb-1,m,comp;

	while(deb<=fin){
		m=(deb+fin)/2;
		comp=strcmp(tPays[m]->nom,nom);
		if(comp==0)
			return m;
		else if(comp<0)
			fin=m-1;
		else
			deb=m+1;
	}
	return deb;
}