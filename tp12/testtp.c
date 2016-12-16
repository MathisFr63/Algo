#include <stdio.h>
#include "tp.h"

int main(void){
	Pays *tpays[100];
	int nbPays;

	nbPays=chargeFresult(tpays,100);
	printf("%d\n",nbPays);
	affiche(tpays,nbPays);
	return 0; 
}