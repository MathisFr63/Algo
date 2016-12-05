#include <stdio.h>
#include "mat.h"
#include <string.h>
#define TAILLE 10



Mat lireMat(FILE *fe){
	Mat matiere;
	fscanf(fe,"%s %d",matiere.code,&matiere.coef);
	fgets(matiere.des,31,fe);
	if(matiere.des[strlen(matiere.des)-1]=='\n')
		matiere.des[strlen(matiere.des)-1]='\0';
	return matiere;
}

int chargeFmat(Mat tmat[],int nbmax){
	FILE *fe=fopen("matiere.txt","r");
	Mat a;
	int i=0;

	if(fe==NULL){
		printf("ERREUR lors de l'ouverture du fichier !\n");
		fclose(fe);
		return -2;
	}

	a=lireMat(fe);
	while(feof(fe)==0){
		if(i==nbmax){
			printf("Tableau trop petit\n");
			fclose(fe);
			return -1;
		}
		tmat[i]=a;
		i++;
		a=lireMat(fe);
	}
	fclose(fe);
	return i;
}

void affichtabM(Mat tmat[],int nbmat){
	int i;
	printf("Code Matière\tCoefficient\tDésignation\n");
	for(i=0;i<nbmat;i++){
		printf("%s\t\t%d\t\t%s\n",tmat[i].code,tmat[i].coef,tmat[i].des);
	}
}

int rechMat(char code[],Mat tmat[],int nbmat){
	int i;

	for(i=0;i<nbmat;i++){
		if(strcmp(code,tmat[i].code)==0)
			return i;
	}
	return -1;
}

Mat saisieMat(Mat tmat[],int nbmat){
	Mat mat;
	int i;

	printf("Saisie d'une matière\n");
	printf("Code : ");
	scanf("%s",mat.code);
	for(i=0;i<nbmat;i++){
		while(strcmp(mat.code,tmat[i].code)==0){
			printf("Erreur : Code déjà enregistré pour \"%s\"\n",tmat[i].des);
			printf("Retapez : ");
			scanf("%s",mat.code);
			i=0;
		}
	}
	printf("Coefficient : ");
	scanf("%d%*c",&mat.coef);
	printf("Désignation : ");
	fgets(mat.des,31,stdin);
	if(mat.des[strlen(mat.des)-1]=='\n')
		mat.des[strlen(mat.des)-1]='\0';
	return mat;
}

void ajoutMat(void){
	Mat tmat[TAILLE],a;
	char choix;
	int nbmat,pos,i;
	FILE *fs=fopen("resultats.txt","w");

	nbmat=chargeFmat(tmat,TAILLE);
	if(nbmat<0)
		return;
	printf("%d\n",nbmat);
	printf("Voulez-vous saisir une matière ? (o/n)");
	scanf("%c%*c",&choix);
	while(choix=='o'){
		if(nbmat==TAILLE)
			return;	
		a=saisieMat(tmat,nbmat);
		strcpy(tmat[nbmat].code,a.code);
		strcpy(tmat[nbmat].des,a.des);
		tmat[nbmat].coef=a.coef;
		nbmat++;
		printf("Voulez-vous encore saisir une matière ? (o/n)");
		scanf("%*c%c",&choix);
	}
	affichtabM(tmat,nbmat);
	for(i=0;i<nbmat;i++){
		fprintf(fs,"%s %d %s\n",tmat[i].code,tmat[i].coef,tmat[i].des);
	}
	fclose(fs);
	printf("bien jouer a toi\n");
}

void test(void{}