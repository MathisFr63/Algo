#include <stdio.h>
#include"exo1com.h"

void exo1(void){
	float comm,montant;
	montant=mont();
	comm=com(montant);
	affichage(comm);
}

float mont(void){
	float mv;
	printf("Montant des ventes :");
	scanf("%f",&mv);
	return mv;
}

float com(float mv){
	float com;
	if (mv<6000)
	com=0.05*mv;
	else if(mv<10001)
	com=300+0.08*(mv-6000);
	else
	com=300+320+0.1*(mv-10000);
	return com;
}

void affichage(float com){
	printf("Montant de la commission : %.2f\n",com);
}
