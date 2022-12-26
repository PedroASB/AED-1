// LISTA DE ORDENAÇÃO - BUBBLE E SHELL SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 04
#include <stdio.h>

#define tam 10

int shellSort(int v[], int size){
	int i, j, valor, trocas = 0;
	int h = 1;

	while (h < size){
		h = 3*h + 1;
	}
	
	while (h > 0){
		for (i = h; i < size; i++){
			valor = v[i];
			j = i;
			while (j > (h - 1) && valor <= v[j - h]){
				v[j] = v[j - h];
				j = j - h;
				trocas++;
			}
			v[j] = valor;
		}
		h = h / 3;
	}

	return trocas;
}

int main(){
	int i, trocas;
	int A[tam] = {12, 42, 1, 6, 56, 23, 52, 9, 5, 24};

	printf("\nQUESTAO 04\n\nVetor A = {");
	for (i = 0; i < tam; i++){
		printf("%d", A[i]);
		if (i < tam - 1) printf(", ");
	}
	printf("}\n\n");

	trocas = shellSort(A, tam);

	printf("Vetor A ordenado = {");
	for (i = 0; i < tam; i++){
		printf("%d", A[i]);
		if (i < tam - 1) printf(", ");
	}
	printf("}\n\n");

	printf("Foram realizadas %d trocas\n", trocas);

	return 0;
}
