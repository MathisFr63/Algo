#include "tp.h"

int main(void){
	Ensemble e, e1, e2;
	int choix, val, choix2;
	Booleen rep;

	e = ensembleVide();
	e1 = ensembleVide();
	e2 = ensembleVide();
	printf("Choix : ");
	scanf("%d", &choix);
	
	e1 = ajouter(e1, 1);
	e1 = ajouter(e1, 2);
	e1 = ajouter(e1, 3);
	e1 = ajouter(e1, 4);
	e1 = ajouter(e1, 5);
	e1 = ajouter(e1, 6);


	e2 = ajouter(e2, 4);
	e2 = ajouter(e2, 5);
	e2 = ajouter(e2, 6);
	e2 = ajouter(e2, 7);
	e2 = ajouter(e2, 8);
	e2 = ajouter(e2, 9);


	while(choix != 0){
		if (choix == 1){
			printf("Valeur : ");
			scanf("%d", &val);
			e1 = ajouter(e1, val);
		}

		if (choix == 2){
			printf("Valeur : ");
			scanf("%d", &val);
			e2 = ajouter(e2, val);
		}

		else if (choix == 3){
			printf("Choix2 : ");
			scanf("%d", &choix2);
			if (choix2 == 1)
				afficherEnsemble(e);
			else if (choix2 == 2)
				afficherEnsemble(e1);
			else if (choix2 == 3)
				afficherEnsemble(e2);
		}

		else if (choix == 4){
			printf("Valeur : ");
			scanf("%d", &val);
			e = supprimer(e, val);
		}

		else if (choix == 5){
			printf("Valeur : ");
			scanf("%d", &val);
			rep = appartient(e, val);
			if (rep == FAUX)
				printf("FAUX\n");
			else
				printf("Vrai\n");
		}
		else if (choix == 6){
			rep = estVide(e);
			if(rep == FAUX)
				printf("La liste n'est pas vide\n");
			else
				printf("La liste est vide\n");
		}

		else if (choix == 7){
			e = ensembleVide();
			e = intersection(e1,e2);
		}

		else if (choix == 8){
			e = ensembleVide();
			e = fusion(e1,e2);
		}

		else if (choix == 9){
			e = ensembleVide();
			e = complement(e1,e2);
		}

		printf("Choix : ");
		scanf("%d", &choix);
	}

	return 0; 
}