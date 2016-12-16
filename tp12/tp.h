typedef struct{
	char nom[20];
	int nbmo;
	int nbma;
	int nbmb;
	int nbtm;
}Pays;



int chargeFresult(Pays *tpays[], int nbmax);
int recherche(Pays *tPays[],int nb,char *nom);
void affiche (Pays **tpays,int nb);