// LISTA DE ORDENAÇÃO - QUICK E HEAP SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 06
#include <stdio.h>
#include <ctype.h>
#define tam 23

// gcc exe06.c -o exe06 && ./exe06

void swap(char *a, char *b);

// Para ordem conforme o valor de cada caractere ma tabela ASCII
void heapify(char v[], int n, int i);
void heapSort(char v[], int n);

// Para ordem alfabética
void heapify_2(char v[], int n, int i);
void heapSort_2(char v[], int n);

int main(){
	int i;
	char str[tam] = "Ordenando com Heap Sort";

	printf("\nQUESTAO 06\n\n");

	printf("String original: \"");
	for (i = 0; i < tam; i++){
		printf("%c", str[i]);
	}
	printf("\"\n\n");

	// printf("Ordenando de forma decrescente...\n\n");

	heapSort(str, tam);

	printf("Ordem decrescente (Tabela ASCII):  \"");
	for (i = 0; i < tam; i++){
		printf("%c", str[i]);
	}
	printf("\"\n");

	heapSort_2(str, tam);

	printf("Ordem decrescente (Alfabetica):  \"");
	for (i = 0; i < tam; i++){
		printf("%c", str[i]);
	}
	printf("\"\n");
	
	return  0;
}


void swap(char *a, char *b){
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(char v[], int n, int i){
	int min = i;
	int leftChild = 2*i + 1;
	int rightChild = 2*i + 2;

	if (leftChild < n && v[leftChild] < v[min]){
		min = leftChild;
	}
	if (rightChild < n && v[rightChild] < v[min]){
		min = rightChild;
	}

	if (min != i){
		swap(&v[i], &v[min]);
		heapify(v, n, min);
	}
}

void heapSort(char v[], int n){
	int i;
	for (i = (n / 2 - 1); i >= 0; i--){
		heapify(v, n, i);
	}
	for (i = (n - 1); i >= 0; i--){
		swap(&v[0], &v[i]);
		heapify(v, i, 0);
	}
}

void heapify_2(char v[], int n, int i){
	int min = i;
	int leftChild = 2*i + 1;
	int rightChild = 2*i + 2;

	if (leftChild < n && tolower(v[leftChild]) < tolower(v[min])){
		min = leftChild;
	}
	if (rightChild < n && tolower(v[rightChild]) < tolower(v[min])){
		min = rightChild;
	}

	if (min != i){
		swap(&v[i], &v[min]);
		heapify_2(v, n, min);
	}
}

void heapSort_2(char v[], int n){
	int i;
	for (i = (n / 2 - 1); i >= 0; i--){
		heapify_2(v, n, i);
	}
	for (i = (n - 1); i >= 0; i--){
		swap(&v[0], &v[i]);
		heapify_2(v, i, 0);
	}
}
