#include "library.h"
#define TAM 10

// gcc conceitoLista.c library.c -o conceitoLista && ./conceitoLista

typedef struct no{
	int info;
	// union {
	// 	char caracter;
	// } elemento;
	struct no *link;
} lista;

lista *p, *q, *prim;
int qtd = 0;

void inserir(int num);

void imprime(void);

void excluir(int num);

void libera(lista * p);

int main() {
	system("clear");
	prim = NULL;

	printf("\nInforme a quantidade de no\'s(elementos): ");
	scanf("%u", &qtd);

	for (int i = 1; i <= qtd; i++) {
		inserir(64 + i);
	}
	printf("\n");

	imprime();
	libera(p);
	printf("\n");
	imprime();

	printf("\nFim da lista\n\n");
return 0;
}

void inserir(int num) {
	p = (lista*) malloc(sizeof(lista));
	p->info = num;
	
	p->link = NULL;
	if (prim == NULL) {
		prim = p;
	} else {
		q->link = p;
	}
	q = p;
}

void imprime(){
	if (prim == NULL) {
		printf("Lista vazia\n");
		return;
	}
	p = prim;
	while (1){
		printf("%d", p->info);
		if (p->link == NULL) break;
		printf(" ► ");
		p = p->link;
	}
}

void excluir(int num) {
	p = prim;
	while (p != NULL) {
		if (p->info == num) {
			q->link = p->link;
			free(p);
		}
		q = p;
		p = p->link;
	}
}
 
void libera(lista * p){
	// p = prim;

	// if (p->link == NULL){
	// 	free(p);
	// } else if {
	// 	(p->info == prim->info){
	// 		free(p){

	// 		}
	// 	}
	// }

	// libera(p->link);
}

void observacoes(void){
	/*
	typedef struct elemento{
		int valor;
		struct elemento * prox;
	} Elem;

	typedef struct elemento * Lista;
	// Lista é um "conjunto" de elementos

	Lista * lista1; 
	// "Conjunto" de listas ("conjunto" de "conjunto" de elementos)
	// struct elemento ** lista2;
	// Elem ** lista3;

	// (15)--(NULL)
	*/
}
