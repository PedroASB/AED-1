// LISTA DE ORDENAÇÃO - SELECTION E INSERTION SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 04

#include <stdio.h>

void insertionSort(int v[], int size);

int main(){
	int i;
	int A[8] = {10, 20, 3, 15, 5, 1, 4, 2};

	printf("QUESTAO 04\n\n");

	printf("Arranjo A = {");
	for (i = 0; i < 8; i++){
		printf("%d", A[i]);
		if (i < 7) printf(", ");
	}
	printf("}\n\n");

	insertionSort(A, 8);
	return 0;
}

void insertionSort(int v[], int size){
	int i, j, cont;
	int aux, troca = 0;

	for (i = 1; i < size ; i++){
		j = i;
		while (j > 0 && v[j - 1] > v[j]){
			aux = v[j];
			v[j] = v[j - 1];
			v[j - 1] = aux;
			troca++;

			printf("Troca %d: {", troca);
			for (cont = 0; cont < size; cont++){
				printf("%d", v[cont]);
				if (cont < size - 1) printf(", ");
			}
			printf("}\n");

			printf("%d trocou com %d\n\n", v[j], v[j - 1]);

			j--;
		}

	}
}
