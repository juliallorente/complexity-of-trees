#include "arvore_avl.h"

ArvoreAVL* criarArvoreAVL() {
	ArvoreAVL *arvore = malloc(sizeof(ArvoreAVL));
	arvore->raiz = NULL;

	return arvore;
}

No_AVL* adicionarNoAVL(No_AVL* no, int valor) {
	counter++;
	if (valor > no->valor) {
		if (no->direita == NULL) {
			No_AVL* novo = malloc(sizeof(No_AVL));
			novo->valor = valor;
			novo->pai = no;
			novo->direita = NULL;
			novo->esquerda = NULL;
			no->direita = novo;

			return novo;
		} else {
			return adicionarNoAVL(no->direita, valor);
		}
	} else {
		if (no->esquerda == NULL) {
			No_AVL* novo = malloc(sizeof(No_AVL));
			novo->valor = valor;
			novo->pai = no;
			novo->direita = NULL;
			novo->esquerda = NULL;
			no->esquerda = novo;

			return novo;
		} else {
			return adicionarNoAVL(no->esquerda, valor);
		}
	}
}

No_AVL* adicionarAVL(ArvoreAVL* arvore, int valor) {
	counter++;
	if (arvore->raiz == NULL) {
		No_AVL* novo = malloc(sizeof(No_AVL));
		novo->valor = valor;
		novo->pai = NULL;
		novo->direita = NULL;
		novo->esquerda = NULL;
		arvore->raiz = novo;

		return novo;
	} else {
		No_AVL* no = adicionarNoAVL(arvore->raiz, valor);
		balanceamentoAVL(arvore, no);

		return no;
	}
}

void balanceamentoAVL(ArvoreAVL* arvore, No_AVL* no) {
	while (no != NULL) {
		counter++;
		int fator = fbAVL(no);
		if (fator > 1) { // árvore mais pesada para esquerda
			// rotação para a direita (++)

			if (fbAVL(no->esquerda) > 0) {
				// printf("RSD(%d)\n",no->valor);
				rsd(arvore, no); //rotação simples a direita, pois o FB do filho tem sinal igual
			} else {
				// printf("RDD(%d)\n",no->valor);
				rdd(arvore, no); //rotação dupla a direita, pois o FB do filho tem sinal diferente (+-)
			}
		} else if (fator < -1) { // árvore mais pesada para a direita
			// rotação para a esquerda (--)
			if (fbAVL(no->direita) < 0) {
			   // printf("RSE(%d)\n", no->valor);
				rse(arvore, no); //rotação simples a esquerda, pois o FB do filho tem sinal igual
			} else {
				// printf("RDE(%d)\n", no->valor);
				rde(arvore, no); //rotação dupla a esquerda, pois o FB do filho tem sinal diferente (-+)
			}
		}

		no = no->pai;
	}
}

int alturaAVL(No_AVL* no) {
	int esquerda = 0, direita = 0;

	if (no->esquerda != NULL) {
		esquerda = alturaAVL(no->esquerda) + 1;
	}

	if (no->direita != NULL) {
		direita = alturaAVL(no->direita) + 1;
	}

	return esquerda > direita ? esquerda : direita;
}

// Quando o FB resultar em um valor diferente de 0, -1 ou 1, deverá ser realizada uma das operações de balanceamentoAVL
int fbAVL(No_AVL* no) {
	int esquerda = 0,direita = 0;

	counter++;
	if (no->esquerda != NULL) {
		esquerda = alturaAVL(no->esquerda) + 1;
	}

	if (no->direita != NULL) {
		direita = alturaAVL(no->direita) + 1;
	}

	return esquerda - direita;
}

// Operações de balanceamentoAVL:
// Rotação simples à esquerda(--): FB desbalanceado negativo, nó à direita com FB negativo
No_AVL* rse(ArvoreAVL* arvore, No_AVL* no) {

	No_AVL* pai = no->pai;
	No_AVL* direita = no->direita;

	counter++;
	no->direita = direita->esquerda;
	no->pai = direita;

	direita->esquerda = no;
	direita->pai = pai;

	if (no->direita != NULL) {
		no->direita->pai = no;
	}

	if (pai == NULL) {
		arvore->raiz = direita;
	} else {
		if (pai->esquerda == no) {
			pai->esquerda = direita;
		} else {
			pai->direita = direita;
		}
	}

	return direita;
}

// Rotação simples à direita(++): FB desbalanceado positivo, nó à esquerda com FB positivo
No_AVL* rsd(ArvoreAVL* arvore, No_AVL* no) {
	No_AVL* pai = no->pai;
	No_AVL* esquerda = no->esquerda;

	counter++;
	no->esquerda = esquerda->direita;
	no->pai = esquerda;

	esquerda->direita = no;
	esquerda->pai = pai;

	if (no->esquerda != NULL) {
		no->esquerda->pai = no;
	}

	if (pai == NULL) {
		arvore->raiz = esquerda;
	} else if (pai->esquerda == no) {
		pai->esquerda = esquerda;
	} else {
		pai->direita = esquerda;
	}

	return esquerda;
}

// Rotação dupla à esquerda(-+): FB desbalanceado negativo, nó à direita com FB positivo
No_AVL* rde(ArvoreAVL* arvore, No_AVL* no) {
	counter++;
	no->direita = rsd(arvore, no->direita);
	return rse(arvore, no);
}

// Rotação dupla à direita(+-): FB desbalanceado positivo, nó à esquerda com FB negativo
No_AVL* rdd(ArvoreAVL* arvore, No_AVL* no) {
	counter++;
	no->esquerda = rse(arvore, no->esquerda);
	return rsd(arvore, no);
}

void percorrerProfundidadeInOrderAVL(No_AVL* no, void (*callback)(int)) {
	if (no != NULL) {
		percorrerProfundidadeInOrderAVL(no->esquerda, callback);
		callback(no->valor);
		percorrerProfundidadeInOrderAVL(no->direita, callback);
	}
}
