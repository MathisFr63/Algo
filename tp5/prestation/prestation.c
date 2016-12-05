#include <stdio.h>
#include"prestation.h"

/*programme : prestation.c
auteur: Mathis FRIZOT Bernardo PEREIRA AUGUSTO
date : 07/10/2016
finalité: Statistiques de prestations hôtelières
*/


/* Nom : globale
Finalité : affiche les statistiques de l'hôtel
Paramètres entrant: Aucun
Paramètres entrant-sortant: Aucun
Valeur retourné: Aucune
Variables :
	numrecep, Numéro de la réception lu dans le fichier texte
	n, nombre de réceptions ayant les trois prestations
	cLoc, coût total d'une réception
	salle, coût total des locations de salles
	cMax, coût maximal parmis les réceptions
	cMoy, moyenne des réceptions qui présentent les trois prestations
	cSalle, coût d'une salle lu dans le fichier texte
	cApero, coût d'un apéritif lu dans le fichier texte
	cBanquet, coût d'un banquet lu dans le fichier texte
	som, somme des coûts de location des réceptions présentant les trois prestations (afin de faire une moyenne)
*/


void globale(void){
	FILE *fe;
	int numrecep,n=0;
	float cLoc,salle=0,cMax=0,cMoy=0,cSalle,cApero,cBanquet,som=0;
	
	
	fe=fopen("reception.txt","r");
	if (fe==NULL){
		printf("Ouverture du fichier impossible\n");
	}
	else{
		fscanf(fe,"%d%f%f%f",&numrecep,&cSalle,&cApero,&cBanquet);
		while (feof(fe)==0){
			salle=salle+cSalle;
			cLoc=cSalle+cApero+cBanquet;
			if (cLoc>cMax)
				cMax=cLoc;
			if (cSalle !=0 && cApero !=0 && cBanquet !=0){
				cLoc=cSalle+cApero+cBanquet;
				som=som+cLoc;
				n++;
			}
			fscanf(fe,"%d%f%f%f",&numrecep,&cSalle,&cApero,&cBanquet);
		}
		fclose(fe);
		
		
		printf("Le montant total des locations de salle est : %.2f\n",salle);
		printf("Le coût de la réception la plus coûteuse est : %.2f €\n",cMax); 
		if (n==0)
			printf("Aucune réception ne présente les trois prestations\n");
		else{
			cMoy=som/n;
			printf("Le coût moyen des réceptions sui présentent les trois prestations est de : %.2f\n",cMoy);
		}
	}
}
