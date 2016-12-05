#include <stdio.h>
#include"bonjour.h"

/*programme: bonjour.c
auteur : FRIZOT Mathis PEREIRA AUGUSTO Bernardo
date : 09/09/2016
finalité : afficher bonjour à l'écran
*/

void affichBonjour(void){
  printf("Bonjour\n");
  
}

void affichBonjour1(void){
  int annee;
  printf("Année en cours : ");
  scanf("%d",&annee);
  printf("Bonjour %d\n",annee);
  
}
