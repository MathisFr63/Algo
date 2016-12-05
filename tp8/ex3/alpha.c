#include <stdio.h>
#include "alpha.h"
#include <string.h>
#define LIG 25
#define COL 15

int chargement(char tabM[][COL]){
	FILE *fe=fopen("mot.txt","r");
	int i=0;
	char mot[COL];

	if(fe==NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		return;
	}
	fgets(mot,COL,fe);
		if(mot[strlen(mot)-1]=='\n')
			mot[strlen(mot)-1]='\0';
	while(feof(fe)==0 && i<COL){
		strcpy(tabM[i],mot);
		i++;
		fgets(mot,COL,fe);
		if(mot[strlen(mot)-1]=='\n')
			mot[strlen(mot)-1]='\0';
	}
	fclose(fe);
	return i;
}

void affichage(char tabM[][COL],int nbM){
	int i;

	for(i=0;i<nbM;i++){
		printf("%s\n",tabM[i]);
	}
}

void insert(char tabM[][COL],int *nbM){
	char ins[COL];
	int i,nb;

	printf("Mot à insérer : ");
	fgets(ins,COL,stdin);
		if(ins[strlen(ins)-1]=='\n')
			ins[strlen(ins)-1]='\0';

	if(*nbM>=LIG-1){
		printf("Le tableau est plein\n");
		return;
	}

	for(i=0;i<*nbM;i++){
		if(strcmp(ins,tabM[i])==0){
			printf("Le mot que vous voulez insérer exite déjà !\n");
			return;
		}
		else if(strcmp(ins,tabM[i])>0){
			for(nb=*nbM;nb>i+1;nb--){
				strcpy(tabM[nb],tabM[nb-1]);
			}
			strcpy(tabM[nb],ins);
			(*nbM)++;
			return;
		}
		else if(i=*nbM-1){
			strcpy(tabM[i],ins);
		}
	}
}

void save(char tabM[][COL],int nbM){
	FILE *fs=fopen("mot.txt","w");
	int i;
	
	for(i=0;i<nbM;i++){
		fprintf(fs,"%s\n",tabM[i]);
	}
	fclose(fs);
}

void menu(void){
	int nbM,choix;
	char tabM[LIG][COL];

	nbM=chargement(tabM);
	printf("\nMenu : \n\n");
	printf("1| Affichage\n");
	printf("2| Insertion\n");
	printf("3| Mot le plus long\n");
	printf("4| Quitter\n");
	scanf("%d",&choix);

	while(choix!=4){
		if(choix==1){
			affichage (tabM,nbM);
		}
		else if(choix==2){
			insert(tabM,&nbM);
		}
		else if(choix==3){
			mLong(tabM,nbM);
		}
		printf("\nMenu : \n\n");
		printf("Choix : ");
		scanf("%d",&choix);
	}
	save(tabM,nbM);
}

void mLong(char tabM[][COL],int nbM){
	char mot[LIG][COL],tCores[LIG][COL];
	int n=0,i;

	printf("Saisir des lettres (max 8)\n");
	scanf("%s",mot);
	if(strlen(*mot)>8){
		printf("Erreur le mot saisi est trop long !\n");
	}

	for(i=0;i<8;i++){
		for(i=0;i<nbM;i++){
		}
	}
}