#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó
typedef struct node {
	int info;
	struct node * link;
} Node;

// Estrutura de uma fila dinâmica
typedef struct queue {
	int size;
	Node * head;
	Node * tail;
} Queue;

// Cria uma fila dinâmica
Queue * createQueue();

// Insere um novo elemento ao final de uma fila dinâmica
void pushQueue(Queue * queue, int value);

// Remove o primeiro elemento de uma fila dinâmica
void popQueue(Queue * queue);

// Imprime todos os elementos de uma fila dinâmica
void printQueue(Queue * queue);

// Realiza a busca de uma elemento em uma fila dinâmica
int searchQueue(Queue * queue, int key);

// Libera a memória alocada por uma fila dinâmica
Queue * freeQueue(Queue * queue);

#endif // __QUEUE_H__
