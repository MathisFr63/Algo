#include <stdio.h>
#include"exo4.h"

void exo(void){
	int Clermont,nbE;
	float prixe1,Prix;
	nbE=nbe();
	Clermont=clermont();
	Prix=prix(nbE,Clermont);
	affichage(Prix);
}
 
int nbe(void){
	int nbenfants;
	printf("Nombre d'enfants :");
	scanf("%d%*c",&nbenfants);
	return nbenfants;
}

float prixE1(int Clermont){
	float prixE1;
	if (Clermont==1)
	prixE1=70;
	if (Clermont==2)
	prixE1=60;
	if (Clermont==3)
	prixE1=50;
	return prixE1;
}

int clermont(void){
	char clermontFD,qf;
	int clerm;
	printf("Clermontois (O/N) ?");
	scanf("%c%*c",&clermontFD);
	if (clermontFD=='O'){
	printf("Quotient Familial :");
	scanf("%c%*c",&qf);
	if (qf<6000)
	clerm=3;
	else
	clerm=2;
	}
	else
	clerm=1;
	return clerm;
}

float prix(int nbE, int Clermont){
	float prix;
	if (nbE==1)
	prix=prixE1(Clermont);
	if (nbE==2)
	prix=prix+prixE1(Clermont)*0.9;
	else if (nbE>2)
	prix=prix+prixE1(Clermont)*0.9+((nbE-2)*(prixE1(Clermont)*0.8));
	return prix;
}

void affichage(float Prix){
	printf("Le montant à payer sera de : %.2f\n",Prix);
}
