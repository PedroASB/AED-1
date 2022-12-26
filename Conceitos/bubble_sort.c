// BUBBLE SORT
#include <stdio.h>

#define tam 10

// void bubbleSort(int v[], int size);

int main(){

	int i, j, aux, trocas = 0;
	int v[tam] = {5, 8, 2, 3, 6, 4, 9, 1, 7, 0};

	for (i = (tam - 1); i > 0; i--){
		for (j = 0; j < i; j++){
			if (v[j] > v[j + 1]){
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
				trocas++;
			}
		}
	}

	for (i = 0; i < tam; i++) printf("%d ", v[i]);
	printf("\n%d trocas realizadas\n", trocas);

	return 0;
}
