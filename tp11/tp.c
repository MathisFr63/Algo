#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"

/*programme : tp.c
auteur: Mathis FRIZOT Bernardo PEREIRA AUGUSTO
date : 09/12/2016
finalité: Récusivité
*/

/* Nom : nbSegment
Finalité : Calcule du nombre de segments obtenus lorque tout les points d'un cercle sont reliés entre eux
Paramètres entrant: n,nb de points sur le cercle
Paramètres entrant-sortant: Aucun
Valeur retourné: nombre de segments
Variables : Aucune
*/

int nbSegment(int n){
	if (n==1)
		return 0;
	return nbSegment(n-1)+(n-1);

}

/* Nom : rechVal
Finalité : recherche d'une valeur dans un tableau d'entiers
Paramètres entrant: n, taille physique du tableau
val, valeur recherchée
Paramètres entrant-sortant: tab, tableau d'etier
Valeur retourné: position de la valeur recherchée dans le tableau ou -1 si la valeur n'a pas était trouvée
Variables : Aucune
*/

int rechVal(int tab[],int n,int val){
	if(n==0)
		return -1;
	if (tab[n-1]==val)
		return n-1;
	return rechVal(tab,n-1,val);
}

/* Nom : rechProche
Finalité : recherche de la valeur la plus poche de la valeur recherchée dans un tableau d'entier
Paramètres entrant: n, taille physique du tableau d'entier
val, valeur recherchée
Paramètres entrant-sortant: tab, tableau d'entiers
*pos, position de la valeur la plus proche dans le tableau
Valeur retourné: res, valeur la plus proche de la valeur recherchée
Variables : res, valeur la plus proche de la valeur recherchée
*/

int rechProche(int tab[],int n,int val,int *pos){
	int res;
	if(n==1){
		return tab[0];
		*pos=0;
	}
	res=rechProche(tab,n-1,val,pos);
	if (abs(tab[n-1]-val)<abs(res-val)){
		*pos=n-1;
		return tab[n-1];
	}
	return res;
}

/* Nom : rechMax
Finalité : recherche du plus grand entier d'un tableau d'entier
Paramètres entrant: n, taille physique du tableau d'entier
Paramètres entrant-sortant: tab, tableau d'entier
Valeur retourné: res, valeur du plus grand entier du tableau
Variables : res, valeur du plus grand entier du tableau
*/

int rechMax(int tab[],int n){
	int res;
	if(n==1)
		return tab[0];
	res=rechMax(tab,n-1);
	if(tab[n-1]>res)
		return tab[n-1];
	return res;
}

/* Nom : teststrlen
Finalité : calcule de la longueur d'un chaîne de caractères
Paramètres entrant: Aucun
Paramètres entrant-sortant: mot, tableau de caractères dont on veut connaître la taille
Valeur retourné: taille, taille du tableau 
Variables : taille, taille du tableau
*/

int teststrlen(char mot[]){
	int taille=0;
	if(mot[0]!='\0'){
		taille=teststrlen(mot+1);
		return taille+1;
	}
	else
		return taille;
}

/* Nom : copie
Finalité : copie la chaîne de cractère d'un tableau dans un autre
Paramètres entrant: Aucun
Paramètres entrant-sortant: mot2, destination de la copie
mot1, source de la copie
Valeur retourné: Aucune
Variables : Aucune
*/

void copie(char mot2[],char mot1[]){
	if(mot1[0]!='\0'){
		mot2[0]=mot1[0];
		copie(mot2+1,mot1+1);
	}
	else
		mot2[0]='\0';
}

/* Nom : concat
Finalité : concatène 2 tableau comportant des chaînes de caractères dans un seul tableau
Paramètres entrant: Aucun
Paramètres entrant-sortant: mot1, premier tableau comportant une chaîne de caractères
mot2, deuxième tableau comportant une chaîne de caractères
mot3, tableau dans le quel vont être concaténer les 2 tableaux précédents
Valeur retourné: Aucune
Variables : Aucune
*/

void concat(char mot1[],char mot2[],char mot3[]){
	if(mot1[0]!='\0'){
		mot3[0]=mot1[0];
		concat(mot1+1,mot2,mot3+1);
	}
	else if(mot2[0]!='\0'){
		mot3[0]=mot2[0];
		concat(mot1+1,mot2+1,mot3+1);
	}
	else
		mot3[0]='\0';
}

/* Nom : comparaison
Finalité : compare deux chaînes de caractères
Paramètres entrant: Aucun
Paramètres entrant-sortant: mot1, première chaîne de caractères
mot2, deuxième chaîne de caractères
Valeur retourné: i, valeur de la comparaison : 
	0 si les mots sont identiques
	1 si le mot 1 est supérieur au mot 2 (dans le dictionnaire)
	-1 si le mot 1 est inférieur au mot 2
Variables : i, valeur de la comparaison
*/

int comparaison(char mot1[],char mot2[]){
	int i;
	if(mot1[0]==mot2[0]){
		if(mot1[0]!='\0'){
			i=comparaison(mot1+1,mot2+1);
			return i;
		}
		else{
			return 0;
		}
	}
	else{
		if(mot1[0]<mot2[0]){
			return -1;
		}
		else{
			return 1;
		}
	}
}



// Cette fonction ne fonctionne pas correctement et n'est pas terminée

int baguenaudier(int *tab,int n,int *i,int *j){
	printf("i = %d | n= %d\n",*i,n);
	// Probleme lorsque tab[n-1]=n pour toutes les cases (exemples : tab[5]={1,2,3,4,5}) 
	// --> la fonction renvoi *i=0 tout le temps même si les cases ont un pion et se termine 
	// donc en disant que le pion peut être poser ou enlever
	if(tab[n-1]==n && tab[n-2]==n-1){
		*i=0;
		n=n-1;
	}
	if(n>1 && *i==0){
		baguenaudier(tab,n-1,i,j);
		if(tab[n-2]==0 && *j==1)
			return;
		else{
			*j=-1;
			*i=-1;
		}
	}
	if(*i==0){
		printf("On peut enlever le pion car la case immédiatement à gauche a un pion et c'est le seul pion à gauche\n");
		// Ici tab[n-1] (où n vaut 5 si on résoud un baguenaudier à 5 points)
		//sera modifier et vaudra maintenant 0 ce qui veut dire qu'il n'y a pas de pion dans la case
	}
}