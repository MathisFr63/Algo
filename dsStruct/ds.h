typedef struct{
	int jour;
	int mois;
	int annee;
	}Date;

typedef struct{
	char nom[21];
	char prenom[21];
	Date naissance;
	char etab[15];
	}Etudiant;

Etudiant lireEtu(FILE* fe);