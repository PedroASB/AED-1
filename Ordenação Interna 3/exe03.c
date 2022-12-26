// LISTA DE ORDENAÇÃO - QUICK E HEAP SORT
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 03
#include <stdio.h>
#include <string.h>
#define tam 10

// gcc exe03.c -o exe03 && ./exe03

void quickSort(char str[tam][20], int start, int size);

int main(){
	int i;

	char nomes[tam][20] = {"Julia\0", "Fernanda\0", "Carlos\0", "Pedro\0", "Isadora\0",
	"Amanda\0", "Felipe\0", "Joao Pedro\0", "Thiago\0",  "Joao\0"};

	printf("\nQUESTAO 03\n\n");

	printf("Nomes desordenados:\n");
	for (i = 0; i < tam; i++){
		printf("%s", nomes[i]);
		if (i < tam - 1) printf(", ");
	}
	printf("\n\n");

	quickSort(nomes, 0, tam);

	printf("Nomes ordenados:\n");
	for (i = 0; i < tam; i++){
		printf("%s", nomes[i]);
		if (i < tam - 1) printf(", ");
	}
	printf("\n");

	return  0;
}

void quickSort(char str[tam][20], int start, int size){
	int i, j, cont;
	char aux[20], pivot[20];
	i = start;
	j = size - 1;

	strcpy(pivot, str[(start + size) / 2]);

	while (i <= j){
		while ((strcmp(str[i], pivot) < 0) && i < size){
			i++;
		}
		while ((strcmp(str[j], pivot) > 0) && j > start){
			j--;
		}

		if (i <= j){
			if (i < j){
				strcpy(aux, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], aux);
			}
			i++;
			j--;
		}

	}

	if (j > start){
		quickSort(str, start, j + 1);
	}
	if (i < size){
		quickSort(str, i, size);
	}

	return;
}
