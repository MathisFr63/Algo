/*programme : hotel.c
auteur: Mathis FRIZOT Bernardo PEREIRA AUGUSTO
date : 23/09/2016
finalité: Gestion des différentes prestations d'un complexe hôtelier
*/

#include <stdio.h>
#include"hotel.h"

/* Nom : globale
Finalité : calcul du prix total
Paramètres: Aucun
Valeur retourné: Aucune
Variables :
	aperitif, caractère lu au clavier
	coutS, cout de la location de la salle
	coutA, cout de l'apéritif
	coutT, cout de l'ensemble des prestations
*/

void globale(void){
	char aperitif;
	float coutS,coutA,coutT;
	printf("Voulez-vous un apéritif (O/N) ?");
	scanf("%c%*c",&aperitif);
	
	coutS=LocationSalle();
	if (aperitif=='O'){
		coutA=apero();
		coutT=coutS+coutA;
		printf("Location de salle :\t%.2f\nApéritif :\t\t %.2f\nTotal :\t\t\t%.2f\n",coutS,coutA,coutT);
	}
	else
	printf("Total : %.2f\n",coutS,coutS);
}

/* Nom : LocationSalle
Finalité : Appel des fonctions pour calculer le montant de la location d'une salle 
Paramètres: Aucun
Valeur retourné: CoutS
Variables :
   cate, caractère lu au clavier
   deco, caractère lu au clavier
   apero, caractère lu au clavier
   coutS, cout de la location
*/

float LocationSalle(void){
	char cate,deco,apero;
	float coutS;
	
	saisirLocSalle(&cate,&deco);
	coutS=salle(cate,deco);
	
	return coutS;
}

/* Nom : salle
Finalité : calcul le montant de la prestation
Paramètres: cate, deco
Valeur retourné: cout
Variables :
cout, cout de la location
*/

float salle (char cate,char deco){
	float cout;
	
	if (cate=='A')
		cout=1500;
	else if (cate=='B')
		cout=1000;
	else
		cout=700;
	if (deco=='O')
		cout=cout*1.1;
		
    return cout;
}
	
/* Nom : saisirLocSalle
Finalité : Demande la catégorie de la salle et si l'on veut une décoration
Paramètres : Aucun
Paramètres entrant sortant : *cate, *deco
Valeur retourné: Aucune
Variables : Aucune
*/	
	
void saisirLocSalle(char *cate,char *deco){
	printf("Catégorie de la salle (A/B/C) : ");
	scanf("%c%*c",cate);
	printf("Décoration (O/N) ?");
	scanf("%c%*c",deco);
}

/* Nom : apero
Finalité : Appel des fonctions pour calculer le montant de l'apéritif
Paramètres: aucun
Valeur retourné: coutA
Variables :
	formule, cractère lu au clavier
	nbP, nombre lu au clavier
	coutA, cout de l'apéritif
*/

float apero(void){
	char formule;
	int nbP;
	float coutA;
	
	saisirApero(&formule,&nbP);
	coutApero(formule,nbP,&coutA);
	
	return coutA;
}

/* Nom : coutApero
Finalité : calcul le montant de l'aperitif
Paramètres: nbP, formule
Paramètres entrant sortant : *coutA
Valeur retourné: Aucune
Variables :
     Unite, prix d'un apéritif à l'unité
     Buffet1, prix d'un apéritif en forfait pour moins de 51 personnes
     Buffet2, prix d'un apéritif en forfait pour entre 51 et 100 personnes
     Buffet3, prix d'un apéritif en forfait pour plus de 100 personnes
     service, prix du service
*/

void coutApero(char formule,int nbP, float *coutA){
	float service=50,Unite=12,Buffet1=300,Buffet2=500,Buffet3=800;
	if (formule=='U')
		*coutA=nbP*Unite;
	else if(formule=='B')
    if(nbP<=50)
		*coutA=Buffet1;
    else if (nbP<=100)
		*coutA=Buffet2;
    else
		*coutA=Buffet3;
  
  *coutA=*coutA+service;
}

/* Nom : saisirApero
Finalité : Demande la formule et le nombre de personnes
Paramètres : Aucun
Paramètres entrant sortant : *formule, *nbP
Valeur retourné: Aucune
Variables : Aucune
*/	

void saisirApero(char *formule,int *nbP){
	  printf("Formule (U/B) :");
	  scanf("%c%*c",formule);
	  printf("Nombre de personnes : ");
	  scanf("%d%*c",nbP);
  }
