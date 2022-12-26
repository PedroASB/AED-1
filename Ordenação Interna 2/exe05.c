// LISTA DE ORDENAÇÃO - BUBBLE E SHELL SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 05
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 100

// Shell Sort em ordem decrescente
void shellSort(int v[], int size){
	int i, j, valor;
	int h = 1;

	while (h < size){
		h = 3*h + 1;
	}
	
	while (h > 0){
		for (i = h; i < size; i++){
			valor = v[i];
			j = i;
			while (j > (h - 1) && valor > v[j - h]){
				v[j] = v[j - h];
				j = j - h;
			}
			v[j] = valor;
		}
		h = h / 3;
	}

}

int main(){
	int i;
	int v[tam];

	srand((unsigned)time(NULL));

	for (i = 0; i < tam; i++){
		v[i] = rand() % 100;
	}

	printf("\nQUESTAO 05\n");

	printf("\nVetor = {");
	for (i = 0; i < tam; i++){
		printf("%d", v[i]);
		if (i < tam - 1) printf(", ");
	}
	printf("}\n\n");

	shellSort(v, tam);

	printf("Ordem decrescente: {");
	for (i = 0; i < tam; i++){
		printf("%d", v[i]);
		if (i < tam - 1) printf(", ");
	}
	printf("}\n\n");

	return 0;
}
