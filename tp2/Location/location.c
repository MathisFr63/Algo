/*programme : Location.c
auteur: Mathis FRIZOT Bernardo PEREIRA AUGUSTO
date : 16/09/2016
finalité: Gestion des différentes prestations d'un complexe hôtelier
*/

#include<stdio.h>
#include"location.h"

/* Nom : Location de la salle
Finalité : Affiche le montant de la prestation
Variables :
catS caractère lu au clavier
deco caractère lu au clavier
prix prix de la location afficher
*/

void location(void){
  char catS,deco;
  float prixA=1500,prixB=1000,prixC=700,pourcent=0.1,prix;
  printf("Location de la salle\n");
  printf("Catégorie de salle : ");
  scanf("%c%*c",&catS);
  printf("Décoration (O/N) : ");
  scanf("%c%*c",&deco);
  if (catS=='A')
    prix=prixA;
  else if (catS=='B')
    prix=prixB;
  else if (catS=='C')
    prix=prixC;
  else
    printf("Erreur de catégorie!\n");
  if (deco=='O')
    prix=prix+prix*pourcent;
  else 
  printf("Le montant de la prestation sera de : %.2f\n\n",prix);
}


/* Nom : Apéritif
Finalité : Affiche le montant de la prestation
Variables :
nbP Nombre de personnes lu au clavier
formule caractère lu au clavier
prixApero prix total afficher
*/

void aperitif(void){
  int nbP;
  char formule;
  float Unite=12,Buffet1=300,Buffet2=500,Buffet3=800,service=50,prixApero;
  printf("Apéritif\n");
  printf("Nombre de personnes : ");
  scanf("%d%*c",&nbP);
  printf("Formule (U/B) : ");
  scanf("%c%*c",&formule);
 
  if (formule=='U')
    prixApero=nbP*Unite+service;
  else if(formule=='B')
    if(nbP<=50)
      prixApero=Buffet1+service;
    else if (nbP<=100)
      prixApero=Buffet2+service;
    else
      prixApero=Buffet3+service;
  printf("Montant de la prestation : %.2f\n",prixApero);
}


/* Nom : Banquet
Finalité : Affiche le montant de la prestation
Variables :
nbP Nombre de personnes lu au clavier
menu caractère lu au clavier
prix prix total afficher
*/

void banquet(void){
  int nbP;
  char menu;
  float prixB;
  printf("Banquet\n");
  printf("Nombre de personnes : ");
  scanf("%d%*c",&nbP);
  printf("Menu identique (O/N) : ");
  scanf("%c%*c",&menu);
  if (menu=='O')
    if (nbP>80)
      prixB=26*(nbP-80)+50*27+20*28+10*30;
    else if (nbP>30)
      prixB=27*(nbP-30)+20*28+10*30;
    else if (nbP>10)
      prixB=28*(nbP-10)+10*30;
    else if (nbP>0)
      prixB=nbP*30;
    else
      printf("erreur\n");
  else if (menu=='N')
    prixB=nbP*33;
  else
    printf("Erreur de Menu\n");
  printf("Montant de la prestation : %.2f\n",prixB);
}

/* Nom : Etude globale
Finalité : Appel les fonctions Apéritif et Banquet
Variables :
apero caractère lu au clavier
banq caractère lu au clavier
*/

void globale(void){
  char apero,banq;
  printf("Voulez-vous un apéritif ? (O/N) ");
  scanf("%c%*c",&apero);
  printf("Voulez-vous un banquet ? (O/N) ");
  scanf("%c%*c",&banq);
  location();
  if (apero=='O')
    aperitif();
  else
    printf("Pas d'apéritif\n");
  if (banq=='O')
    banquet();
  else
    printf("Pas de Banquet\n");
}
