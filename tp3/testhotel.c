#include<stdio.h>
#include"hotel.h"

/* Nom : testCoutSalle
Finalité : Affiche le montant de la location d'une salle 
Paramètres: Aucun
Valeur retourné: Aucune
Variables :
   cate, caractère lu au clavier
   deco, caractère lu au clavier
   coutS, cout de la location afficher
   apero, caractère lu au clavier
*/

void testCoutSalle(void){
  char cate, deco, apero;
  float coutS,coutA;
  
  printf("Catégorie de la salle (A/B/C) : ");
  scanf("%c%*c",&cate);
  printf("Decoration (O/N) :");
  scanf("%c%*c",&deco);
  
  coutS=coutsalle(cate, deco);
  printf("%.2f\n",coutS);
}

/* Nom : testPrixApero
Finalité : Affiche le montant de la prestation
Paramètres: aucun
Valeur retourné: aucune
Variables :
*/

void testPrixApero(void){
  int nbP;
  float prixA;
  char formule;
  
  printf("Formule (U/B) :");
  scanf("%c%*c",&formule);
  printf("Nombre de personnes : ");
  scanf("%d%*c",&nbP);
  
  prixA=prixApero(nbP,formule);
  printf("%.2f\n",prixA);
}

int main(void){
  //testCoutSalle();
  //testPrixApero();
  hotel();
  return 0;
}
