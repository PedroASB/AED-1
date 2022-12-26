#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó
typedef struct node {
	int info;
	struct node * link;
} Node;

// Estrutura de uma pilha
typedef struct stack {
	int size;
	struct node * top;
} Stack;

// Cria/aloca uma pilha dinâmica
Stack * createStack(void);

// Insere um novo elemento no topo de uma pilha ("Empilha")
void pushStack(Stack * stack, int value);

// Remove o elemento do topo de uma pilha ("Desempilha")
void popStack(Stack * stack);

// Imprime os elementos de uma pilha 
void printStack(Stack * stack);

// Retorna o elemento do topo de uma pilha
Node * peekStack(Stack * stack);

int getElementIndex(Stack * stack, int number);

void removeElementStack(Stack * stack, int number);

// Libera a memória alocada por uma pilha dinâmica
Stack * freeStack(Stack * stack);
