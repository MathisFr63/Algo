#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell{
	int val;
	struct cell * suiv;
} Cellule;

typedef Cellule * Ensemble;

typedef	enum{FAUX, VRAI} Booleen;

Ensemble ensembleVide(void);
Ensemble ajouter(Ensemble e, int x);
Ensemble insererEnTete(Ensemble e, int x);
Ensemble insererEnQueue(Ensemble e, int x);
void afficherEnsemble(Ensemble e);
Ensemble supprimer(Ensemble e, int x);
Ensemble supprimerEnTete(Ensemble e);
Booleen appartient(Ensemble e, int x);
Booleen estVide(Ensemble e);
Ensemble intersection(Ensemble e1, Ensemble e2);
Ensemble fusion(Ensemble e1, Ensemble e2);
Ensemble complement(Ensemble e1, Ensemble e2);
