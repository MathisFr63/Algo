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

int rechVal(int tab[],int n,int val){
	if(n==0)
		return -1;
	if (tab[n-1]==val)
		return n-1;
	return rechVal(tab,n-1,val);
}

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

int rechMax(int tab[],int n){
	int res;
	if(n==1)
		return tab[0];
	res=rechMax(tab,n-1);
	if(tab[n-1]>res)
		return tab[n-1];
	return res;
}

int teststrlen(char mot[]){
	int taille=0;
	if(mot[0]!='\0'){
		taille=teststrlen(mot+1);
		return taille+1;
	}
	else
		return taille;
}

void copie(char mot2[],char mot1[]){
	if(mot1[0]!='\0'){
		mot2[0]=mot1[0];
		copie(mot2+1,mot1+1);
	}
	else
		mot2[0]='\0';
}

void concat(char tab1[],char tab2[],char tab3[]){
	if(tab1[0]!='\0'){
		tab3[0]=tab1[0];
		concat(tab1+1,tab2,tab3+1);
	}
	else if(tab2[0]!='\0'){
		tab3[0]=tab2[0];
		concat(tab1+1,tab2+1,tab3+1);
	}
	else
		tab3[0]='\0';
}

int comparaison(char tab1[],char tab2[]){
	int i;
	if(tab1[0]==tab2[0]){
		if(tab1[0]!='\0'){
			i=comparaison(tab1+1,tab2+1);
			return i;
		}
		else{
			return 0;
		}
	}
	else{
		if(tab1[0]<tab2[0]){
			return -1;
		}
		else{
			return 1;
		}
	}
}