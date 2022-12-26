// INSERTION SORT
#include <stdio.h>

#define tam 10

// void insertionSort(int v[], int size);

int main(){

	int i, j, aux, trocas = 0;
	int v[tam] = {5, 8, 2, 3, 6, 4, 9, 1, 7, 0};

	for (i = 1; i < tam ; i++){
		j = i;
		while (j > 0 && v[j - 1] > v[j]){
			aux = v[j];
			v[j] = v[j - 1];
			v[j - 1] = aux;
			j--;
			trocas++;
		}

	}

	for (i = 0; i < tam; i++) printf("%d ", v[i]);
	printf("\n%d trocas realizadas\n", trocas);

	return 0;
}
