#include "worstCases.h"

void populateCsvWorstCaseAVL(char path[], char modes[]) {
	ArvoreAVL *a_avl;

	FILE *fptr = fopen(path, modes);

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	a_avl = criarArvoreAVL();
	for (int j = 0; j < numberOfKeys; j += step) {
		adicionarAVL(a_avl, j);
		fprintf(fptr, "%d,%ld\n", j, counter);
		counter = 0;
	}

	fclose(fptr);
	printf("AVL Worst Case generated, its data can be found at %s\n", path);  
}

void populateCsvWorstCaseBTree(char path[], char modes[], int order) {
	ArvoreB* arvoreB;

	FILE *fptr = fopen(path, modes);

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	arvoreB = criaArvoreB(order);
	for (int j = 0; j < numberOfKeys; j += step) {
		adicionaChaveArvoreB(arvoreB, j);
		fprintf(fptr, "%d,%ld\n", j, counter);
		counter = 0;
	}

	fclose(fptr);
	printf("B%d Worst Case generated, its data can be found at %s\n", order, path);  
}

void populateCsvWorstCaseRubroNegra(char path[], char modes[]) {
	ArvoreRubroNegra* a_rubro_negra;

	FILE* fptr = fopen(rubroNegraWorstCasePath, "w+");

	if (fptr == NULL) {
		printf("Unable to open file");
		exit(-1);
	}

	printColumnNamesinFile(fptr);

	a_rubro_negra = criarRubroNegra();
	for (int j = 0; j < numberOfKeys; j += step) {
		adicionarRubroNegra(a_rubro_negra, j);
		fprintf(fptr, "%d,%ld\n", j, counter);
		counter = 0;
	}

	fclose(fptr);
	printf("Rubro Negra Worst Case generated, its data can be found at %s\n", rubroNegraWorstCasePath);

}
