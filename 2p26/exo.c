#include <stdio.h>
#include"exo.h"

void testPG(void){
	int x,y,z,maxi;
	x=saisir1nb();
	y=saisir1nb();
	z=saisir1nb();
	maxi= pg3nb(x,y,z);
	printf("Le plus grand est : %d\n",maxi);
	return;
}
 int saisir1nb(void){
	 int nb;
	 printf("Nombre :");
	 scanf("%d",&nb);
	 return nb;
 }
 
 int pg2nb(int a, int b){
	 int pg;
	 if(a>b)
	 pg=a;
	 else
	 pg=b;
	 return pg;
 }
 
int pg3nb(int a,int b,int c){
	int pg2,pg;
	pg2=pg2nb(a,b);
	if(pg2>c)
	pg=pg2;
	else
	pg=c;
	return pg;
}


