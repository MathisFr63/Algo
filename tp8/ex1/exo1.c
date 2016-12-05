#include <stdio.h>
#include "exo1.h"
#include <string.h>
#define MATIERE 10

void extract(void){
	FILE *fe=fopen("fnotes.txt","r");
	char mat[MATIERE],codeM[MATIERE],id[MATIERE];
	float note,somme=0,moy;
	int n=0;
	
	if(fe==NULL){
		printf("Erreur lors de l'ouverture du fichier fnotes\n");
		return;
	}

	printf("Tapez le code de la matière à traiter : ");
	scanf("%s",mat);
	printf("Notes données en %s :\n",mat);

	printf("Etudiants\tNotes\n");
	fscanf(fe,"%s%s%f",id,codeM,&note);
	while(feof(fe)==0){
		if(strcmp(codeM,mat)==0){
			printf("%s\t\t%.2f\n",id,note);
			somme+=note;
			n++;
		}
		fscanf(fe,"%s%s%f",id,codeM,&note);
	}
	fclose(fe);
	if(n==0){
		printf("\nAucune note pour cette matière\n");
	}
	else{
		moy=somme/n;
		printf("\nMOYENNE : %.2f\n",moy);
	}
}