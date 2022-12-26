// LISTA DE ORDENAÇÃO - SELECTION E INSERTION SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 05

#include <stdio.h>
#define tam 6

void insertionSort(int v[], int size){
	int i, j, aux;

	for (i = (size - 2); i >= 0 ; i--){
		j = i;
		while (j < (size - 1) && v[j + 1] > v[j]){
			aux = v[j];
			v[j] = v[j + 1];
			v[j + 1] = aux;
			j++;
		}

	}
}

int main(){
	int i;
	int A[tam] = {31, 41, 59, 26, 41, 58};


	printf("QUESTAO 05\n\n");

	printf("Arranjo A = {");
	for (i = 0; i < tam; i++){
		printf("%d", A[i]);
		if (i < tam - 1) printf(", ");
	}
	printf("}\n\n");

	insertionSort(A, tam);

	printf("Arranjo em A ordem decrescente:\n{");
	for (i = 0; i < tam; i++){
		printf("%d", A[i]);
		if (i < tam - 1) printf(", ");
	}
	printf("}\n");

	return 0;
}
