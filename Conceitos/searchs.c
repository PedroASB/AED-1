#include <stdio.h>
#include <stdlib.h>
#define N 10
// gcc Searchs.c -o Searchs && ./Searchs

// Linear Search
int linearSearch(int v[], int size, int key);

// Recursive Binary Search
int recursiveBinarySearch(int v[], int beg, int end, int key);

// Iterative Binary Search
int iterativeBinarySearch(int v[], int size, int key);

// Alternative Iterative Binary Search
int alt_iterativeBinarySearch(int v[], int size, int key);

int main(){
	system("clear");
	int i, s, v[N];

	for (i = 0; i < N; i++) v[i] = i;

	// s = linearSearch(v, N, 7);

	// s = recursiveBinarySearch(v, 0, N - 1, 7);

	// s = iterativeBinarySearch(v, N,	7);

	// s = alt_iterativeBinarySearch(v, N, 7);

	if (s == -1) printf("Valor não foi encontrado\n");
	else printf("Valor encontrado na posição %d\n", s);

	return 0;
}

int linearSearch(int v[], int size, int key){
	int i;
	for (i = 0; i < size; i++){
		if (v[i] == key) return i;
	}
	return -1;
}

int recursiveBinarySearch(int v[], int beg, int end, int key){
	int i;
	i = (beg + end) / 2;

	if (beg > end) return -1;
	if (v[i] == key) return i;
	else if (v[i] > key) recursiveBinarySearch(v, beg, i - 1, key);
	else if (v[i] < key) recursiveBinarySearch(v, i + 1, end, key);
}

int iterativeBinarySearch(int v[], int size, int key){
	int beg = 0;
	int end = size - 1;

	while (beg <= end) {
		int i = (beg + end) / 2;

		if (v[i] == key) return i;
		if (beg == end && end == i) return -1;

		if (v[i] < key) {
			beg = i + 1;
		} else {
			end = i;
		}
	}

}

int alt_iterativeBinarySearch(int v[], int size, int key){
	int i, beg, end;

	beg = 0;
	end = size - 1;

	while (beg <= end){
		i = beg + (end - beg) / 2;
		if (v[i] == key) return i;
		else if (v[i] < key) beg = i + 1;
		else if (v[i] > key) end = i - 1;
	}

	return -1;
}
