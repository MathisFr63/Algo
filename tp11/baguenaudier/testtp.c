#include "tp.h"
#include <stdio.h>

int main(void){
	int tab[6]={1,2,3,4,5,6},i,n=6;
	for(i=0;i<n;i++){
		printf("%d;",tab[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		vidertab(tab,n);
	}
	for(i=0;i<n;i++){
		printf("%d;",tab[i]);
	}
	printf("\n");
	return 0; 
}