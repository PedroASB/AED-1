// PILHAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTAO 04

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um no
typedef struct node {
	double info;
	struct node * link;
} Node;

// Estrutura de uma pilha
typedef struct stack {
	int size;
	struct node * top;
} Stack;

// Cria/aloca uma pilha dinamica
Stack * createStack(void);

// Insere um novo elemento no topo de uma pilha ("Empilha")
void pushStack(Stack * stack, double value);

// Remove o elemento do topo de uma pilha e retorna seu conteudo ("Desempilha")
double popStack(Stack * stack);

// Libera a memoria alocada por uma pilha dinamica
Stack * freeStack(Stack * stack);

// Calcula e retorna o resultado de uma operacao
double result(double a, double b, char * op);

// Verifica se o digito eh um numero ou uma operacao
int verifyString(char * str);

int main(){
	char str[100], * token;
	double num1, num2, res;
	Stack * stack = createStack();

	printf("\nQuestao 04\n\n");
	printf("Digite a expressao:\n");
	scanf("%[^\n]", str);

	token = strtok(str, " ");

	while (token != NULL){
		
		switch ( verifyString(token) ){
			case 1: // Numero
				num1 = atof(token);
				pushStack(stack, num1);
				break;

			case 2: // Operacao
				num2 = popStack(stack);
				num1 = popStack(stack);
				res = result(num1, num2, token);
				pushStack(stack, res);
				break;
		}

		token = strtok(NULL, " ");
	}

	printf("\nResultado:\n");
	printf("%.2lf\n", stack->top->info);

	stack = freeStack(stack);
	return 0;
}

Stack * createStack(void){
	Stack * stack = (Stack *) malloc(sizeof(Stack));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

void pushStack(Stack * stack, double value){
	if (stack == NULL) return;

	Node * newNode = (Node *) malloc(sizeof(Node));
	newNode->info = value;
	stack->size++;

	if (stack->size == 1){
		stack->top = newNode;
		stack->top->link = NULL;
		return;
	}

	newNode->link = stack->top;
	stack->top = newNode;
}

double popStack(Stack * stack){
	if (stack == NULL || stack->size == 0) return 0;

	double value;
	value = stack->top->info;

	if (stack->size == 1){
		free(stack->top);
		stack->size--;
		return value;
	}

	Node * node = stack->top;
	stack->top = stack->top->link;
	free(node);
	stack->size--;
	return value;
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

double result(double a, double b, char * op){
	if ( !strcmp(op, "+") ) return a + b;
	if ( !strcmp(op, "-") ) return a - b;
	if ( !strcmp(op, "*") ) return a * b;
	if ( !strcmp(op, "/") ) {
		if (b != 0) return ( (double)(a) / b );
	}
	return 0;
}

int verifyString(char * str){
	if ( !strcmp(str, "+") || !strcmp(str, "-") || !strcmp(str, "*") || !strcmp(str, "/") ) {
		return 2;
	}
	return 1;
}
