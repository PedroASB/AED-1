// LISTAS ENCADEADAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 01

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct lista{
	int info;
} Lista;

// Inicializa/limpa a lista
void inicializarLista(Lista lista[][2]);

// Encontra o elemento na lista e retorna sua posição 
int encontrarElemento(Lista lista[][2], int valor);

// Insere um novo elemento na lista
void inserirElemento(Lista lista[][2], int valor, int indice);

// Remove um elemento da lista
void removerElemento(Lista lista[][2], int valor);

// Imprime os elementos da lista
void imprimirLista(Lista lista[][2]);

// Pausa o terminal
void pausar();

int main(){
	int opt, num, indice, t = 0;
	Lista lista[TAM][2];

	printf("\nQuestao 01\n\n");
	while (1) {
		printf("-- Menu de opcoes --\n");
		printf("1 - Inicializar/limpar a lista\n");
		printf("2 - Inserir um novo elemento\n");
		printf("3 - Remover um elemento\n");
		printf("4 - Imprimir a lista\n");
		printf("5 - Encerrar o programa\n");
		printf("Sua escolha: ");
		scanf("%d", &opt);

		switch (opt) {
			case 1:
				inicializarLista(lista);
				t = 1;
				printf("\nLista inicializada com sucesso!\n");
				break;
			case 2:
				if (t == 0) printf("\nA lista ainda nao foi inicializada!\n");
				else {
					printf("\nInforme o valor a ser inserido: ");
					scanf("%d", &num);
					printf("Em que posicao deseja inserir: \n");
					scanf("%d", &indice);
					if (indice < 0 || indice > 9) printf("Indice invalido!\n");
					else {
						inserirElemento(lista, num, indice);
						printf("Valor inserido com sucesso!\n");
					}
				}
				break;
			case 3:
				if (t == 0) printf("\nA lista ainda nao foi inicializada!\n");
				else {
					printf("\n");
					imprimirLista(lista);
					printf("\nInforme o valor a ser removido: ");
					scanf("%d", &num);
					if (encontrarElemento(lista, num) == -1) printf("Valor nao encontrado!\n");
					else {
						removerElemento(lista, num);
						printf("Valor removido com sucesso!\n");
					}
				}
				break;
			case 4:
				if (t == 0) printf("\nA lista ainda nao foi inicializada!\n");
				else {
					printf("\n");
					imprimirLista(lista);
				}
				break;
			case 5:
				printf("\nFim do programa\n");
				return 0;
			default:
				printf("\nOpcao invalida!\n");
				break;
		}

		printf("\n");
		pausar();
		printf("\n");
	}
	
	return 0;
}

void inicializarLista(Lista lista[][2]){
	int i;
	for (i = 0; i < TAM; i++){
		lista[i][0].info = 0;
		lista[i][1].info = i + 1;
	}
	lista[i-1][1].info = -1;
}

int encontrarElemento(Lista lista[][2], int valor){
	int indice;
	for (indice = 0; indice < TAM; indice++){
		if (lista[indice][0].info == valor) return indice;
	}
	return -1;
}

void inserirElemento(Lista lista[][2], int valor, int indice){
	if (indice < 0 || indice > 9) return;
	lista[indice][0].info = valor;
}

void removerElemento(Lista lista[][2], int valor){
	int indice = encontrarElemento(lista, valor);
	if (indice == -1) return;
	lista[indice][0].info = 0;
}

void imprimirLista(Lista lista[][2]){
	int i;
	printf("Valor -> Posicao do proximo\n");
	for (i = 0; i < TAM; i++){
		printf("%5d -> ", lista[i][0].info);
		if (lista[i][1].info == -1) printf("NULL");
		else printf("%d", lista[i][1].info);
		printf("\n");
	}
}

void pausar(){
    setbuf(stdin, NULL);
	printf("Pressione ENTER para continuar... ");
    getchar();
    setbuf(stdin, NULL);
}
