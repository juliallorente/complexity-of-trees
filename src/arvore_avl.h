#ifndef __ARVORE_AVL_H
#define __ARVORE_AVL_H

#include "utils.h"

typedef struct no_avl {
    struct no_avl* pai;
    struct no_avl* esquerda;
    struct no_avl* direita;
    int valor;
} No_AVL;

typedef struct arvore_avl {
    struct no_avl* raiz;
} ArvoreAVL;

ArvoreAVL* criarArvoreAVL();
No_AVL* adicionarNoAVL(No_AVL*, int);
No_AVL* adicionarAVL(ArvoreAVL*, int);
void balanceamentoAVL(ArvoreAVL*, No_AVL*);
int alturaAVL(No_AVL*);
int fbAVL(No_AVL*);
No_AVL* rsd(ArvoreAVL*, No_AVL*);
No_AVL* rse(ArvoreAVL*, No_AVL*);
No_AVL* rdd(ArvoreAVL*, No_AVL*);
No_AVL* rde(ArvoreAVL*, No_AVL*);
void percorrerProfundidadeInOrderAVL(No_AVL*, void (*callback)(int));

#endif