// LISTA DE ORDENAÇÃO - SELECTION E INSERTION SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 06

#include <stdio.h>
#define tam 500

int comp = 0;
void insertionSort(int v[], int size);

int main(){
	int i;
	int N = tam - 1;
	int B[tam];

	printf("QUESTAO 06\n\n");

	for (i = 0; i < tam; i++){
		B[i] = N;
		N--;
	}

	insertionSort(B, tam);

	printf("Foram realizadas %d comparacoes para ordenar o vetor B\n\n", comp);

	printf("Resposta:\n");
	printf("O numero maximo de comparacoes em um algoritmo \n");
	printf("de insertion sort ocorre quando o vetor esta na ordem \n");
	printf("inversa, e, como esse algoritmo tem complexidade O(n^2) \n");
	printf("e o vetor B contem 500 elementos, conclui-se que \n");
	printf("seriam necessarias 500^2 = 250000 comparacoes.\n");

	return 0;
}

void insertionSort(int v[], int size){
	int i, j, aux;

	for (i = 1; i < size ; i++){
		comp++; // Uma comparação dentro do for
		j = i;
		while (j > 0 && v[j - 1] > v[j]){
			comp += 2; // Duas comparações dentro do while
			aux = v[j];
			v[j] = v[j - 1];
			v[j - 1] = aux;
			j--;
		}
	}
	comp++; // Comparação que encerra o laço for

}
