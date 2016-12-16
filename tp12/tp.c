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
	printf("Nom\tOr\tArgent\tBronze\n");
	fscanf(fe,"%s %d %d %d ",tpays[i]->nom,&tpays[i]->nbmo,&tpays[i]->nbma,&tpays[i]->nbmb);
	while(feof(fe)==0 && i<nbmax){
		printf("%d\n",i);
		printf("%s\t%d\t%d\t%d\n",tpays[i]->nom,tpays[i]->nbmo,tpays[i]->nbma,tpays[i]->nbmb);
		// printf("Pays : %s\n",tpays[i]->nom);
		fscanf(fe,"%s %d %d %d ",tpays[i]->nom,&tpays[i]->nbmo,&tpays[i]->nbma,&tpays[i]->nbmb);
		i++;
	}
	fclose(fe);
	return i;
}

