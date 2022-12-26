// PILHAS
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTAO 01

#include <stdio.h>
#include <stdlib.h>

// Empilha um elemento no vetor
void pushArray(char * stack, char ch, int size);

// Imprime/desempilha os elementos de um vetor
void printArray(char * stack, int size);

// Libera a memoria alocada por um vetor
char * freeArray(char * stack);

int main(){
	int size = 1;
	char * stack = (char *) malloc(sizeof(char));
	char ch;

	printf("\nQuestao 01\n\n");
	printf("Digite uma palavra:\n");

	while (1){
		scanf("%c", &ch);
		if (ch == '\n') break;
		pushArray(stack, ch, size);
		size++;
	}

	printf("\nDesempilhando...\n");
	printArray(stack, size - 1);

	stack = freeArray(stack);
	return 0;
}

void pushArray(char * stack, char ch, int size){
	stack = (char *) realloc(stack, size * sizeof(char));
	stack[size - 1] = ch;
}

void printArray(char * stack, int size){
	int i;
	for (i = size - 1; i >= 0; i--){
		printf("%c", stack[i]);
		if (i > 0) printf(" -> ");
	}
	printf("\n");
}

char * freeArray(char * stack){
	free(stack);
	return NULL;
}
