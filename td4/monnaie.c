#include <stdio.h>
#include"monnaie.h"

void saisir(int *valAchat,int *somme){
	printf("Valeur des achat : ");
	scanf("%d",valAchat);
	printf("Somme donnée à la caissière : ");
	scanf("%d",somme);
}

int monnaieRendue(int valAchat, int somme,int *billets10,int *billet5,int *pieces2,int *piece1){
	int monnaieR;
	monnaieR=somme-valAchat;
	*billets10=monnaieR/10;
	*billet5=(monnaieR%10)/5;
	*pieces2=(monnaieR%5)/2;
	*piece1=(monnaieR%2);
	return monnaieR;
}

void afficher(int MonnaieR,int billets10,int billet5,int pieces2,int piece1){
	printf("Monnaie à rendre : %d€\n", MonnaieR);
	printf(" %d Billets de 10€\n %d Billet de 5€\n %d Pièces de 2€\n %d Pièce de 1€\n",billets10,billet5,pieces2,piece1);
}

void rendreMonnaie(void){
	int monnaie,somme,Achat,billets10,billet5,pieces2,piece1;
	saisir(&Achat,&somme);
	monnaie=monnaieRendue(Achat,somme,&billets10,&billet5,&pieces2,&piece1);
	afficher(monnaie,billets10,billet5,pieces2,piece1);
}
	
