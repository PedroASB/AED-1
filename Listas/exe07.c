// LISTAS ENCADEADAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 07

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó
typedef struct no {
	int info;
	struct no * ant;
	struct no * prox;
} No;

// Estrutura de uma lista encadeada
typedef struct lista {
	int tam;
	No * inicio;
	No * fim;
} Lista;

// LISTA CIRCULAR DUPLAMENTE ENCADEADA

// Cria uma lista encadeada
Lista * criarLista(void);

// Busca um elemento em uma lista encadeada e retorna sua posição
int encontrarElemento(Lista * lista, int valor);

// Insere um elemento ao final de uma lista encadeada
void inserirElemento(Lista * lista, int valor);

// Insere um elemento em uma posição específica em uma lista encadeada
void inserirElementoPosicao(Lista * lista, int valor, int indice);

// Remove o primeiro elemento de uma lista encadeada
void removerElementoInicio(Lista * lista);

// Remove o último elemento de uma lista encadeada
void removerElementoFinal(Lista * lista);

// Remove um elemento de uma lista encadeada pela posição informada
void removerElementoPosicao(Lista * lista, int indice);

// Remove um elemento de uma lista encadeada pelo valor informada
void removerElementoValor(Lista * lista, int valor);

// Imprime os elementos de uma lista encadeada
void imprimirLista(Lista * lista);

// Imprime os elementos de uma lista encadeada na ordem inversa
void imprimirListaInvertida(Lista * lista);

// Libera a memória alocada de uma lista encadeada
Lista * liberarLista(Lista * lista);

// Pausa o terminal
void pausar();

int main(){
	int opt, num, qtd, indice;
	Lista * lista = criarLista();

	printf("\nQuestao 07\n\n");
	while (1) {
		printf("-- Menu de opcoes --\n");
		printf("1 - Inserir elementos ao final\n");
		printf("2 - Inserir elementos pela posicao\n");
		printf("3 - Remover um elemento pelo valor\n");
		printf("4 - Remover um elemento pela posicao\n");
		printf("5 - Imprimir a lista\n");
		printf("6 - Imprimir a lista na ordem inversa\n");
		printf("7 - Encerrar o programa\n");
		printf("Sua escolha: ");
		scanf("%d", &opt);

		if (opt == 1){

			printf("\nQuantos valores deseja inserir? ");
			scanf("%d", &qtd);
			if (qtd > 0){
				printf("Digite os valores:\n");
				while (qtd > 0){
					scanf("%d", &num);
					inserirElemento(lista, num);
					qtd--;
				}
				printf("Valores inseridos com sucesso!\n\n");
			}
			pausar();

		}
		else if (opt == 2){

			if (lista->tam == 0){
				indice = 0;
				printf("\nAinda nao ha elementos na lista. Inserindo na posicao 0...\n");
				printf("Quantos valores deseja inserir? ");
				scanf("%d", &qtd);
				if (qtd > 0){
					printf("Digite os valores:\n");
					while (qtd > 0){
						scanf("%d", &num);
						inserirElementoPosicao(lista, num, indice);
						indice++;
						qtd--;
					}
					printf("Valores inseridos com sucesso!\n\n");
				}
			}
			else {
				printf("\nLista: ");
				imprimirLista(lista);
				printf("\nEm que posicao deseja inserir? (0 a %d) ", lista->tam);
				scanf("%d", &indice);
				if (indice < 0 || indice > lista->tam) {
					printf("Indice invalido!\n\n");
					continue;
				}
				printf("\nQuantos valores deseja inserir? ");
				scanf("%d", &qtd);
				if (qtd > 0){
					printf("Digite os valores:\n");
					while (qtd > 0){
						scanf("%d", &num);
						inserirElementoPosicao(lista, num, indice);
						indice++;
						qtd--;
					}
					printf("Valores inseridos com sucesso!\n\n");
				}
			
			}
			pausar();

		}
		else if (opt == 3){

			if (lista->tam == 0) {
				printf("\nA lista esta vazia!\n\n");
			} else {
				printf("\nLista: ");
				imprimirLista(lista);
				printf("\nQual valor deseja remover? ");
				scanf("%d", &num);
				if (encontrarElemento(lista, num) == -1) printf("O valor nao esta presente na lista!\n\n");
				else {
					removerElementoValor(lista, num);
					printf("Valor removido com sucesso!\n\n");
				}
			}
				pausar();

		}
		else if (opt == 4){

			if (lista->tam == 0) {
				printf("\nA lista esta vazia!\n\n");
			} else {
				printf("\nLista: ");
				imprimirLista(lista);
				printf("\nQual o indice do valor que deseja remover? ");
				if (lista->tam > 0) printf("(0 a %d) ", lista->tam - 1);
				scanf("%d", &indice);
				if (indice < 0 || indice > lista->tam - 1) printf("Indice invalido!\n\n");
				else {
					removerElementoPosicao(lista, indice);
					printf("Valor removido com sucesso!\n\n");
				}
			}
				pausar();

		}
		else if (opt == 5){

			if (lista->tam == 0) {
				printf("\nA lista esta vazia!\n\n");
			} else {
				printf("\nLista:\n");
				imprimirLista(lista);
				printf("\n");
			}
			pausar();
			
		}
		else if (opt == 6){

			if (lista->tam == 0) {
				printf("\nA lista esta vazia!\n\n");
			} else {
				printf("\nLista invertida:\n");
				imprimirListaInvertida(lista);
				printf("\n");
			}
			pausar();
			
		}
		else if (opt == 7){
			break;
		}
		else {
			printf("\n\n");
			continue;
		}

		printf("\n\n");
	}

	lista = liberarLista(lista);
	printf("\nFim do programa\n");
	return 0;
}

Lista * criarLista(void){
	Lista * lista = (Lista *) malloc(sizeof(Lista));
	lista->tam = 0;
	lista->inicio = NULL;
	lista->fim = lista->inicio;
	return lista;
}

int encontrarElemento(Lista * lista, int valor){
	int indice = 0;
	No * atual = lista->inicio;

	lista->fim->prox = NULL;

	while (atual != NULL){
		if (atual->info == valor) return indice;
		atual = atual->prox;
		indice++;
	}

	lista->fim->prox = lista->inicio;
	return -1;
}

void inserirElemento(Lista * lista, int valor){
	if (lista == NULL) return;

	No * novo = (No *) malloc(sizeof(No));
	novo->info = valor;
	No * aux = lista->fim;

	lista->tam++;
	if (lista->tam == 1){
		lista->inicio = novo;
		lista->fim = lista->inicio;
		return;
	}

	aux = lista->fim;
	aux->prox = novo;
	novo->ant = aux;
	lista->fim = novo;

	lista->fim->prox = lista->inicio;
	lista->inicio->ant = lista->fim;
}

void inserirElementoPosicao(Lista * lista, int valor, int indice){
	if (indice < 0 || indice > lista->tam) return;

	if (lista->tam == 0 || indice == lista->tam){
		inserirElemento(lista, valor);
		return;
	} 

	No * novo = (No *) malloc(sizeof(No));
	novo->info = valor;

	No * atual = lista->inicio;
	No * proximo = NULL;
	lista->tam++;
	
	if (indice == 0){
		novo->prox = atual;
		atual->ant = novo;
		lista->inicio = novo;
		return;
	}

	int T = indice - 1;
	while (T > 0){
		atual = atual->prox;
		T--;
	}

	proximo = atual->prox;
	novo->prox = proximo;
	proximo->ant = novo;
	atual->prox = novo;
	novo->ant = atual;
}

void removerElementoInicio(Lista * lista){
	No * proximo = lista->inicio->prox;
	proximo->ant = lista->fim;
	free(lista->inicio);
	lista->inicio = proximo;
	lista->tam--;
}

void removerElementoFinal(Lista * lista){
	int i;
	No * anterior = lista->inicio;

	for (i = 0; i < (lista->tam - 2); i++){
		anterior = anterior->prox;
	}

	free(lista->fim);
	anterior->prox = NULL;
	lista->inicio->ant = anterior;
	lista->fim = anterior;
	lista->tam--;
}

void removerElementoPosicao(Lista * lista, int indice){
	if (indice < 0 || indice > lista->tam - 1 || lista->tam == 0){
		return;
	}
	if (lista == NULL){
		printf("Lista vazia\n");
		return;	
	}
	if (lista->tam == 1){
		lista->fim->prox = NULL;
		free(lista->inicio);
		lista->tam--;
		return;
	}

	int i;
	No * anterior = lista->inicio;
	No * proximo = NULL;

	if (indice == 0){
		removerElementoInicio(lista);
		return;
	}
	if (indice == lista->tam - 1){
		removerElementoFinal(lista);
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

void removerElementoValor(Lista * lista, int valor){
	if (lista == NULL || lista->tam == 0){
		printf("Lista vazia\n");
		return;	
	}

	int i, indice;
	No * anterior = lista->inicio;
	No * proximo = NULL;

	indice = encontrarElemento(lista, valor);
	if (indice == -1) return;

	removerElementoPosicao(lista, indice);
}

void imprimirLista(Lista * lista){
	if (lista == NULL || lista->tam == 0){
		printf("A lista esta vazia\n");
		return;
	}

	No * no = lista->inicio;
	lista->fim->prox = NULL;

	while (no != NULL){
		printf("%d", no->info);
		if (no->prox != NULL) printf(" -> ");
		no = no->prox;
	}
	printf("\n");

	lista->fim->prox = lista->inicio;
}

void imprimirListaInvertida(Lista * lista){
	if (lista == NULL || lista->tam == 0){
		printf("A lista esta vazia\n");
		return;
	}

	No * no = lista->fim;
	lista->inicio->ant = NULL;

	while (no != NULL){
		printf("%d", no->info);
		if (no->ant != NULL) printf(" <- ");
		no = no->ant;
	}
	printf("\n");

	lista->inicio->ant = lista->fim;
}

Lista * liberarLista(Lista * lista){
	if (lista == NULL){
		printf("Lista inexistente\n");
		return NULL;
	}
	else if (lista->tam == 0){
		free(lista);
		return NULL;
	}

	No * anterior = lista->inicio;
	No * atual = anterior->prox;
	lista->inicio->ant = NULL;
	lista->fim->prox = NULL;

	while (anterior != NULL){
		atual = anterior->prox;
		free(anterior);
		anterior = atual;
		lista->tam--;
	}

	free(lista);
	return NULL;
}

void pausar(){
    setbuf(stdin, NULL);
	printf("Pressione ENTER para continuar... ");
    getchar();
    setbuf(stdin, NULL);
}
