// LISTA DE ORDENAÇÃO - BUBBLE E SHELL SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 01
#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int v[], int size){
	int i, j, aux, flag, trocas = 0;
	
	for (i = (size - 1); i > 0; i--){
		flag = 0;
		for (j = 0; j < i; j++){
			if (v[j] > v[j + 1]){
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
				trocas++;
				flag = 1;
			}
		}
		if (flag == 0) return trocas;
	}
	return trocas;
}

int main(){
	int i, N, trocas;
	int * v = NULL;

	printf("QUESTAO 01\n\n");

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &N);

	v = (int*) calloc(N, sizeof(int));

	printf("Digite os elementos:\n");
	for (i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	printf("\n");

	trocas = bubbleSort(v, N);

	if (trocas == 0) printf("O vetor ja estava ordenado:\n");
	else printf("Foram realizadas %d trocas para ordenar o vetor:\n", trocas);

	printf("{");
	for (i = 0; i < N; i++) {
		printf("%d", v[i]);
		if (i < N - 1) printf(", ");
	}
	printf("}\n");

	free(v);
	return 0;
}
