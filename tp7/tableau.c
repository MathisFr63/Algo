#include <stdio.h>
#include "tableau.h"
#define TAILLE 10


/*programme : tableau.c
auteur: Mathis FRIZOT Bernardo PEREIRA AUGUSTO
date : 14/10/2016
finalité: Modifier un tableau d'entiers
*/


/* Nom : afficheMenu
Finalité : affiche le menu
Paramètres entrant: Aucun
Paramètres entrant-sortant: Aucun
Valeur retourné: Aucune
Variables : Aucune
*/

void afficheMenu(void){
	printf("\tGestion des matières\n\n");
	printf("1\tAffichage\n");
	printf("2\tModification du coefficient d'une matière\n");
	printf("3\tCréation d'une matière\n");
	printf("4\tSuppression d'une matière\n");
	printf("5\tMoyenne des notes dans chaque matière\n");
	printf("6\tMoyennes d'un étudiant\n");
	printf("9\tQuitter\n");
}


/* Nom : menuMatieres
Finalité : Appel des autres fonctions pour modifier le tableau
Paramètres entrant: Aucun
Paramètres entrant-sortant: Aucun
Valeur retourné: Aucune
Variables :
	choix, choix de l'utilisateur pour la modification du fichier
	nbmat, entier représentant le nombre de matières
	tabM, tableau d'entier contenant le numéro de chaque matière
	tabC, tableau d'entier contenant le coefficient de chaque matière
*/

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
		}
	  	else if (choix==2){
			modif(tabM,tabC,nbmat);
	  	}
	  	else if (choix==3){
	  		nbmat=newmat(tabM,tabC,nbmat,TAILLE);
	  	}
	  	else if (choix==4){
	  		nbmat=suppr(tabM,tabC,nbmat);
	  	}
	  	else if (choix==5){
	  		moyenneN(tabM,nbmat);
	  	}
	  	// else if (choix==6){
	  	// 	moyenneE(tabM,tabC,nbmat);
	  	// }
  		printf("Quel est votre choix :");
  		scanf("%d",&choix);
	}
	save(tabM,tabC,nbmat);

}


/* Nom : chargement
Finalité : calcule le nombre de matières que comporte le fichier
Paramètres entrant:
	tailletab, Taille des tableau
Paramètres entrant-sortant:
 	tabM, tableau d'entier contenant le numéro de chaque matière
	tabC, tableau d'entier contenant le coefficient de chaque matière
Valeur retourné: i correspondant au nombre de matières ou -1 si le fichier n'a pas pu être ouvert
Variables :
	nomat, numéro de la matière
	coef, coefficient de la matière
	i, compteur
*/

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


/* Nom : affmat
Finalité : Affiche le fichier lu sous forme de tableau
Paramètres entrant: 
	nbmat, nombre de matières
Paramètres entrant-sortant:
 	tabM, tableau d'entier contenant le numéro de chaque matière
	tabC, tableau d'entier contenant le coefficient de chaque matière
Valeur retourné: Aucune
Variables :
	i, compteur
*/

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


/* Nom : recherche
Finalité : Recherche une matière par son numéro afin de la modifier
Paramètres entrant: 
	nbmat, nombre de matières
	val, numéro de la matière recherché
Paramètres entrant-sortant:
 	tab, tableau d'entier contenant le numéro de chaque matière
Valeur retourné: i, entier représentant la position de la matière recherchée dans le tableau si elle est trouvée ou -1 si la matière n'existe pas
Variables :
	i, compteur
*/

int recherche(int tab[],int nbmat,int val){
	int i;

	for (i=0; i<=nbmat; i++){
 		if (tab[i]==val){
			return i;
		}
		if (tab[i]>val)
			return i;
	}
	return i;
}


/* Nom : modif
Finalité : Modifie le coefficient d'une matière
Paramètres entrant: 
	nbmat, nombre de matières
Paramètres entrant-sortant:
 	tabM, tableau d'entier contenant le numéro de chaque matière
	tabC, tableau d'entier contenant le coefficient de chaque matière
Valeur retourné: Aucune
Variables :
	pos, position de la matière à modifier dans le tableau
	val, numéro de la matière recherchée
	newcoef, nouveau coefficient après modification
*/

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


/* Nom : save
Finalité : Sauvegarde les modifications afin de les enregistrés dans le fichier
Paramètres entrant: 
	nbmat, nombre de matières
Paramètres entrant-sortant:
 	tabM, tableau d'entier contenant le numéro de chaque matière
	tabC, tableau d'entier contenant le coefficient de chaque matière
Valeur retourné: Aucune
Variables :
	i, compteur
	*fs, fichier sur lequel va se faire la sauvegarde
*/

void save(int tabM[], int tabC[],int nbmat){
	FILE *fs;
	int i;

	fs=fopen("tableau.txt","w");
	for (i=0;i<nbmat;i++){
		fprintf(fs, "%d %d\n",tabM[i],tabC[i]);
	}
	fclose(fs);
}


/* Nom : newmat
Finalité : Crée une nouvelle matière
Paramètres entrant: 
	nbmat, nombre de matières
	tailletab, taille des tableaux afin de vérifier si une matière peut être créée ou si le tableau est plein
Paramètres entrant-sortant:
 	tabM, tableau d'entier contenant le numéro de chaque matière
	tabC, tableau d'entier contenant le coefficient de chaque matière
Valeur retourné: nbmat, nouveau nombre de matières
Variables :
	nomat, numéro de la nouvelle matière
	coef, coefficient de la nouvelle matière
	pos, position de la nouvelle matière dans les tableaux
*/

int newmat(int tabM[],int tabC[],int nbmat,int tailletab){
	int nomat,coef,pos;
	printf("Numéro de la nouvelle matière et Coefficient:");
	scanf("%d%d",&nomat,&coef);
	pos=recherche(tabM,nbmat,nomat);
	printf("%d %d\n",nomat,coef);
	if (pos<nbmat && tabM[pos]==nomat){
		printf("La matière existe déjà\n");
	}
	else
		if (nbmat==tailletab){
		printf("Le tableau est plein\n");
	}
		if (pos==nbmat){
		tabM[pos]=nomat;
		tabC[pos]=coef;
		nbmat++;
	}
		if (tabM[pos]!=nomat){
			decaler(tabM,pos,nbmat);
			decaler(tabC,pos,nbmat);
			tabM[pos]=nomat;
			tabC[pos]=coef;
			nbmat++;
		}
	return nbmat;
}


/* Nom : decaler
Finalité : Décaler le tableau pour ajouter une nouvelle matière
Paramètres entrant: 
	nbmat, nombre de matières
	pos, position de la matière que l'on veut insérer
Paramètres entrant-sortant:
 	tab, tableau d'entier
Valeur retourné: Aucune
Variables :
	i, compteur
*/

void decaler(int tab[],int pos,int nbmat){
	int i;
	for (i=nbmat;i>pos;i--){
		tab[i]=tab[i-1];
	}

}

/* Nom : suppr
Finalité : Supprime une matière
Paramètres entrant: 
	nbmat, nombre de matières
Paramètres entrant-sortant:
 	tabM, tableau d'entier contenant le numéro de chaque matière
	tabC, tableau d'entier contenant le coefficient de chaque matière
Valeur retourné: nbmat, Nouveau nombre de matières
Variables :
	i, compteur
	pos, position de la matière à supprimer
	nomat, numéro de la matière à supprimer
*/

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
		printf("N° de matière non trouvé\n");
	return nbmat;
}


void moyenneN(int tabM[],int nbmat){
	FILE *fe=fopen("moyenne.txt","r");
	int tabnbN[TAILLE]={0},noE,noM,pos,i;
	float tabcumN[TAILLE]={0},tabMoy[TAILLE],note;
	if (fe==NULL){
		return;
	}
	fscanf(fe,"%d%d%f",&noE,&noM,&note);
	while(feof(fe)==0){
		pos=recherche(tabM,nbmat,noM);
		tabnbN[pos]++;
		tabcumN[pos]=tabcumN[pos]+note;
		fscanf(fe,"%d%d%f",&noE,&noM,&note);
	}
	fclose(fe);
	printf("N° Matière\tMoyenne\n");
	for(i=0;i<nbmat;i++){
		tabMoy[i]=tabcumN[i]/tabnbN[i];
		if (tabMoy[i]==0)
			printf("%d\tpas de note\n",tabM[i]);
		else
			printf("%d\t%f\n",tabM[i],tabMoy[i]);
	}
}