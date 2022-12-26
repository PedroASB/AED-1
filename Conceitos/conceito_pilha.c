#include <stdio.h>
#include <stdlib.h>

// gcc conceitoPilha.c -o conceitoPilha && ./conceitoPilha

typedef struct no {
	int info;
	struct no *link;
} pilha;

pilha *p, *q, *topo;
// int j;
int main(){
	p = NULL;
	q = NULL;
	topo = NULL;

	printf("\n\nEmpilhando os elementos...\n");
	for (int i = 0; i < 10; i++) {
		p = (pilha *) malloc(sizeof(pilha));
		p->info = i;
		p->link = q;
		topo = p;
		q = p;
		printf(" <- %d", p->info);
	}

	p = topo;
	printf("\n\nDesempilhando os elementos...\n\n");
	while (p != NULL) {
		printf("%d -> ", p->info);
		p = p->link;
	}
	printf("\n\n");

	p = topo;
	q = p->link;
	while (q != NULL) {
		free(p);
		p = q;
		q = q->link;
	}
	q = NULL;
	p = NULL;
	return 0;
}
