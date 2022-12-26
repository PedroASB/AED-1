#include "library.h"

int sum(int x, int y);

int function(int n, int (*f)(int x, int y));

// (int sum) * (anotherFunction(int a);

int main(){
	int x, y, n, k;
	scanf("%d", &n);
	k = function(n, sum);
	printf("k = %d\n", k);
	return 0;
}

int sum(int x, int y){
	return x + y;
}

int function(int n, int (*f)(int x, int y)){
	int k;
	k = n + f(2, 5);
	return k;
}
