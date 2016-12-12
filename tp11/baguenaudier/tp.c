#include "tp.h"
#include <stdio.h>

void vidertab(int tab[],int n){
	if(n==0) return;
	if(n==1){
		tab[0]=0;
		return;
	}
	vidertab(tab,n-2);
	tab[n-1]=0;
	remplirtab(tab,n-2);
	vidertab(tab,n-1);
}

void remplirtab (int tab[], int n){
	if(n==0) return;
	if(n==1){
		tab[0]=1;
		return;
	}
	remplirtab(tab,n-1);
	vidertab(tab,n-2);
	tab[n-1]=1;
	remplirtab(tab,n-2);
}