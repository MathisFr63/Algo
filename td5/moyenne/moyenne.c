#include <stdio.h>
#include"moyenne.h"

void globale (void){
	int anne;
	float moy;
	printf("Qu'elle année voulez-vous saisir ?");
	scanf("%d",&anne);
	moy=moyenne(anne);
	printf("La moyenne en %d était de : %.2f\n",anne,moy);
}

float moyenne (int annee){
	FILE *fe;
	int num,jour,mois,an,nbE=0;
	float noteE,som=0,moy;
	fe=fopen("etudaints.txt","r");
	if (fe==NULL) return -1;
	fscanf(fe,"%d %d %d %d %f",&num,&jour,&mois,&an,&noteE);
	while(feof(fe)==0){
		if (an==annee){
			som=som+noteE;
			nbE++;
		}
	}
	fscanf(fe,"%d %d %d %d %f",&num,&jour,&mois,&an,&noteE);
	fclose(fe);
	if (nbE==0) return -2;
	moy=som/nbE;
	return moy;
}
