#include <stdio.h>
#include"typechar.h"

/*programme: typechar.c
auteur : FRIZOT Mathis et PEREIRA AUGUSTO Bernardo
date : 09/09/2016
finalité : obtenir la valeur ASCII d'une lettre
*/

void typechar(void){
  char carac;
  printf("saisir un unique caractère en minuscule : \n");
  carac=getchar();
  printf("le caractère lu est :%c\n",carac);
  printf("la valeur ASCII correspondante est : %d\n",carac);
}
