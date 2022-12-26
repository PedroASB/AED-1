// LISTA DE ORDENAÇÃO - SELECTION E INSERTION SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 02

#include <stdio.h>
#include <stdlib.h>

/*
Este algoritmo seleciona o maior elemento e 
o coloca no final do vetor, a cada iteração.
Esta variante do selection sort não altera a
complexidade do algoritmo: permanece O(n^2)
pois há sempre a execução de dois laços de 
repetição para encontrar, nesse caso, o maior
elemento e jogá-lo no final do vetor.
*/
void selectionSort(int v[], int size){
	int i, j;
	int max, aux;
	
	for (i = (size - 1); i > 0; i--){
		max = i;
		for (j = (i - 1); j >= 0; j--){
			if (v[j] > v[max]) {
				max = j;
			}
		}
		aux = v[i];
		v[i] = v[max];
		v[max] = aux;
	}
}

int main(){
	int i, N;
	int * v = NULL;

	printf("QUESTAO 02\n");

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &N);

	v = (int *) calloc(N, sizeof(int));

	printf("Digite os elementos do vetor:\n");
	for (i = 0; i < N; i++){
		scanf("%d", &v[i]);
	}

	selectionSort(v, N);

	printf("Os elementos em ordem são:\n");
	for (i = 0; i < N; i++){
		printf("%d ", v[i]);
	}
	printf("\n");

	printf("Resposta: Essa variante do selection sort nao altera \n");
	printf("a complexidade do algoritmo: permanece O(n^2), \n");
	printf("pois ha sempre a execucao de dois lacos de \n");
	printf("repeticao para encontrar, nesse caso, o maior \n");
	printf("elemento e joga-lo no final do vetor.\n");

	free(v);
	return 0;
}
