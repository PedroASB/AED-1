// FILAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTAO 03

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um no
typedef struct node {
	unsigned long int RA;
	struct node * link;
} Node;

// Estrutura de uma fila dinamica
typedef struct queue {
	int size;
	Node * head;
	Node * tail;
} Queue;

// Cria uma fila dinamica
Queue * createQueue();

// Insere um novo elemento ao final de uma fila dinamica
void pushQueue(Queue * queue, unsigned long int value);

// Imprime todos os elementos de uma fila dinamica
void printQueue(Queue * queue);

// Libera a memoria alocada por uma fila dinamica
Queue * freeQueue(Queue * queue);

int main(){
	Node * node = NULL;
	Queue * queue = createQueue();
	unsigned long int RA;
	FILE * file = fopen("protocols.bin", "wb");

	printf("\n== Armazenando RAs em uma fila ==\n");
	printf("(Digite 0 para encerrar)\n");

	while (1) {
		printf("\nInforme o RA: ");
		scanf("%lu", &RA);
		if (RA == 0) break;
		pushQueue(queue, RA);
		printf("RA armazenado!\n");
	}

	node = queue->head;
	fwrite(&(queue->size), sizeof(int), 1, file);

	while (node != NULL){
		fwrite(&(node->RA), sizeof(unsigned long int), 1, file);
		node = node->link;	
	}

	printf("\nFim dos requerimentos\n");
	printf("\nFila formada:\n");
	printQueue(queue);

	fclose(file);
	queue = freeQueue(queue);
	return 0;
}


Queue * createQueue(){
	Queue * queue = (Queue *) malloc(sizeof(queue));
	queue->head = NULL;
	queue->tail = queue->head;
	queue->size = 0;
	return queue;
}

void pushQueue(Queue * queue, unsigned long int value){
	if (queue == NULL) return;

	Node * node = (Node *) malloc(sizeof(Node));
	node->RA = value;
	queue->size++;

	if (queue->size == 1){
		queue->head = node;
		queue->tail = queue->head;
		return;
	}

	queue->tail->link = node;
	queue->tail = node;
}

void printQueue(Queue * queue){
	if (queue == NULL || queue->size == 0){
		printf("Fila vazia\n");
		return;
	}

	Node * node = queue->head;

	while (node != NULL){
		printf("%lu", node->RA);
		if (node->link != NULL) printf(" -> ");
		node = node->link;
	}
	printf("\n");
}

Queue * freeQueue(Queue * queue){
	if (queue == NULL) return NULL;

	if (queue->size == 0){
		free(queue);
		return NULL;
	}

	Node * previous = queue->head;
	Node * node = previous->link;

	while (node != NULL){
		node = previous->link;
		free(previous);
		previous = node;
		queue->size--;
	}

	free(queue);

	return NULL;
}
