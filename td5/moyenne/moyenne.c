#include <stdio.h>
#include"moyenne.h"


void test(void){
	int annee;
	float moyen;
	printf("Année à extraire :");
	scanf("%d",&annee);
	moyen=moyenne(annee);
	printf("La moyenne des notes obtenues au BAC en %d est : %.2f\n",annee,moyen);
}

float moyenne (int annee){
	FILE *fe;
	int num,jour,mois,an,nbE=0;
	float noteE,som=0,moy;
	fe=fopen("etudiants.txt","r");
	if (fe==NULL)
		return -1;
	fscanf(fe,"%d %d %d %d %f",&num,&jour,&mois,&an,&noteE);
	while (feof(fe)==0){
		if (an==annee)
		{
			som=som+noteE;
			nbE++;
		}
	}
	fscanf(fe,"%d %d %d %d %f",&num,&jour,&mois,&an,&noteE);
	fclose(fe);
	if (nbE==0)
		return -2;
	moy=som/nbE;
	return moy;
}