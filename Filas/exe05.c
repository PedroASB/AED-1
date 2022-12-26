// FILAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTAO 05

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	// Union: o primeiro "no" armazena a posicao do 
	// ultimo mas o demais armazenam o RA dos alunos
	union {
		unsigned long int RA;
		struct no * fim; 
	} elem;

	struct no * prox;
} No;

typedef struct {
	int tam;
	No * inicio; // ponteiro para o inicio da fila
} Descritor;

// Cria uma fila dinamica
Descritor * criaFila();

// Insere um novo elemento ao final de uma fila dinamica
void insereFila(Descritor * fila, unsigned long int valor);

// Imprime todos os elementos de uma fila dinamica
void imprimeFila(Descritor * fila);

// Libera a memoria alocada por uma fila dinamica
Descritor * liberaFila(Descritor * fila);

int main(){
	int tam;
	No * no = NULL;
	Descritor * fila = criaFila();
	unsigned long int RA;
	FILE * file = fopen("protocols.bin", "wb");

	printf("\n== Armazenando RAs em uma fila ==\n");
	printf("(Digite 0 para encerrar)\n");

	while (1) {
		printf("\nInforme o RA: ");
		scanf("%lu", &RA);
		if (RA == 0) break;
		insereFila(fila, RA);
		printf("RA armazenado!\n");
	}

	tam = fila->tam - 1;
	fwrite(&tam, sizeof(int), 1, file);

	no = fila->inicio->prox;
	while (no != NULL){
		fwrite(&(no->elem.RA), sizeof(unsigned long int), 1, file);
		no = no->prox;	
	}

	printf("\nFim dos requerimentos\n");
	printf("\nFila formada:\n");
	imprimeFila(fila);

	fclose(file);
	fila = liberaFila(fila);
	return 0;
}

Descritor * criaFila(){
	Descritor * fila = (Descritor *) malloc(sizeof(Descritor));
	fila->inicio = (No *) malloc(sizeof(No));
	fila->tam = 1;
	return fila;
}

void insereFila(Descritor * fila, unsigned long int valor){
	if (fila == NULL) return;

	No * no = (No *) malloc(sizeof(No));
	no->elem.RA = valor;
	fila->tam++;

	if (fila->tam == 2){
		fila->inicio->prox = no;
		fila->inicio->elem.fim = fila->inicio->prox;
		return;
	}

	fila->inicio->elem.fim->prox = no;
	fila->inicio->elem.fim = no;
}

void imprimeFila(Descritor * fila){
	if (fila == NULL || fila->tam < 1){
		printf("Fila vazia\n");
		return;
	}

	No * no = fila->inicio->prox;

	while (no != NULL){
		printf("%lu", no->elem.RA);
		if (no->prox != NULL) printf(" -> ");
		no = no->prox;
	}
	printf("\n");
}

Descritor * liberaFila(Descritor * fila){
	if (fila == NULL) return NULL;

	if (fila->tam == 0){
		free(fila);
		return NULL;
	}

	No * previous = fila->inicio;
	No * no = previous->prox;

	while (no != NULL){
		no = previous->prox;
		free(previous);
		previous = no;
		fila->tam--;
	}

	free(fila);

	return NULL;
}
