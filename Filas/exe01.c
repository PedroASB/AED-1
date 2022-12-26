// FILAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTAO 01

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

int main(){
	int input;
	Document doc;
	Node * node = NULL;
	Queue * queue = createQueue();
	FILE * file = fopen("spool.bin", "wb");

	printf("\n== Fila de Impressao ==\n");
	printf("Leitura ate o fim de arquivo (EOF) (Ctrl + D)\n"); // Ctrl + D (Linux) ou Ctrl + Z (Windows)

	while (1){
		printf("\nNome do documento: ");
		input = scanf("%[^\n]%*c", doc.name);

		if (input == EOF) break;

		printf("Tempo de impressao: ");
		scanf("%d%*c", &doc.time);

		pushQueue(queue, doc);
		printf("Adcionado a fila!\n");
	}

	node = queue->head;
	fwrite(&(queue->size), sizeof(int), 1, file);

	while (node != NULL){
		fwrite(&(node->doc.name), sizeof(char), 50, file);
		fwrite(&(node->doc.time), sizeof(int), 1, file);
		node = node->link;	
	}

	printf("\n\nFim da leitura\n");
	
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
		printf("Tempo de impressao: %ds\n\n", node->doc.time);
		node = node->link;
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
