// FILAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTAO 04

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

// Remove o primeiro elemento de uma fila dinâmica
void popQueue(Queue * queue);

// Imprime todos os elementos de uma fila dinamica
void printQueue(Queue * queue);

// Libera a memoria alocada por uma fila dinamica
Queue * freeQueue(Queue * queue);

int main(){
	int sizeQueue;
	Queue * queue = createQueue();
	unsigned long int RA;
	FILE * file = fopen("protocols.bin", "rb");

	if (!file) {
		printf("O arquivo deve ser gerado no exercicio 03\n");
		return 0;
	}

	fread(&sizeQueue, sizeof(int), 1, file);

	while (sizeQueue > 0){
		fread(&RA, sizeof(unsigned long int), 1, file);
		pushQueue(queue, RA);
		sizeQueue--;
	}

	while (queue->head != NULL) {
		if (queue->head != NULL) {
			printf("\n== Fila de atendimento ==\n");
			printQueue(queue);
		}
		popQueue(queue);
	}

	printf("\nTodos foram atendidos!\n");

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

void popQueue(Queue * queue){
	if (queue == NULL || queue->size == 0) return;

	if (queue->size == 1){
		queue->tail->link = NULL;
		free(queue->head);
		queue->head = NULL;
		queue->size--;
		return;
	}

	Node * node = queue->head->link;
	free(queue->head);
	queue->head = node;
	queue->size--;
}

void printQueue(Queue * queue){
	if (queue == NULL || queue->size == 0) return;

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
