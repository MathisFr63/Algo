#include <stdio.h>
#include"multi.h"


/*programme : multi.c
auteur: Mathis FRIZOT Bernardo PEREIRA AUGUSTO
date : 07/10/2016
finalité: Afficher une table de multiplication
*/


/* Nom : tableMult
Finalité : affiche la table de multiplication pour le nombre m
Paramètres entrant: m, nombre dont on veut la table de multiplication
Paramètres entrant-sortant: Aucun
Valeur retourné: Aucune
Variables :
	i, multiplicateur de 1 à 9
*/

void tableMult(int m){
	int i=1;
	printf("Table de multiplication par %d\n",m);
	while (i <= 9){
		printf("%d*%d = %d\n",m,i,m*i);
		i++;
	}
}

/* Nom : entierDe1A9
Finalité : retourne l'entier dont on veut la table de multiplication
Paramètres entrant: Aucun
Paramètres entrant-sortant: Aucune
Valeur retourné: entier
Variables :
	entier, entier dont on veut la table de multiplication
*/
	
int entierDe1A9(void){
	int entier;
	printf("Taper un entier compris entre 1 et 9 :");
	scanf("%d",&entier);
	while (entier<1 || entier>9){
		printf("La valeur doit être comprise entre 1 et 9; retaper :");
		scanf("%d",&entier);
	}
	return entier;
}

/* Nom : globale
Finalité : appel des autres fonctions pour afficger la table de multiplication
Paramètres entrant: Aucun
Paramètres entrant-sortant: Aucun
Valeur retourné: Aucune
Variables :
	m, entier dont on veut la table de multiplication
*/

void globale(void){
	int m;
	m=entierDe1A9();
	tableMult(m);
}
