// LISTA DE ORDENAÇÃO - QUICK E HEAP SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 01
#include <stdio.h>
#define tam 10

int troca = 0;
void quickSort(int v[], int start, int size);

int main(){
	int i;
	int v[tam] = {5, 13, 7, 20, 12, 9, 1, 4, 18, 3};

	printf("\nQUESTAO 01\n\n");

	printf("VETOR A = {");
	for (i = 0; i < tam; i++){
		printf("%d", v[i]);
		if (i < tam - 1) printf(", ");
	}
	printf("}\n\n");

	printf("Aplicando o Quick Sort...\n\n");

	quickSort(v, 0, tam);

	printf("Vetor ordenado!\n");

	return 0;
}

void quickSort(int v[], int start, int size){
	int i, j, aux, pivot;
	int cont;
	i = start;
	j = size - 1;

	pivot = v[(start + size) / 2];

	while (i <= j){
		while (v[i] < pivot && i < size){
			i++;
		}
		while (v[j] > pivot && j > start){
			j--;
		}
		if (i <= j){
			if (i < j){
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				troca++;

				printf("Troca #%d: {", troca);
				for (cont = 0; cont < tam; cont++){
					printf("%d", v[cont]);
					if (cont < tam - 1) printf(", ");
				}
				printf("}\n");

				printf("(%d trocou com %d)\n\n", v[i], v[j]);
			}
			i++;
			j--;
		}
	}

	if (j > start){
		quickSort(v, start, j + 1);
	}
	if (i < size){
		quickSort(v, i, size);
	}

	return;
}
