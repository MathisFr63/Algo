#include <stdio.h>
#include"exo2.h"

void exo(void){
	int nb,nbpaq;
	float prix,couts;
	nb=nbL();
	prix=prixL();
	nbpaq=paquet(nb);
	couts=cout(nb,prix);
	affichage(couts,nbpaq);
}

float fEnv(int nbL){
	float fenv;
	if (nbL<=6)
	fenv=7;
	else if (nbL<=12)
	fenv=12;
	else
	fenv=16;
	return fenv;
}

int paquet(int nbL){
	int paq;
	paq=nbL/3;
	if (nbL%3 !=0)
	paq++;
	return paq;
}

float cout(int nbL,float prixL){
	float cout,fenv;
	fenv=fEnv(nbL);
	cout=fenv+prixL*nbL;
	return cout;
}
void affichage(float cout,int paq){
	printf("Le coût de la commande sera de : %.2f\n",cout);
	printf("Il faut expédier %d paquets\n",paq);
}

int nbL(void){
	int nbL;
	printf("Nombre de livres :");
	scanf("%d",&nbL);
	return nbL;
}

float prixL(void){
	float prixL;
	printf("Prix d'un livre :");
	scanf("%f",&prixL);
	return prixL;
}
