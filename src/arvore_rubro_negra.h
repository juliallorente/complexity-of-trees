#ifndef _ARVORE_RUBRO_NEGRA_H
#define _ARVORE_RUBRO_NEGRA_H

#include "utils.h"

enum coloracao { Vermelho, Preto };
typedef enum coloracao Cor;

typedef struct no_rubro_negra {
    struct no_rubro_negra* pai;
    struct no_rubro_negra* esquerda;
    struct no_rubro_negra* direita;
    Cor cor;
    int valor;
} NoRubroNegra;

typedef struct arvore_rubro_negra {
    struct no_rubro_negra* raiz;
    struct no_rubro_negra* nulo;
} ArvoreRubroNegra;

NoRubroNegra* criarNoRubroNegra(ArvoreRubroNegra*, NoRubroNegra*, int);
void balancearRubroNegra(ArvoreRubroNegra*, NoRubroNegra*);
void rotacionarEsquerdaRubroNegra(ArvoreRubroNegra*, NoRubroNegra*);
void rotacionarDireitaRubroNegra(ArvoreRubroNegra*, NoRubroNegra*);
ArvoreRubroNegra* criarRubroNegra();
int vaziaRubroNegra(ArvoreRubroNegra*);
NoRubroNegra* adicionarRubroNegra(ArvoreRubroNegra*, int);
NoRubroNegra* adicionarNoRubroNegra(ArvoreRubroNegra*, NoRubroNegra*, int);
void percorrerProfundidadeInOrderRubroNegra(ArvoreRubroNegra*, NoRubroNegra*, void (*callback)(int));

#endif