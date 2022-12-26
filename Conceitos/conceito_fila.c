#include <stdio.h>
#include <stdlib.h>

// gcc conceitoFila.c -o conceitoFila
// ./conceitoFila

typedef struct no{
	int info;
	struct no *link;
} fila;

fila *p, *q, *ini, *fim;

int main(){
	int aux = 0;
	p = NULL;
	q = NULL;
	ini = NULL;

	printf("\nColocando na Fila\n");
	for (int i = 0; i < 10; i++) {
		p = (fila *)malloc(sizeof(fila));
		p->link = NULL;
		p->info = i;
		if (q != NULL) {
			q->link = p;
		}
		fim = p;
		if (ini == NULL) {
			ini = p;
		}
		q = p;
		printf("%d -> ", p->info);
	}

	printf("\nRetirando da Fila\n");
	p = ini;
	while (p != NULL) {
		printf("%d -> ", p->info);
		p = p->link;
	}

	free(p);
	printf("\n\n");
}
