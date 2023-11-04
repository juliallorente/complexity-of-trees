#include "arvore_b.h"

ArvoreB* criaArvoreB(int ordem) {
    ArvoreB* a = malloc(sizeof(ArvoreB));
    a->ordem = ordem;
    a->raiz = criaNoArvoreB(a);

    return a;
}

NoArvoreB* criaNoArvoreB(ArvoreB* arvore) {
    int max = arvore->ordem * 2;
    NoArvoreB* no = malloc(sizeof(NoArvoreB));

    no->pai = NULL;

    no->chaves = malloc(sizeof(int) * (max + 1));
    no->filhos = malloc(sizeof(NoArvoreB) * (max + 2));
    no->total = 0;

    for (int i = 0; i < max + 2; i++) {
        no->filhos[i] = NULL;
    }

    return no;
}

void percorreArvoreB(NoArvoreB* no) {
    if (no != NULL) {
        for (int i = 0; i < no->total; i++){
            percorreArvoreB(no->filhos[i]); //visita o filho a esquerda

            printf("%d ",no->chaves[i]);
        }

        percorreArvoreB(no->filhos[no->total]); //visita ultimo filho (direita)
    }
}

int pesquisaBinariaArvoreB(NoArvoreB* no, int chave) {
    int inicio = 0, fim = no->total - 1, meio;

    while (inicio <= fim) {
        counter++;

        meio = (inicio + fim) / 2;

        if (no->chaves[meio] == chave) {
            return meio; //encontrou
        } else {
            if (no->chaves[meio] > chave) {
                fim = meio - 1;
            } else {
                inicio = meio + 1;
            }
        }
    }
    return inicio; //não encontrou
}

int localizaChaveArvoreB(ArvoreB* arvore, int chave) {
    NoArvoreB *no = arvore->raiz;

    while (no != NULL) {
        int i = pesquisaBinariaArvoreB(no, chave);

        if (i < no->total && no->chaves[i] == chave) {
            return 1; //encontrou
        } else {
            no = no->filhos[i];
        }
    }

    return 0; //não encontrou
}

NoArvoreB* localizaNoArvoreB(ArvoreB* arvore, int chave) {
    NoArvoreB *no = arvore->raiz;

    while (no != NULL) {
        counter++;
        int i = pesquisaBinariaArvoreB(no, chave);

        if (no->filhos[i] == NULL)
            return no; //encontrou nó
        else
            no = no->filhos[i];
    }

    return NULL; //não encontrou nenhum nó
}

void adicionaChaveNoArvoreB(NoArvoreB* no, NoArvoreB* novo, int chave) {
    int i = pesquisaBinariaArvoreB(no, chave);
    counter++;
    for (int j = no->total - 1; j >= i; j--) {
        no->chaves[j + 1] = no->chaves[j];
        no->filhos[j + 2] = no->filhos[j + 1];
    }

    no->chaves[i] = chave;
    no->filhos[i + 1] = novo;

    no->total++;
}

int transbordoArvoreB(ArvoreB* arvore, NoArvoreB* no) {
    counter++;
    return no->total > arvore->ordem * 2;
}

NoArvoreB* divideNoArvoreB(ArvoreB* arvore, NoArvoreB* no) {
    int meio = no->total / 2;
    NoArvoreB* novo = criaNoArvoreB(arvore);
    counter++;
    novo->pai = no->pai;
    for (int i = meio + 1; i < no->total; i++) {
        novo->filhos[novo->total] = no->filhos[i];
        novo->chaves[novo->total] = no->chaves[i];

        if (novo->filhos[novo->total] != NULL) {
            novo->filhos[novo->total]->pai = novo;
        }

        novo->total++;
    }

    novo->filhos[novo->total] = no->filhos[no->total];
    if (novo->filhos[novo->total] != NULL) {
        novo->filhos[novo->total]->pai = novo;
    }
    no->total = meio;
    return novo;
}

void adicionaChaveRecursivoArvoreB(ArvoreB* arvore, NoArvoreB* no, NoArvoreB* novo, int chave) {

    adicionaChaveNoArvoreB(no, novo, chave);

    counter++;
    if (transbordoArvoreB(arvore, no)) {
        int promovido = no->chaves[arvore->ordem];
        novo = divideNoArvoreB(arvore, no);

        if (no->pai == NULL) {

            NoArvoreB* pai = criaNoArvoreB(arvore);
            counter++;
            pai->filhos[0] = no;
            adicionaChaveNoArvoreB(pai, novo, promovido);

            no->pai = pai;
            novo->pai = pai;
            arvore->raiz = pai;
        } else
            adicionaChaveRecursivoArvoreB(arvore, no->pai, novo, promovido);
    }
}

void adicionaChaveArvoreB(ArvoreB* arvore, int chave) {
    NoArvoreB* no = localizaNoArvoreB(arvore, chave);

    adicionaChaveRecursivoArvoreB(arvore, no, NULL, chave);
}