// LISTA DE PESQUISA SEQUENCIAL E BINÁRIA
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 01 - letra a

#include <stdio.h>
#define N 8

int comp_linear = 0;
int comp_binary = 0;

// Pesquisa sequencial
int linearSearch(int v[], int size, int key);

// Pesquisa binária (recursiva)
int binarySearch(int v[], int beg, int end, int key);

int main(){
	int i, p;
	int v[N] = {2, 7, 11, 33, 54, 85, 90, 115};

	printf("\nQuestao 01 - letra a\n\n");
	printf("Vetor = {2, 7, 11, 33, 54, 85, 90, 115}\n\n");

	p = linearSearch(v, N, 54);
	printf("Busca linear:\nValor 54 encontrado na posicao %d\n", p);
	printf("Foram realizadas %d comparacoes\n\n", comp_linear);

	p = binarySearch(v, 0, N - 1, 54);
	printf("Busca binaria:\nValor 54 encontrado na posicao %d\n", p);
	printf("Foram realizadas %d comparacoes\n\n", comp_binary);

	return 0;
}

int linearSearch(int v[], int size, int key){
	int i;
	for (i = 0; i < size; i++){
		comp_linear += 1;
		if (v[i] == key) return i;
	}
	return -1;
}

int binarySearch(int v[], int beg, int end, int key){
	int i;
	i = (beg + end) / 2;
	
	if (beg > end) {
		comp_binary++;
		return -1;
	}

	if (v[i] == key) {
		comp_binary++;
		return i;
	} 
	else if (v[i] > key) {
		comp_binary++;
		binarySearch(v, beg, i - 1, key);
	} 
	else if (v[i] < key) {
		comp_binary++;
		binarySearch(v, i + 1, end, key);
	}

}
