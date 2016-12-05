#include <stdio.h>
#include "pendu.h"
#define TAILLE 27

void initialiser(char mot[],int n){
	int i;

	for(i=0;i<n;i++){
		mot[i]='-';
	}
	mot[i]='\0';
}

void placer(char mot1[],char c,char mot2[]){
	int i;

	for(i=0;mot1[i]!='\0';i++){
		if(mot1[i]==c)
			mot2[i]=c;
	}
}

void globale(void){
	char mot[TAILLE],mot1[TAILLE],c,reconnus,essai[TAILLE];
	int nbL=0,n,etap=0,i;

	printf("Joueur 1, proposez un mot à deviner :\n");
	system("stty -echo");
	scanf("%s",mot1);
	system("stty echo");
	printf("En combien d'étapes voulez-vous jouer ? ");
	scanf("%d",&n);
	while(mot1[nbL]!='\0'){
		nbL++;
	}
	printf("Mot de %d lettre à trouver en %d étapes\n",nbL,n);
	initialiser(mot,nbL);
	while(etap<n){
		printf("Proposez une lettre :");
		scanf("%*c%c",&c);
		placer(mot1,c,mot);
		printf("%s\n",mot);
		printf("Avez-vous reconnus le mot (O/N) ?");
		scanf("%*c%c",&reconnus);
		etap++;
		if(reconnus=='O'){
			printf("Mot ? ");
			scanf("%s",essai);
			if(strcmp(essai,mot1)==0){
				printf("Bravo, vous avez gagné !!!\nMot trouvé en %d étapes\n",etap);
				return;
			}
			else
				printf("Désolé ...\n");
		}
	}
	printf("Votre nombre d'étapes maximum a était dépassé\n");
}