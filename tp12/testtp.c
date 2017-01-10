#include "tp.h"

int main(void){
	Pays *tpays[100];
	int nbpays,i;

	nbpays=chargeFresult(tpays,100);
	affiche(tpays,nbpays);
	triselect(tpays,nbpays);
	printf("----------------------------------------------\n");
	affiche(tpays,nbpays);
	recherche(tpays,nbpays,"Etats-Unis");
	recherche(tpays,nbpays,"Chine");
	nbpays=miseajour(tpays,nbpays,"resdujour.don");
	printf("----------------------------------------------\n");
	affiche(tpays,nbpays);
	sauvegarde(tpays,nbpays);
	for(i=0;i<nbpays;i++){
		free(tpays[i]);
	}
	return 0; 
}