#include "queue.h"

Queue * createQueue(){
	Queue * queue = (Queue *) malloc(sizeof(queue));
	queue->head = NULL;
	queue->tail = queue->head;
	queue->size = 0;
	return queue;
}

void pushQueue(Queue * queue, int value){
	if (queue == NULL) return;

	Node * node = (Node *) malloc(sizeof(Node));
	node->info = value;
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
	if (queue == NULL || queue->size == 0){
		printf("Fila vazia\n");
		return;
	}

	Node * node = queue->head;

	while (node != NULL){
		printf("%d", node->info);
		if (node->link != NULL) printf(" -> ");
		node = node->link;
	}
	printf("\n");
}

int searchQueue(Queue * queue, int key){
	int index = 0;

	Node * node = queue->head;
	while (node != NULL){
		if (node->info == key) return index;
		node = node->link;
		index++;
	}
	return -1;
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
