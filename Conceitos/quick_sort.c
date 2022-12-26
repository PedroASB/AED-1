// QUICK SORT
#include <stdio.h>
#define tam 10
int trocas = 0;

int quickSort(int v[], int start, int size){
	int i, j, aux, pivot;
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
				trocas++;
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

	return trocas;
}

int main(){
	int i, trocas;
	int v[tam] = {5, 8, 2, 3, 6, 4, 9, 1, 7, 0};

	trocas = quickSort(v, 0, tam);

	for (i = 0; i < tam; i++) printf("%d ", v[i]);
	printf("\n%d trocas realizadas\n", trocas);

	return 0;
}
