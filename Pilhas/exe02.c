// PILHAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTAO 02

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um no
typedef struct node {
	char character;
	struct node * link;
} Node;

// Estrutura de uma pilha
typedef struct stack {
	int size;
	struct node * top;
} Stack;

// Cria/aloca uma pilha dinamica
Stack * createStack(void);

// Insere um novo elemento no topo de uma pilha
void pushStack(Stack * stack, char ch);

// Imprime os elementos de uma pilha 
void printStack(Stack * stack);

// Libera a memoria alocada por uma pilha dinamica
Stack * freeStack(Stack * stack);

int main(){
	Stack * stack = createStack();
	char ch;

	printf("\nQuestao 02\n\n");
	printf("Digite uma palavra:\n");
	
	while (1){
		scanf("%c", &ch);
		if (ch == '\n') break;
		pushStack(stack, ch);
	}

	printf("\nDesempilhando...\n");
	printStack(stack);

	stack = freeStack(stack);
	return 0;
}


Stack * createStack(void){
	Stack * stack = (Stack *) malloc(sizeof(Stack));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

void pushStack(Stack * stack, char ch){
	if (stack == NULL) return;

	Node * newNode = (Node *) malloc(sizeof(Node));
	newNode->character = ch;
	stack->size++;

	if (stack->size == 1){
		stack->top = newNode;
		stack->top->link = NULL;
		return;
	}

	newNode->link = stack->top;
	stack->top = newNode;
}

void printStack(Stack * stack){
	if (stack == NULL || stack->size == 0) return;
	
	Node * node = stack->top;

	while (node != NULL){
		printf("%c", node->character);
		node = node->link;
		if (node != NULL) printf(" -> ");
	}
	printf("\n");

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
