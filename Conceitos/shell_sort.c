// SHELL SORT
#include <stdio.h>

#define tam 10

// void shellSort(int v[], int size);

int main(){

	int i, j, valor, trocas = 0;
	int h = 1;
	int v[tam] = {5, 8, 2, 3, 6, 4, 9, 1, 7, 0};

	while (h < tam){
		h = 3*h + 1;
	}

	while (h > 0){
		for (i = h; i < tam; i++){
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

	for (i = 0; i < tam; i++) printf("%d ", v[i]);
	printf("\n%d trocas realizadas\n", trocas);

	return 0;
}
