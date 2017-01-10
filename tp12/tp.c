#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp.h"


/*programme : tp.c
auteur: Mathis FRIZOT Bernardo PEREIRA AUGUSTO
date : 16/12/2016
finalité: Mise à jour des résultats des Jeux Olympiques
*/

/* Nom : chargeFresult
Finalité : Charge les données d'un fichier dans un tableau
Paramètres entrant: nbmax, nombres maximal de Pays
Paramètres entrant-sortant: *tpays[], tableau de pointeur pointant sur des pays
Valeur retourné: nombre de pays
Variables : int, compteur
pay, pays
*/
int chargeFresult(Pays *tpays[], int nbmax){
	FILE *fe=fopen("joresult.don","r");
	int i=0;
	Pays pay;

	if(fe==NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		exit(1);
	}
	fscanf(fe,"%s %d %d %d",pay.nom,&pay.nbmo,&pay.nbma,&pay.nbmb);
	while(feof(fe)==0){
		if(i>=nbmax){
			printf("Erreur tableau trop petit\n");
			return -1;
		}
		tpays[i]=(Pays *)malloc(sizeof(Pays));
		if(tpays[i]==NULL){
			printf("Problème d'allocation mémoire\n");
			exit(1);
		}
		pay.nbtm=pay.nbmo+pay.nbma+pay.nbmb;
		*tpays[i]=pay;
		i++;
		fscanf(fe,"%s %d %d %d",pay.nom,&pay.nbmo,&pay.nbma,&pay.nbmb);
	}
	fclose(fe);
	return i;
}

/* Nom : rechmin
Finalité : recherche de la chaîne de caractère la plus petite (dans l'alphabet) et renvoi sa position
Paramètres entrant: nbpays, nombre pays
Paramètres entrant-sortant: *tpays[], tableau de pointeur pointant sur des Pays
Valeur retourné: pos, position de la chaîne de caractère la plus petite
Variables : i, compteur
*/

int rechmin(Pays *tpays[],int nbpays){
	int i,pos=0;

	for(i=1;i<nbpays;i++){
		if(strcmp(tpays[i]->nom,tpays[pos]->nom)<0)
			pos=i;
	}
	return pos;
}

/* Nom : triselect
Finalité : tri alphabétique d'un tableau de pointeurs
Paramètres entrant: nbpays, nombre de pays
Paramètres entrant-sortant: *tpays[], tableau de pointeur pointant sur des pays
Valeur retourné: Aucune
Variables : pos, position de la chaîne de caractère la plus petite
i, compteur
*tmp, pointeur pointant sur un pays
*/

void triselect(Pays *tpays[],int nbpays){
	int pos,i;
	Pays *tmp;

	for(i=0;i<nbpays;i++){
		pos=rechmin(tpays+i,nbpays-i)+i;
		if(i!=pos){
			tmp=tpays[i];
			tpays[i]=tpays[pos];
			tpays[pos]=tmp;
		}
	}
}

/* Nom : affiche
Finalité : affiche le contenu d'un tableau
Paramètres entrant: nb, nombre de pays
Paramètres entrant-sortant: **tpays, tableau de pointeur pointant sur des pays
Valeur retourné: Aucune
Variables : i, compteur
*/

void affiche (Pays **tpays,int nb){
	int i;

	printf("Nom\t\tOr\tArgent\tBronze\tTotal\n");
	for(i=0;i<nb;i++){
		if(strlen(tpays[i]->nom) > 7)
	 		printf("%s\t%d\t%d\t%d\t%d\n",tpays[i]->nom,tpays[i]->nbmo,tpays[i]->nbma,tpays[i]->nbmb,tpays[i]->nbtm);
	 	else 
			printf("%s\t\t%d\t%d\t%d\t%d\n",tpays[i]->nom,tpays[i]->nbmo,tpays[i]->nbma,tpays[i]->nbmb,tpays[i]->nbtm);

	}
}

/* Nom : recherche
Finalité : recherche de position d'insertion d'une chaîne de caractère dans l'ordre alphabétique
Paramètres entrant: nb , nombre de pays
Paramètres entrant-sortant: *nom, chaîne de caractère contenant le nom du pays recherché
*tpays[], tableau de pointeur pointant sur des pays
Valeur retourné: m, position d'insertion ou deb lorque m=deb=fin
Variables : deb, position de départ dans le tableau
fin position de fin dans le tableau
*/

int recherche(Pays *tPays[],int nb,char *nom){
	int deb=0,fin=nb-1,m,comp;

	while(deb<=fin){
		m=(deb+fin)/2;
		comp=strcmp(nom, tPays[m]->nom);
		if(comp==0)
			return m;
		else if(comp<0)
			fin=m-1;
		else
			deb=m+1;
	}
	return deb;
}

/* Nom : miseajour
Finalité : Met à jour le tableau de pointeurs afin de mettre à jour les résultats des Jeux Olympiques
Paramètres entrant: nbpays, nombre de pays
Paramètres entrant-sortant: *nomFich, nom du fichier dans lequel sont stockées les résultats de la journée
*tpays[], tableau de pointeur pointant sur des pays
Valeur retourné: nbpays, nombre de pays après mise à jour
Variables : pos, position d'insertion dans le tableau
i, compteur
pay, pays
*/

int miseajour(Pays *tpays[],int nbpays,char *nomFich){
	FILE *fe=fopen(nomFich,"r");
	Pays pay;
	int pos,i;

	if(fe==NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		return -1;
	}
	fscanf(fe,"%s %d %d %d",pay.nom,&pay.nbmo,&pay.nbma,&pay.nbmb);
	while(feof(fe)==0){
		pos=recherche(tpays,nbpays,pay.nom);
		if(pos==nbpays || strcmp(tpays[pos]->nom,pay.nom)!=0){
			for(i=nbpays;i>pos;i--){
				tpays[i]=tpays[i-1];
			}
			tpays[pos]=(Pays *)malloc(sizeof(Pays));
			
			pay.nbtm=pay.nbmo+pay.nbma+pay.nbmb;
			*tpays[pos]=pay;
			nbpays ++;
		}
		else{
			tpays[pos]->nbmo+=pay.nbmo;
			tpays[pos]->nbma+=pay.nbma;
			tpays[pos]->nbmb+=pay.nbmb;
			tpays[pos]->nbtm+=pay.nbmo+pay.nbma+pay.nbmb;
		}
		fscanf(fe,"%s %d %d %d",pay.nom,&pay.nbmo,&pay.nbma,&pay.nbmb);
	}
	fclose(fe);
	return nbpays;
}

/* Nom : sauvegarde
Finalité : sauvegarde les données dans un fichier
Paramètres entrant: nbpays, nombre de pays
Paramètres entrant-sortant: *tpays[], tableau de pointeur pointant sur des pays
Valeur retourné: Aucune
Variables : i, compteur
*/

void sauvegarde(Pays *tpays[],int nbpays){
	FILE *fs=fopen("paysalpha.don","w");
	int i;

	if(fs==NULL){
		printf("Erreur lors de l'ouverture du fichier\n");
		return;
	}
	for(i=0;i<nbpays;i++){
		fprintf(fs,"%s %d %d %d %d\n",tpays[i]->nom,tpays[i]->nbmo,tpays[i]->nbma,tpays[i]->nbmb,tpays[i]->nbtm);
	}
	fclose(fs);
}