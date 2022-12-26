// LISTAS ENCADEADAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 02

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó
typedef struct no {
	int info;
	struct no * prox;
} No;

// Estrutura de uma lista encadeada
typedef struct lista {
	int tam;
	No * inicio;
	No * fim;
} Lista;

// Cria uma lista encadeada
Lista * criarLista(void);

// Insere um elemento ao final de uma lista encadeada
void inserirElemento(Lista * lista, int valor);

// Imprime os elementos de uma lista encadeada
void imprimirLista(Lista * lista);

// Libera a memória alocada de uma lista encadeada
Lista * liberarLista(Lista * lista);

int main(){
	Lista * lista = NULL;
	int n, x;

	printf("\nQuestao 02\n\n");
	printf("LISTA ENCADEADA\n\nDigite quantos termos deseja inserir: ");
	scanf("%d", &n);

	lista = criarLista();

	printf("Insira os termos:\n");
	while (n--){
		scanf("%d", &x);
		inserirElemento(lista, x);
	}

	printf("\nLista encadeada formada:\n");
	imprimirLista(lista);

	lista = liberarLista(lista);
	return 0;
}

Lista * criarLista(void){
	Lista * lista = (Lista *) malloc(sizeof(Lista));
	lista->tam = 0;
	lista->inicio = NULL;
	lista->fim = lista->inicio;
	return lista;
}

void inserirElemento(Lista * lista, int valor){
	if (lista == NULL) return;

	No * no = (No *) malloc(sizeof(No));
	no->info = valor;

	lista->tam++;
	if (lista->tam == 1){
		lista->inicio = no;
		lista->fim = lista->inicio;
		return;
	}

	lista->fim->prox = no;
	lista->fim = no;
}

void imprimirLista(Lista * lista){
	if (lista == NULL || lista->inicio == NULL){
		printf("Lista vazia\n");
		return;
	}

	No * no = lista->inicio;

	while (no != NULL){
		printf("%d", no->info);
		if (no->prox != NULL) printf(" -> ");
		no = no->prox;
	}
	printf("\n");
}

Lista * liberarLista(Lista * lista){
	if (lista == NULL) return NULL;

	No * anterior = lista->inicio;
	No * atual = anterior->prox;

	while (anterior != NULL){
		atual = anterior->prox;
		free(anterior);
		anterior = atual;
		lista->tam--;
	}

	free(lista);
	return NULL;
}
