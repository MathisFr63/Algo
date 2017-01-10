#include <stdio.h>
#include "tableau.h"
#define TAILLE 10

/* */


/* */

void afficheMenu(void){
	printf("\tGestion des matières\n\n");
	printf("1\tAffichage\n");
	printf("2\tModification du coefficient d'une matière\n");
	printf("3\tCréation d'une matière\n");
	printf("4\tSuppression d'une matière\n");
	printf("9\tQuitter\n");
}


/* */

void menuMatieres(void){
	int choix,nbmat;
	int tabM[TAILLE], tabC[TAILLE];

	nbmat=chargement(tabM,tabC,TAILLE);
	if(nbmat == -1)
	  return;

	afficheMenu();
	printf("Quel est votre choix :");
	scanf("%d",&choix);

	while(choix!=9){
		if (choix==1){
			affmat(tabM,tabC,nbmat);
			printf("Quel est votre choix :");
			scanf("%d",&choix);
		}
	  	else if (choix==2){
			modif(tabM,tabC,nbmat);
			printf("Quel est votre choix :");
			scanf("%d",&choix); 	
	  	}
	  	else if (choix==3){
	  		nbmat=newmat(tabM,tabC,nbmat,TAILLE);
	  		printf("Quel est votre choix :");
			scanf("%d",&choix);
	  	}
	  	else if (choix==4){
	  		nbmat=suppr(tabM,tabC,nbmat);
	  		printf("Quel est votre choix :");
			scanf("%d",&choix);
	  	}
	  	if (choix==9){
		save(tabM,tabC,nbmat);
		}
	}
}


int chargement(int tabM[],int tabC[],int tailletab){
	FILE *fe;
	int nomat,coef,i=0;

	fe=fopen("tableau.txt","r");
	if (fe==NULL){
		printf("Erreur le fichier n'a pas pu être ouvert");
		return -1;
	}

	fscanf(fe,"%d%d",&nomat,&coef);
	while (feof(fe)==0){
		if (i==tailletab){
		    printf("tableau trop petit\n");
			fclose(fe);
			return -1;
		}
		tabM[i]=nomat;
		tabC[i]=coef;
		i++;
		fscanf(fe,"%d%d",&nomat,&coef);
	}

	fclose(fe);

	return i;
}


void affmat(int tabM[],int tabC[],int nbmat){
	int i;
	printf("Matière :\t");
	for (i=0;i<nbmat;i++){
		printf("%d\t",tabM[i]);
	}
	printf("\nCoefficient :\t");
	for (i=0;i<nbmat;i++){
		printf("%d\t",tabC[i]);
	}
	printf("\n");
}


int recherche(int tab[],int nbmat,int val){
	int i;

	for (i=0; i<=nbmat; i++){
 		  if (tab[i]==val){
			return i;
		}
	}
	return -1;
}


void modif(int tabM[], int tabC[],int nbmat){
	int val,pos,newcoef;
	printf("Numéro de matière à modifier :");
	scanf("%d",&val);
	pos=recherche(tabM,nbmat,val);

	if(pos==-1){
		printf("numéro de matière non trouvé\n");
		return;
	}
	
	printf("Ancien coefficient : %d\n",tabC[pos]);
	printf("Nouveau coefficient :");
	scanf("%d",&newcoef);
	tabC[pos]=newcoef;
}



void save(int tabM[], int tabC[],int nbmat){
	FILE *fs;
	int i;

	fs=fopen("tableau.txt","w");
	for (i=0;i<nbmat;i++){
			fprintf(fs, "%d %d\n",tabM[i],tabC[i]);
	}
	fclose(fs);
}

int newmat(int tabM[],int tabC[],int nbmat,int tailletab){
	int nomat,coef,pos;
	printf("Numéro de la nouvelle matière et Coefficient:");
	scanf("%d%d",&nomat,&coef);
	pos=recherche(tabM,nbmat,nomat);
	printf("%d %d\n",nomat,coef);
	if (nbmat<tailletab && pos==-1){
		tabM[nbmat]=nomat;
		tabC[nbmat]=coef;
		nbmat++;
	}
	else if (pos!=-1){
		printf("N° de matière déjà enregistré\n");
	}
	else{
		printf("tableau plein\n");
	}
	return nbmat;
}

int suppr(int tabM[],int tabC[],int nbmat){
	int nomat,pos,i;
	printf("Numéro de la matière à supprimer :");
	scanf("%d",&nomat);
	pos=recherche(tabM,nbmat,nomat);
	if (pos!=-1){
		printf("Le coefficient de cette matière est de : %d\n",tabC[pos]);
		for (i=pos;i<TAILLE;i++){
			tabM[i]=tabM[i+1];
			tabC[i]=tabC[i+1];
		}
		nbmat=nbmat-1;
	}
	else
		printf("N° de matière non trouvé");
	return nbmat;
}