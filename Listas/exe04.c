// LISTAS ENCADEADAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 04

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Remove um elemento de uma lista encadeada pela posição informada
void removerElemento(Lista * lista, int indice);

// Imprime os elementos de uma lista encadeada
void imprimirLista(Lista * lista);

// Libera a memória alocada de uma lista encadeada
Lista * liberarLista(Lista * lista);

int main(){
	int indice, num, T = 10;
	Lista * lista = criarLista();

	// Insere valores aleatórios na lista
	srand((unsigned)time(NULL));
	while (T > 0){
		num = rand() % 100;
		inserirElemento(lista, num);
		T--;
	}

	printf("\nQuestao 04\n\n");
	printf("Lista com valores aleatorios:\n");
	imprimirLista(lista);

	printf("\nInforme a posicao do valor para remove-lo: (0 a %d)\n", lista->tam - 1);
	while (1){
		scanf("%d", &indice);
		if (indice >= 0 && indice < lista->tam) break;
		printf("Indice invalido! Digite novamente: ");
	}

	removerElemento(lista, indice);
	printf("\nApos a remocao:\n");
	imprimirLista(lista);

	liberarLista(lista);
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

void removerElemento(Lista * lista, int indice){
	if (lista == NULL || lista->tam == 0){
		printf("Lista vazia\n");
		return;	
	}

	int i;
	No * anterior = lista->inicio;
	No * proximo = NULL;

	if (indice == 0){
		proximo = lista->inicio->prox;
		free(lista->inicio);
		lista->inicio = proximo;
		lista->tam--;
		return;
	}
	else if (indice == lista->tam - 1){
		for (i = 0; i < (lista->tam - 2); i++){
			anterior = anterior->prox;
		}
		free(lista->fim);
		anterior->prox = NULL;
		lista->fim = anterior;
		lista->tam--;
		return;
	}

	for (i = 0; i < indice - 1; i++){
		anterior = anterior->prox;
	}
	proximo = anterior->prox->prox;
	free(anterior->prox);
	anterior->prox = proximo;
	lista->tam--;
}

void imprimirLista(Lista * lista){
	if (lista == NULL || lista->tam == 0){
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
	else if (lista->tam == 0) {
		free(lista);
		return NULL;
	}

	No * anterior = lista->inicio;
	No * atual = anterior->prox;

	while (anterior != NULL){
		atual = anterior->prox;
		free(anterior);
		anterior = atual;
	}

	free(lista);
	return NULL;
}
