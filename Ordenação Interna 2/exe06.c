// LISTA DE ORDENAÇÃO - BUBBLE E SHELL SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 06
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 5000

void bubbleSort(int v[], int size);
void shellSort(int v[], int size);

int main(){
	int i, v1[tam], v2[tam];
	double tempo;
	clock_t inicio, fim;

	srand((unsigned)time(NULL));

	for (i = 0; i < tam; i++){
		v1[i] = rand() % 100;
	}

	printf("QUESTAO 06\n\n");

	for (i = 0; i < tam; i++){
		v2[i] = v1[i];
	}
	
	inicio = clock();
	bubbleSort(v2, tam);
	fim = clock();

	tempo = ((double) (fim - inicio)/CLOCKS_PER_SEC);
	printf("Tempo demorado com Bubble sort: %lf segundos\n", tempo);

	for (i = 0; i < tam; i++){
		v2[i] = v1[i];
	}

	inicio = clock();
	shellSort(v2, tam);
	fim = clock();

	tempo = ((double) (fim - inicio)/CLOCKS_PER_SEC);
	printf("Tempo demorado com Shell sort: %lf segundos\n", tempo);

	return 0;
}

void bubbleSort(int v[], int size){
	int i, j, aux, flag;

	for (i = (size - 1); i > 0; i--){
		flag = 0;
		for (j = 0; j < i; j++){
			if (v[j] > v[j + 1]){
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
				flag = 1;
			}
		}
	}

}

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
			while (j > (h - 1) && valor <= v[j - h]){
				v[j] = v[j - h];
				j = j - h;
			}
			v[j] = valor;
		}
		h = h / 3;
	}


}
