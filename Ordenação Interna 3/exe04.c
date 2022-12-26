// LISTA DE ORDENAÇÃO - QUICK E HEAP SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 04
#include <stdio.h>
#define tam 9

// gcc exe04.c -o exe04 && ./exe04

int A[tam] = {5, 13, 2, 25, 7, 17, 20, 8, 4};
int troca = 0;

void swap(int *a, int *b);
void heapify(int v[], int n, int i);
void heapSort(int v[], int n);

int main(){

	int i;
	// int A[tam] = {5, 13, 2, 25, 7, 17, 20, 8, 4};

	printf("\nQUESTAO 04\n\n");

	printf("Vetor A = {");
	for (i = 0; i < tam; i++) {
		printf("%d", A[i]);
		if (i < tam - 1) printf(", ");
	}
	printf("}\n");

	printf("\nAplicando o Heap Sort...\n\n");
	heapSort(A, tam);

	printf("\nVetor ordenado!\n");

	return 0;
}

void swap(int *a, int *b){
	int tmp, i;
	tmp = *a;
	*a = *b;
	*b = tmp;

	troca++;
	printf("Troca #%d: ", troca);

	printf("{");
	for (i = 0; i < tam; i++) {
		printf("%d", A[i]);
		if (i < tam - 1) printf(", ");
	}
	printf("}\n");

}

void heapify(int v[], int n, int i){
	int max = i;
	int leftChild = 2*i + 1;
	int rightChild = 2*i + 2;

	if (leftChild < n && v[leftChild] > v[max]){
		max = leftChild;
	}
	if (rightChild < n && v[rightChild] > v[max]){
		max = rightChild;
	}

	if (max != i){
		swap(&v[i], &v[max]);
		heapify(v, n, max);
	}
}

void heapSort(int v[], int n){
	int i;
	for (i = (n / 2 - 1); i >= 0; i--){
		heapify(v, n, i);
	}
	for (i = (n - 1); i >= 0; i--){
		swap(&v[0], &v[i]);
		heapify(v, i, 0);
	}
}
