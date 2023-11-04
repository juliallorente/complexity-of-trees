#include "utils.h"

char avlWorstCasePath[] = "data/worstCaseAVL.csv";
char b1WorstCasePath[] = "data/worstCaseB1.csv";
char b5WorstCasePath[] = "data/worstCaseB5.csv";
char b10WorstCasePath[] = "data/worstCaseB10.csv";
char rubroNegraWorstCasePath[] = "data/worstCaseRubroNegra.csv";

char avlAvgCasePath[] = "data/avgCaseAVL.csv";
char b1AvgCasePath[] = "data/avgCaseB1.csv";
char b5AvgCasePath[] = "data/avgCaseB5.csv";
char b10AvgCasePath[] = "data/avgCaseB10.csv";
char rubroNegraAvgCasePath[] = "data/avgCaseRubroNegra.csv";

int numberOfKeys = 1000;
int step = 1;
int numberOfExecutions = 100;
int sizeLimit = 1000;

register_t counter = 0;

void printColumnNamesinFile(FILE *fptr) {
    fprintf(fptr, "chaves,operações\n");
}

int randomNum(int max) {
	return ((rand() % max) + 1);
}
