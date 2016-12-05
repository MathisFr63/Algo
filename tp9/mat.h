#include <stdio.h>

typedef struct{
	char code[6];
	int coef;
	char des[31];
}Mat;

Mat lireMat(FILE *fe);
int chargeFmat(Mat tmat[],int nbmax);
void affichtabM(Mat tmat[],int nbmat);
Mat saisieMat(Mat tmat[],int nbmat);
void ajoutMat(void);
