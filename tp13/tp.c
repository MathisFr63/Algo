#include "tp.h"

Ensemble ensembleVide(void){
	return NULL;
}

Ensemble ajouter(Ensemble e, int x){
	
	if (e == NULL || e->val >= x)
		e = insererEnTete(e, x);
	else
		e->suiv = ajouter(e->suiv, x);
	return e;
}

Ensemble insererEnTete(Ensemble e, int x){
	Cellule * tmp;

	tmp = (Cellule*)malloc(sizeof(Cellule));
		if (tmp == NULL) exit(1);
	
	tmp->val = x;
	tmp->suiv = e;

	return tmp;
}

void afficherEnsemble(Ensemble e){
	Cellule * tmp;
	tmp = e;

	printf("{");
	if (tmp != NULL){
		printf("%d", tmp->val);
		tmp = tmp->suiv;
	}
	while (tmp != NULL){
		printf(", %d", tmp->val);
		tmp=tmp->suiv;
	}
	printf("}\n");
}

Ensemble supprimer(Ensemble e, int x){
	if (e == NULL || e->val > x){
			printf("La valeur %d n'a pas été trouvée dans la liste\n", x);
			return e;
		}

	if (e->val == x){
		e = supprimerEnTete(e);
		return e;
	}

	else
		e->suiv = supprimer(e->suiv, x); 
}

Ensemble supprimerEnTete(Ensemble e){
	Cellule * tmp;
	tmp = e;
	e = tmp->suiv;

	free(tmp);
	return e;
}

Booleen appartient(Ensemble e, int x){
	if (e == NULL || e->val > x)
		return FAUX;

	if (e->val == x)
		return VRAI;

	return appartient(e->suiv, x);
}

Booleen estVide(Ensemble e){
	if (e == NULL)
		return VRAI;
	return FAUX;
}

Ensemble intersection(Ensemble e1, Ensemble e2){
	Ensemble e;

	e = ensembleVide();
	
	while (e1 != NULL && e2 != NULL){
		if (e1->val == e2->val){
			e = ajouter(e,e1->val);
			e1 = e1->suiv;
			e2 = e2->suiv;
		}

		else if (e1->val < e2->val)
			e1 = e1->suiv;
		else
			e2 = e2->suiv;
	}

	return e;
}

Ensemble fusion(Ensemble e1, Ensemble e2){
	Ensemble e;

	e = ensembleVide();
	
	while (e1 != NULL || e2 != NULL){		
		if (e1 != NULL && e2 !=NULL){
			if (e1->val == e2->val){
				e = ajouter(e,e1->val);
				e1 = e1->suiv;
				e2 = e2->suiv;
			}

			else if (e1->val < e2->val){
				e = ajouter(e, e1->val);
				e1 = e1->suiv;
			}

			else if (e1->val > e2->val){
				e = ajouter(e, e2->val);
				e2 = e2->suiv;
			}
		}

		else{
			if (e1 != NULL){
				e = ajouter(e, e1->val);
				e1 = e1->suiv;
			}

			if (e2 != NULL){
				e = ajouter(e, e2->val);
				e2 = e2->suiv;
			}
		}

	}

	return e;
}

Ensemble complement(Ensemble e1, Ensemble e2){
	Ensemble e;

	e = ensembleVide();
	
	while (e1 != NULL || e2 != NULL){
		if (e1 != NULL && e2 !=NULL){
			if (e1->val < e2->val){
				e1 = e1->suiv;
			}

			else if (e1->val == e2->val){
				e1 = e1->suiv;
				e2 = e2->suiv;
			}
		}

		else if (e1 == NULL && e2 != NULL){
			e = ajouter(e, e2->val);
			e2 = e2->suiv;
		}

	}

	return e;
}