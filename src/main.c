#include "worstCases.h"
#include "avgCases.h"

int main() {
	populateCsvWorstCaseAVL(avlWorstCasePath, "w+");
	populateCsvAvgCaseAVL(avlAvgCasePath, "w+");

	populateCsvWorstCaseBTree(b1WorstCasePath, "w+", 1);
	populateCsvAvgCaseBTree(b1AvgCasePath, "w+", 1);
	
	populateCsvWorstCaseBTree(b5WorstCasePath, "w+", 5);
	populateCsvAvgCaseBTree(b5AvgCasePath, "w+", 5);
	
	populateCsvWorstCaseBTree(b10WorstCasePath, "w+", 10);
	populateCsvAvgCaseBTree(b10AvgCasePath, "w+", 10);
	
	populateCsvWorstCaseRubroNegra(rubroNegraWorstCasePath, "w+");
	populateCsvAvgCaseRubroNegra(rubroNegraAvgCasePath, "w+");

	return 0;	
}