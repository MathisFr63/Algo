#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nbSegment(int n);
int rechVal(int tab[],int n,int val);
int rechProche(int tan[],int n,int val,int *pos);
int rechMax(int tab[],int n);
int teststrlen(char mot[],int n);
void copie(char mot1[],char mot2[],int n);
void globale (void);
int comparaisonint(int tab1[],int tab2[],int n);
int comparaison(char tab1[],char tab2[],int n);