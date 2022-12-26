#include "stack.h"

Stack * createStack(void){
	Stack * stack = (Stack *) malloc(sizeof(Stack));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

void pushStack(Stack * stack, int value){
	if (stack == NULL) return;

	Node * newNode = (Node *) malloc(sizeof(Node));
	newNode->info = value;
	stack->size++;

	// printf(" <- ");
	if (stack->size == 1){
		stack->top = newNode;
		stack->top->link = NULL;
		// printf("%d", stack->top->info);
		return;
	}

	newNode->link = stack->top;
	stack->top = newNode;
	// printf("%d", stack->top->info);
}

void popStack(Stack * stack){
	if (stack == NULL || stack->size == 0) return;

	if (stack->size == 1){
		free(stack->top);
		stack->size--;
		return;
	}

	Node * node = stack->top;
	stack->top = stack->top->link;
	free(node);
	stack->size--;
}

void printStack(Stack * stack){
	if (stack == NULL || stack->size == 0) {
		printf("Lista vazia\n");
		return;
	}
	
	Node * node = stack->top;

	while (node != NULL){
		printf("%d", node->info);
		node = node->link;
		if (node != NULL) printf(" -> ");
	}
	printf("\n");
}

Node * peekStack(Stack * stack){
	Node * element = stack->top;
	return element;
}

int getElementIndex(Stack * stack, int number){
	if (stack == NULL || stack->size == 0) return -1;

	int index = 0;
	Node * node = stack->top;

	while (node != NULL){
		if (node->info == number) return index;
		node = node->link;
		index++;
	}

	return -1;
}

void removeElementStack(Stack * stack, int number){
	int index = getElementIndex(stack, number);
	if (index == -1) return;

	int i;
	Node * previous = stack->top;
	Node * remove = NULL;

	stack->size--;

	if (index == 0){
		remove = stack->top;
		stack->top = stack->top->link;
		free(remove);
		return;
	}

	for (i = 0; i < index - 1; i++) {
		previous = previous->link;
	}

	remove = previous->link;
	previous->link = previous->link->link;
	free(remove);
}

Stack * freeStack(Stack * stack){
	if (stack == NULL) return NULL;

	if (stack->size == 0){
		free(stack);
		return NULL;
	}

	Node * actual, * next;
	actual = stack->top;
	next = actual->link;

	while (next != NULL){
		free(actual);
		actual = next;
		next = next->link;
	}
	free(stack);

	return NULL;
}
