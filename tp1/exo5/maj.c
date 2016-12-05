#include <stdio.h>
#include"maj.h"

/*programme: maj.c
auteur : FRIZOT Mathis et PEREIRA AUGUSTO Bernardo
date : 09/09/2016
finalité : obtenir la majuscule et sa valeur ASCII correspondante d'une lettre minuscule
*/

void maj(void){
  char carac,caracM;
  printf("saisir un unique caractère en minuscule : \n");
  carac=getchar();
  printf("le caractère lu est :%c\n",carac);
  printf("la valeur ASCII correspondante est : %d\n",carac);
  caracM=carac-32;
  printf("le caractère en majuscule correspondant est : %c de valeur ASCII : %d\n",caracM,caracM);
}
