#include <stdio.h>
#include"exo3.h"

void exo(void){
	int Zoo,Bat,Age;
	float prix,pzoo,pbat,page;
	Zoo=zoo();
	Bat=bat();
	Age=age();
	pzoo=pZoo(Zoo);
	pbat=pBat(Bat,Age);
	page=pAge(Age);
	prix=total(pzoo, pbat, page);
	affichage(prix);
}
 
int zoo(void){
	 int zoo;
	 printf("Voulez-vous allez au zoo (0/1) ?");
	 scanf("%d",&zoo);
	 return zoo;
}
 
int bat(void){
	 int bat;
	 printf("Voulez-vous allez au zoo (0/1) ?");
	 scanf("%d",&bat);
	 return bat;
}

int age(void){
	int age;
	printf("Âge de la personne :");
	scanf("%d",&age);
	return age;
}

float pZoo(int Zoo){
	float pZoo=0;
	if (Zoo==1)
	pZoo=2.5;
	return pZoo;
}

float pBat(int Bat, int Age){
	float pBat;
	if (Bat==1)
		if (Age>12 && Age<60)
			pBat=5;
		else
			pBat=4.5;
	return pBat;
}

float pAge(int Age){
	float pAge=0;
	if (Age>12)
	pAge=3;
	return pAge;
}

float total(float pZoo,float pBat,float pAge){
	float total;
	total=pZoo+pBat+pAge;
	return total;
}

void affichage(float total){
	printf("Le prix de l'entrée sera de : %.2f\n",total);
}
