#include <stdio.h>
#include"ds.h"

int repartitionNote(float *moyUE,int tabComptD2[]){
	FILE *fe;
	float som=0;
	int noE,d1,d2,nbE=0,nbNote=0,i=0;
	fe=fopen("noteEtudiants.txt","r");
	if (fe==NULL)
		return -1;
	fscanf(fe,"%d%d%d",&noE,&d1,&d2);
	if (feof(fe)!=0)
		return -2;
	while (feof(fe)==0){
		nbE++;
		tabComptD2[d2]++;
		fscanf(fe,"%d%d%d",&noE,&d1,&d2);
	}
	fclose(fe);
	fe=fopen("noteEtudiants.txt","r");
	fscanf(fe,"%d%d%d",&noE,&d1,&d2);
	for (i=0;i<nbE;i++){
		som=som+d1+2*d2;
		nbNote=nbNote+3;
		fscanf(fe,"%d%d%d",&noE,&d1,&d2);	
	}
	printf("Notes : %d\n",nbNote);
	printf("Somme : %.2f\n",som);
	*moyUE=som/nbNote;
	
	fclose(fe);
	
	return 0;
}

void essai(void){
	float moyUE;
	int tabComptD2[21]={0};
	int codeErreur,i=0;
	
	codeErreur=repartitionNote(&moyUE,tabComptD2);
	if (codeErreur==0){
		printf("note :\t");
		for (i=0;i<21;i++){
			printf("%d\t",i);
		}
		printf("\nD2 :\t");
		for (i=0;i<21;i++){
			printf("%d\t",tabComptD2[i]);
		}
		printf("\nMoyenne pour UE : %.2f\n",moyUE);
	}
	else if (codeErreur==-1)
		printf("Erreur d'ouverture du fichier\n");
	else if (codeErreur==-2)
		printf("Le fichier est vide\n");
}