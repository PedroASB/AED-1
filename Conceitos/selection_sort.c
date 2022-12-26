// SELECTION SORT
#include <stdio.h>

#define tam 10

// void selectionSort(int v[], int size);

int main(){

	int i, j, min, aux, trocas = 0;
	int v[tam] = {5, 8, 2, 3, 6, 4, 9, 1, 7, 0};

	for (i = 0; i < (tam - 1); i++){
		min = i;
		for (j = (i + 1); j < tam; j++){
			if (v[j] < v[min]) {
				min = j;
				trocas++;
			}
		}
		aux = v[i];
		v[i] = v[min];
		v[min] = aux;
	}

	for (i = 0; i < tam; i++) printf("%d ", v[i]);
	printf("\n%d trocas realizadas\n", trocas);

	return 0;
}
