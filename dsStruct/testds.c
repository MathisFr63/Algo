#include "ds.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
	Etudiant *tEtu;
	Chambre tabChambre[50];
	int nbChambres,nbEt,nbEIUT,i;

	tEtu=ChargeEtudiants("fétudiants.don",&nbEt);
	nbChambres=charger(tabChambre,50);
	printf("Nom\tPrénom\t\tDate de naissance\tEtablissement\tChambre\n");
	for(i=0;i<nbEt;i++){
		afficheT(tEtu[i]);
	}
	nbEIUT=nbIUT(tEtu,nbEt);
	affChamb(tabChambre,'A','8',nbChambres);
	suppr("Dupond","Arthur",tabChambre,nbChambres,tEtu,&nbEt);
	sauveTEtudiants(tEtu,"fétudiants.bin",nbEt);
	free(tEtu);
	return 0;
}