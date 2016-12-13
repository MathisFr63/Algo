#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ds.h"

Etudiant lireEtu(FILE* fe){
	Etudiant etu;
	fget(etu.nom,20,fe);
	if(etu.nom[strlen(etu.nom)-1]=='\n')
		etu.nom[strlen(etu.nom)-1]=='\0';
	fget(etu.prenom,20,fe);
	if(etu.prenom[strlen(etu.prenom)-1]=='\n')
		etu.prenom[strlen(etu.prenom)-1]=='\0';
	fscanf(fe,'%d %d %d',etu.naissance.jour,etu.naissance.mois,etu.naissance.annee);
	fscanf(fe,'%s',etu.etab);
	return etu;
}

void test (void){
	Etudiant etu;
	FILE *fe=fopen("etu.don","r");

	etu=lireEtu(fe);
	printf("nom : %s\nprénom : %s\n Date : %d/%d/%d\n Etablissement : %s",etu.nom,etu.prenom,etu.naissance.jour,etu.naissance.mois,etu.naissance.annee,etu.etab);
}