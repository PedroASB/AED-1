// FILAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTAO 02

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um documento
typedef struct document {
	char name[50];
	int time;
} Document;

// Estrutura de um no
typedef struct node {
	Document doc;
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
void pushQueue(Queue * queue, Document newDoc);

// Imprime todos os elementos de uma fila dinamica
void printQueue(Queue * queue);

// Libera a memoria alocada por uma fila dinamica
Queue * freeQueue(Queue * queue);

// Realiza uma contagem regressiva
void countdown(int number);

int main(){
	int sizeQueue;
	Document doc;
	Node * node = NULL;
	Queue * queue = createQueue();
	FILE * file = fopen("spool.bin", "rb");

	fread(&sizeQueue, sizeof(int), 1, file);

	while (sizeQueue > 0){
		fread(&(doc.name), sizeof(char), 50, file);
		fread(&(doc.time), sizeof(int), 1, file);
		pushQueue(queue, doc);
		sizeQueue--;
	}

	printf("\n== Fila de Impressao ==\n\n");
	printQueue(queue);

	printf("Fim das impressoes\n");
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

void pushQueue(Queue * queue, Document newDoc){
	if (queue == NULL) return;

	Node * node = (Node *) malloc(sizeof(Node));
	node->doc.time = newDoc.time;
	strcpy(node->doc.name, newDoc.name);
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
		printf("Documento: %s\n", node->doc.name);
		printf("Tempo de impressao: %ds\n", node->doc.time);
		system("sleep 1");
		countdown(node->doc.time);
		printf("Documento impresso!\n\n");
		node = node->link;
		system("sleep 1");
	}

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

void countdown(int number){
	while (number > 0){
		printf("%d\n", number);
		system("sleep 1");
		number--;
	}
}
