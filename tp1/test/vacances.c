#include <stdio.h>
#include"vacances.h"

void vacances(void){
  int clerm,nbE;
  float prix,quoF;
  printf("clermontois : ");
  scanf("%d",&clerm);
  printf("nombre d'enfants : ");
  scanf("%d",&nbE);
  printf("quotient familial : ");
  scan("%f",&quoF);
  if (clerm==0)
    prix=70;
  else
    if (quoF>=6000)
      prix=60;
    else
      prix=50;
  if (nbE>1)
    if (nbE==2)
    prix=prix+(prix-prix*0.1);
  else
    prix=prix+(prix-prix*0.1)+(nbE-2)*(prix-prix*0.2);
  printf("Le prix à payer est de : %.2f\n",prix);
}
