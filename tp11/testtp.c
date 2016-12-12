#include <stdio.h>

int main(void){
//RECHERCHE VALEUR
	// int val,pos,tab[6]={0,1,2,3,4,5};
	// printf("Valeur : ");
	// scanf("%d",&val);
	// pos=rechVal(tab,6,val);
	// if(pos>0)
	// 	printf("La valeur %d se trouve à la position %d\n",val,pos+1);
	// else
	// 	printf("Valeur non trouvée dans le tableau\n");

//RECHERCHE PROCHE
	// int res,pos;
	// int tab[6]={0,12,36,95,45,5};
	// res=rechProche(tab,6,35,&pos);
	// printf("La valeur la plus proche est : %d à la position : %d\n",res,pos);

//RECHERCHE MAX
	// int res;
	// int tab[6]={0,12,36,95,45,5};
	// res=rechMax(tab,6);
	// printf("Max : %d\n",res);

//LONGUEUR
	// int taille;
	// char mot[12]="bonjour";
	// taille=teststrlen(mot);
	// printf("%d\n",taille);

//COPIE
	// int i;
	// char mot1[20]="bonjourtest",mot2[20];
	// copie(mot2,mot1,20);
	// printf("%s\n",mot2);

//COMPARAISON CHAR
	int i, j, k;
	char tab1[12]="ananas",tab2[12]="anana", tab3[12]="ananas";
	i=comparaison(tab1,tab2,12);
	if(i>0)
		printf("%s > %s\n", tab1, tab2);
	else if (i<0)
		printf("%s < %s\n", tab1, tab2);
	else
		printf("Les mots sont identiques\n");	
	j=comparaison(tab1,tab3,12);
	if(j>0)
		printf("%s > %s\n", tab1, tab3);
	else if (j<0)
		printf("%s < %s\n", tab1, tab3);
	else
		printf("Les mots sont identiques\n");
	k=comparaison(tab2,tab3,12);
	if(k>0)
		printf("%s > %s\n", tab2, tab3);
	else if (k<0)
		printf("%s < %s\n", tab2, tab3);
	else
		printf("Les mots sont identiques\n");
//CONCAT
	// int i;
	// char mot1[20]="bonjourtest",mot2[20]="voyons",mot3[40];
	// concat(mot1,mot2,mot3);
	// printf("%s\n",mot3);
	return 0;
}