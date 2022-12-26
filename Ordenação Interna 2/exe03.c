// LISTA DE ORDENAÇÃO - BUBBLE E SHELL SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 03
#include <stdio.h>
#include <stdlib.h>

void recursive_bubble_sort(int v[], int i, int j){
	int aux;

	if (j < i) {
		if (v[j] > v[j + 1]){
			aux = v[j];
			v[j] = v[j + 1];
			v[j + 1] = aux;
		}
		j++;
	} else {
		i--;
		j = 0;
	}
	
	if (i > 0) recursive_bubble_sort(v, i, j);

	return;
}


int main(){
	int i, N;
	int * v = NULL;

	printf("QUESTAO 03\n\n");

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &N);

	v = (int*) calloc(N, sizeof(int));

	printf("Digite os elementos:\n");
	for (i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	recursive_bubble_sort(v, (N - 1), 0);

	printf("Vetor ordenado: {");
	for (i = 0; i < N; i++) {
		printf("%d", v[i]);
		if (i < N - 1) printf(", ");
	}
	printf("}\n");

	free(v);
	return 0;
}
