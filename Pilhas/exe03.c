// PILHAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTAO 03

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um no
typedef struct node {
	int number;
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
void pushStack(Stack * stack, int number);

// Procuma um elemento na pilha e retorna sua posicao
int searchStack(Stack * stack, int number);

// Remove um elemento de uma pilha
void removeElementStack(Stack * stack, int number);

// Imprime os elementos de uma pilha 
void printStack(Stack * stack);

// Libera a memoria alocada por uma pilha dinamica
Stack * freeStack(Stack * stack);

int main(){
	int num;
	Stack * stack = createStack();

	printf("\nQuestao 03\n\n");
	printf("Digite os numeros de tombo: (-1 para encerrar)\n");

	while (1){
		printf("\nInserindo novo tombo: ");
		scanf("%d", &num);
		if (num == -1) break;
		pushStack(stack, num);
		printf("Inserido com sucesso!\n");
	}

	printf("\nPilha formada:\n");
	printStack(stack);
	printf("\nDigite o numero do tombo a ser removido da pilha: ");
	scanf("%d", &num);
	
	removeElementStack(stack, num);

	printf("\nApos a eliminacao:\n");
	if (stack->size == 0) printf("Nao restou numeros na pilha\n");
	else printStack(stack);
	printf("\n");

	stack = freeStack(stack);
	return 0;
}

Stack * createStack(void){
	Stack * stack = (Stack *) malloc(sizeof(Stack));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

void pushStack(Stack * stack, int number){
	if (stack == NULL) return;

	Node * newNode = (Node *) malloc(sizeof(Node));
	newNode->number = number;
	stack->size++;

	if (stack->size == 1){
		stack->top = newNode;
		stack->top->link = NULL;
		return;
	}

	newNode->link = stack->top;
	stack->top = newNode;
}

int searchStack(Stack * stack, int number){
	if (stack == NULL || stack->size == 0) return -1;

	int i = 0;
	Node * node = stack->top;

	while (node != NULL){
		if (node->number == number) return i;
		node = node->link;
		i++;
	}

	return -1;
}


void removeElementStack(Stack * stack, int number){
	int index = searchStack(stack, number);
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

void printStack(Stack * stack){
	if (stack == NULL || stack->size == 0) return;
	
	Node * node = stack->top;

	while (node != NULL){
		printf("%d", node->number);
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
