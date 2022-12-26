// LISTA DE PESQUISA SEQUENCIAL E BINÁRIA
// Nome: Pedro Augusto Serafim Belo
// RA: 202003610
// QUESTÃO 04

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura de um nó
typedef struct node{
	int info;
	struct node * next;
} Node;

// Estrutura de uma lista encadeada
typedef struct list{
	int size;
	Node * head;
	Node * tail;
} List;


// Cria uma lista encadeada
List * createList();

// Insere um novo elemento ao final da lista
void insert(List * list, int value);

// Imprime todos os elementos de uma lista
void printList(List * list);

// Realiza a busca de uma elemento em uma lista
int searchList(List * list, int key);

// Libera a memória alocada de uma lista
void freeList(List * list);

int main(){
	int index, num, T = 10;
	List * list = createList();
	
	srand((unsigned)time(NULL));
	while (T > 0){
		num = rand() % 100;
		insert(list, num);
		T--;
	}

	printf("\nQuestao 04\n\n");
	printf("Lista com valores aleatorios:\n");
	printList(list);

	printf("\nEscolha um valor para realizar a busca: ");
	scanf("%d", &num);

	// O index inicia em 0 (zero)
	index = searchList(list, num);

	if (index == -1) printf("\nO valor nao foi encontrado na lista\n\n");
	else printf("\nO valor foi encontrado na posicao %d\n\n", index);

	freeList(list);
	return 0;
}

List * createList(){
	List * list = (List *) malloc(sizeof(List));
	list->head = NULL;
	list->tail = list->head;
	list->size = 0;
	return list;
}

void insert(List * list, int value){
	Node * node = (Node *) malloc(sizeof(Node));
	node->info = value;
	list->size += 1;

	if (list->size == 1){
		list->head = node;
		list->tail = list->head;
		return;
	}

	list->tail->next = node;
	list->tail = node;
}

void printList(List * list){
	if (list == NULL || list->head == NULL){
		printf("Lista vazia\n");
		return;
	}
	Node * node = list->head;
	while (node != NULL){
		printf("%d", node->info);
		if (node->next != NULL) printf(" -> ");
		node = node->next;
	}
	printf("\n");
}

int searchList(List * list, int key){
	int index = 0;
	Node * node = list->head;
	while (node != NULL){
		if (node->info == key) return index;
		node = node->next;
		index++;
	}
	return -1;
}

void freeList(List * list){
	if (list == NULL) return;
	Node * node = NULL;
	Node * prev = list->head;
	while (node != NULL){
		node = prev->next;
		free(prev);
		prev = node;
	}
	free(list);
}
