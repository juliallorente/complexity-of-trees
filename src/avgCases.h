#ifndef __AVG_CASES_H
#define __AVG_CASES_H

#include <time.h>
#include "arvore_avl.h"
#include "arvore_rubro_negra.h"
#include "arvore_b.h"

void populateCsvAvgCaseAVL(char[], char[]);
void populateCsvAvgCaseBTree(char[], char[], int);
void populateCsvAvgCaseRubroNegra(char[], char[]);

#endif