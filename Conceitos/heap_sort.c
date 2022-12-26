// HEAP SORT
#include <stdio.h>

#define tam 10

int trocas = 0;

void swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	trocas++;
}

void heapify(int v[], int n, int i){
	int max = i;
	int leftChild = 2*i + 1;
	int rightChild = 2*i + 2;

	if (leftChild < n && v[leftChild] > v[max]){
		max = leftChild;
	}
	if (rightChild < n && v[rightChild] > v[max]){
		max = rightChild;
	}

	if (max != i){
		swap(&v[i], &v[max]);
		heapify(v, n, max);
	}
}

void heapSort(int v[], int n){
	int i;
	for (i = (n / 2 - 1); i >= 0; i--){
		heapify(v, n, i);
	}
	for (i = (n - 1); i >= 0; i--){
		swap(&v[0], &v[i]);
		heapify(v, i, 0);
	}
}

int main(){

	int i;
	int v[10] = {5, 8, 2, 3, 6, 4, 9, 1, 7, 0};

	heapSort(v, tam);

	for (i = 0; i < 10; i++) printf("%d ", v[i]);
	printf("\n%d trocas realizadas\n", trocas);

	return 0;
}
