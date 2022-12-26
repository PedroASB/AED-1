// LISTA DE PESQUISA SEQUENCIAL E BINÁRIA
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 02

#include <stdio.h>
#include <stdlib.h>

int comp_linear = 0;
int comp_binary = 0;

// Pesquisa sequencial
int linearSearch(int v[], int size, int key);

// Pesquisa binária (recursiva)
int binarySearch(int v[], int beg, int end, int key);

// Imprime um vetor no terminal
void printArray(int v[], int size);

int main(){
	int i, p, N, X;
	int * v = NULL;

	printf("\nQuestao 02\n\n");
	printf("Digite o tamanho do vetor a ser lido: ");
	scanf("%d", &N);

	v = (int *) calloc(N, sizeof(int));

	printf("Digite os elementos de forma ordenada:\n");
	for (i = 0; i < N; i++) scanf("%d", &v[i]);

	printf("\nVetor = {");
	printArray(v, N);
	printf("}\n\n");

	printf("Digite o valor a ser procurado: ");
	scanf("%d", &X);
	printf("\n");

	p = linearSearch(v, N, X);

	if (p == -1) printf("Busca linear:\nValor %d nao encontrado\n", X);
	else printf("Busca linear:\nValor %d encontrado na posicao %d\n", X, p);
	printf("Foram realizadas %d comparacoes\n\n", comp_linear);

	p = binarySearch(v, 0, N - 1, X);

	if (p == -1) printf("Busca binaria:\nValor %d nao encontrado\n", X);
	else printf("Busca binaria:\nValor %d encontrado na posicao %d\n", X, p);
	printf("Foram realizadas %d comparacoes\n\n", comp_binary);
	
	free(v);
	return 0;
}

int linearSearch(int v[], int size, int key){
	int i;
	for (i = 0; i < size; i++){
		comp_linear += 1;
		if (v[i] == key) return i;
	}
	return -1;
}

int binarySearch(int v[], int beg, int end, int key){
	int i;
	i = (beg + end) / 2;

	if (beg > end) {
		comp_binary++;
		return -1;
	}
	if (v[i] == key) {
		comp_binary++;
		return i;
	} 
	else if (v[i] > key) {
		comp_binary++;
		binarySearch(v, beg, i - 1, key);
	} 
	else if (v[i] < key) {
		comp_binary++;
		binarySearch(v, i + 1, end, key);
	}
}

void printArray(int v[], int size){
	if (size == 0) return;
	int i;
	for (i = 0; i < size; i++) {
		printf("%d", v[i]);
		if (i < size - 1) printf(", ");
	}
}
