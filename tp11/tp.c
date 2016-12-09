#include "tp.h"

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

int comparaisonint(int tab1[],int tab2[],int n){
	int i;
	if(n==1)
		if(tab1[0]==tab2[0])
			return 1;
		else
			return -1;
	i=comparaison(tab1,tab2,n-1);
	if(i<0)
		return -1;
	if(tab1[n-1]==tab2[n-1])
		return 1;
}

int teststrlen(char mot[],int n){
	int taille;
	if(n==1)
		return 1;
	taille=teststrlen(mot,n-1);
	if(mot[n-1]!='\0'){
		return taille+1;
	}
	return taille;
}

void copie(char mot1[],char mot2[],int n){
	if(n==1){
		mot2[0]=mot1[0];
		return;
	}
	copie(mot1,mot2,n-1);
	if(mot1[n-1]=='\0')
		mot2[n-1]='\0';
	mot2[n-1]=mot1[n-1];
}

void concat(char tab1[],char tab2[],int n){
	
}

int comparaison(char tab1[],char tab2[],int n){
	int i;
	if(n==1)
		if(tab1[0]==tab2[0])
			return 1;
		else
			return -1;
	i=comparaison(tab1,tab2,n-1);
	if(i<0)
		return -1;
	if(tab1[n-1]==tab2[n-1])
		return 1;

void globale (void){

}