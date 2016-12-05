/*programme : hotel.c
auteur: Mathis FRIZOT Bernardo PEREIRA AUGUSTO
date : 23/09/2016
finalité: Gestion des différentes prestations d'un complexe hôtelier
*/

#include<stdio.h>
#include"hotel.h"


/* Nom : coutsalle
Finalité : calcul le montant de la prestation
Paramètres: cate, deco
Valeur retourné: cout
Variables :
cout, cout de la location afficher
*/

float coutsalle(char cate, char deco){
  float cout;
  
  if (cate=='A')
    cout=1500;
  if (cate=='B')
    cout=1000;
  if (cate=='C')
    cout=700;
  if (deco=='O')
    cout=cout*1.1;
  
  return cout;
}

/* Nom : prixApero
Finalité : calcul le montant de l'aperitif
Paramètres: nbP, formule
Valeur retourné: prix
Variables :
     prix, cout de l'apéritif afficher
     Unite, prix d'un apéritif à l'unité
     Buffet1, prix d'un apéritif en forfait pour moins de 51 personnes
     Buffet2, prix d'un apéritif en forfait pour entre 51 et 100 personnes
     Buffet3, prix d'un apéritif en forfait pour plus de 100 personnes
     service, prix du service
*/

float prixApero(int nbP, char formule){
  float prix,Unite=12,Buffet1=300,Buffet2=500,Buffet3=800,service=50;
  
  if (formule=='U')
    prix=nbP*Unite;
  else if(formule=='B')
    if(nbP<=50)
      prix=Buffet1;
    else if (nbP<=100)
      prix=Buffet2;
    else
      prix=Buffet3;
  
  prix=prix+service;
  return prix;
}

/* Nom : hotel
Finalité : calcul du prix total
Paramètres: Aucun
Valeur retourné: Aucunce
Variables :
	apero, caractère lu au clavier
	cate, caractère lu au clavier
	depo, caractère lu au clavier
	formule, cractère lu au clavier
	nbP, nombre lu au clavier
	coutS, cout de la location de la salle
	coutA, cout de l'apéritif
	coutT, cout de l'ensemble des prestations
*/

void hotel(void){
  char apero,cate,deco,formule;
  int nbP;
  float coutS, coutA=0, coutT;
  
  printf("Catégorie de la salle (A/B/C) : ");
  scanf("%c%*c",&cate);
  printf("Decoration (O/N) :");
  scanf("%c%*c",&deco);
  
  coutS=coutsalle(cate, deco);
  printf("Voulez-vous un apéritif (O/N) : ");
  scanf("%c%*c",&apero);
  
  if (apero=='O'){
	  printf("Formule (U/B) :");
	  scanf("%c%*c",&formule);
	  printf("Nombre de personnes : ");
	  scanf("%d%*c",&nbP);
  
	  coutA=prixApero(nbP,formule);
  }
  
  coutT=coutS+coutA;
  
  printf("Location de salle :\t %.2f \nApéritif :\t\t %.2f \nTotal :\t\t\t %.2f \n",coutS, coutA, coutT);
}
