#include "arvore_rubro_negra.h"

ArvoreRubroNegra* criarRubroNegra() {
    ArvoreRubroNegra *arvore = malloc(sizeof(ArvoreRubroNegra));
    arvore->nulo = NULL;
    arvore->raiz = NULL;

    arvore->nulo = criarNoRubroNegra(arvore, NULL, 0);
    arvore->nulo->cor = Preto;

    return arvore;
}

int vaziaRubroNegra(ArvoreRubroNegra* arvore) {
    return arvore->raiz == NULL;
}

NoRubroNegra* criarNoRubroNegra(ArvoreRubroNegra* arvore, NoRubroNegra* pai, int valor) {
    NoRubroNegra* no = malloc(sizeof(NoRubroNegra));

    no->pai = pai;
    no->valor = valor;
    no->direita = arvore->nulo;
    no->esquerda = arvore->nulo;

    return no;
}

NoRubroNegra* adicionarNoRubroNegra(ArvoreRubroNegra* arvore, NoRubroNegra* no, int valor) {
    counter++;
    if (valor > no->valor) {
        if (no->direita == arvore->nulo) {
            counter++;
            no->direita = criarNoRubroNegra(arvore, no, valor);
            no->direita->cor = Vermelho;

            return no->direita;
        } else {
            return adicionarNoRubroNegra(arvore, no->direita, valor);
        }
    } else {
        if (no->esquerda == arvore->nulo) {
            counter++;
            no->esquerda = criarNoRubroNegra(arvore, no, valor);
            no->esquerda->cor = Vermelho;

            return no->esquerda;
        } else {
            return adicionarNoRubroNegra(arvore, no->esquerda, valor);
        }
    }
}

NoRubroNegra* adicionarRubroNegra(ArvoreRubroNegra* arvore, int valor) {
    if (vaziaRubroNegra(arvore)) {
        counter++;
        arvore->raiz = criarNoRubroNegra(arvore, arvore->nulo, valor);
        arvore->raiz->cor = Preto;

        return arvore->raiz;
    } else {
        NoRubroNegra* no = adicionarNoRubroNegra(arvore, arvore->raiz, valor);
        balancearRubroNegra(arvore, no);

        return no;
    }
}

void percorrerProfundidadeInOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (*callback)(int)) {
    if (no != arvore->nulo) {


        percorrerProfundidadeInOrder(arvore, no->esquerda,callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(arvore, no->direita,callback);
    }
}

void percorrerProfundidadePreOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (*callback)(int)) {
    if (no != arvore->nulo) {
        callback(no->valor);
        percorrerProfundidadePreOrder(arvore, no->esquerda,callback);
        percorrerProfundidadePreOrder(arvore, no->direita,callback);
    }
}

void percorrerProfundidadePosOrder(ArvoreRubroNegra* arvore, NoRubroNegra* no, void (callback)(int)) {
    if (no != arvore->nulo) {
        percorrerProfundidadePosOrder(arvore, no->esquerda,callback);
        percorrerProfundidadePosOrder(arvore, no->direita,callback);
        callback(no->valor);
    }
}

void balancearRubroNegra(ArvoreRubroNegra* arvore, NoRubroNegra* no) {
    while (no->pai->cor == Vermelho) {
        counter++;
        if (no->pai == no->pai->pai->esquerda) {
            NoRubroNegra *tio = no->pai->pai->direita;

            if (tio->cor == Vermelho) {
                counter++;
                tio->cor = Preto; //Caso 1
                no->pai->cor = Preto;
                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            } else {
                if (no == no->pai->direita) {
                    no = no->pai; //Caso 2
                    rotacionarEsquerdaRubroNegra(arvore, no); //Caso 2
                } else {
                    counter++;
                    no->pai->cor = Preto;
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarDireitaRubroNegra(arvore, no->pai->pai); //Caso 3
                }
            }
        } else {
            NoRubroNegra *tio = no->pai->pai->esquerda;

            if (tio->cor == Vermelho) {
                counter++;
                tio->cor = Preto; //Caso 1
                no->pai->cor = Preto;

                no->pai->pai->cor = Vermelho; //Caso 1
                no = no->pai->pai; //Caso 1
            } else {
                if (no == no->pai->esquerda) {
                    no = no->pai; //Caso 2
                    rotacionarDireitaRubroNegra(arvore, no); //Caso 2
                } else {
                    counter++;
                    no->pai->cor = Preto;
                    no->pai->pai->cor = Vermelho; //Caso 3
                    rotacionarEsquerdaRubroNegra(arvore, no->pai->pai); //Caso 3
                }
            }
        }
    }
    arvore->raiz->cor = Preto; //Conserta possível quebra regra 2
}

void rotacionarEsquerdaRubroNegra(ArvoreRubroNegra* arvore, NoRubroNegra* no) {
    NoRubroNegra* direita = no->direita;
    counter++;
    no->direita = direita->esquerda;

    if (direita->esquerda != arvore->nulo) {
        direita->esquerda->pai = no;
    }

    direita->pai = no->pai;

    if (no->pai == arvore->nulo) {
        arvore->raiz = direita;
    } else if (no == no->pai->esquerda) {
        no->pai->esquerda = direita;
    } else {
        no->pai->direita = direita;
    }

    direita->esquerda = no;
    no->pai = direita;
}

void rotacionarDireitaRubroNegra(ArvoreRubroNegra* arvore, NoRubroNegra* no) {
    NoRubroNegra* esquerda = no->esquerda;
    counter++;
    no->esquerda = esquerda->direita;

    if (esquerda->direita != arvore->nulo) {
        esquerda->direita->pai = no;
    }

    esquerda->pai = no->pai;

    if (no->pai == arvore->nulo) {
        arvore->raiz = esquerda;
    } else if (no == no->pai->esquerda) {
        no->pai->esquerda = esquerda;
    } else {
        no->pai->direita = esquerda;
    }

    esquerda->direita = no;
    no->pai = esquerda;
}

void percorrerProfundidadeInOrderRubroNegra(ArvoreRubroNegra * arvore, NoRubroNegra * no, void (*callback)(int)) {
    if (no != arvore->nulo) {


        percorrerProfundidadeInOrder(arvore, no->esquerda,callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(arvore, no->direita,callback);
    }
}