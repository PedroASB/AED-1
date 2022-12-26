// LISTA DE PESQUISA SEQUENCIAL E BINÁRIA
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 03

#include <stdio.h>
#include <stdlib.h>

int t = 0;

// Pesquisa sequencial
int * linearSearch(int v[], int size, int key);

// Pesquisa binária
int * binarySearch(int v[], int size, int key);

// Imprime um vetor no terminal
void printArray(int v[], int size);

// Ordenação por quick sort
void quickSort(int v[], int start, int size);

int main(){
	int i, N, X;
	int * v = NULL;
	int * p = NULL;

	printf("\nQuestao 03\n\n");
	printf("Digite o tamanho do vetor a ser lido: ");
	scanf("%d", &N);

	v = (int *) calloc(N, sizeof(int));

	printf("Digite os elementos de forma ordenada:\n");
	for (i = 0; i < N; i++) scanf("%d", &v[i]);

	printf("\nVetor = {");
	printArray(v, N);
	printf("}\n\n");

	printf("Digite o valor a ser procurado: ");
	scanf("%d", &X);

	p = linearSearch(v, N, X);

	if (p == NULL) printf("\nBusca linear:\nValor %d nao encontrado\n", X);
	else {
		printf("\nBusca linear:\nValor %d encontrado nas posicoes: ", X);
		quickSort(p, 0, t);
		printArray(p, t);
		printf("\n");
	}

	p = binarySearch(v, N, X);

	if (p == NULL) printf("\nBusca binaria:\nValor %d nao encontrado\n", X);
	else {
		printf("\nBusca binaria:\nValor %d encontrado nas posicoes: ", X);
		quickSort(p, 0, t);
		printArray(p, t);
		printf("\n\n");
	}

	free(v);
	free(p);
	return 0;
}

int * linearSearch(int v[], int size, int key){
	int * p = NULL;
	int i;
	t = 0;

	for (i = 0; i < size; i++){
		if (v[i] == key) {
			t++;
			p = (int *) realloc(p, t*sizeof(int));
			p[t - 1] = i;
		}
	}

	return p;
}

int * binarySearch(int v[], int size, int key){
	int * p = NULL;
	int i, j, beg, end;
	t = 0;

	beg = 0;
	end = size - 1;

	while (beg <= end){
		i = beg + (end - beg) / 2;
		if (v[i] == key) {
			j = i;
			while (v[j] == key){
				p = (int *) realloc(p, (t + 1)*sizeof(int));
				p[t] = j;
				j--;
				t++;
			}
			j = i + 1;
			while (v[j] == key){
				p = (int *) realloc(p, (t + 1)*sizeof(int));
				p[t] = j;
				j++;
				t++;
			}
			return p;
		}
		if (v[i] < key) beg = i + 1;
		if (v[i] > key) end = i - 1;
	}

	return p;
}

void printArray(int v[], int size){
	if (size == 0) return;
	int i;
	for (i = 0; i < size; i++) {
		printf("%d", v[i]);
		if (i < size - 1) printf(", ");
	}
}


void quickSort(int v[], int start, int size){
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

}
