#include<stdlib.h>
#include<stdio.h>

struct Lista;

struct Lista {
	int value;
	struct Lista *next;
};

void addValueToList(struct Lista* lista,int value) {
	if (lista->next == NULL) {
		struct Lista* tempLista = (struct Lista*) malloc(sizeof(struct Lista));

		tempLista->value = value;
		tempLista->next = NULL;

		lista->next = tempLista;
	}
	else
	{
		addValueToList(lista->next, value);
	}

}

void viewList(struct Lista *lista){
	printf("%d\n",lista->value);
	if (lista->next)
	{
		viewList(lista->next);
	} 
}





void removeNextElement(struct Lista* lista, struct Lista* nextLista, int value) {
	if (nextLista == NULL) {
		return;
	}

	if (nextLista->value == value) {
		struct Lista* temp = nextLista;
		lista->next = nextLista->next;
		free(temp);
	}
	else
	{
		removeNextElement(nextLista, nextLista->next, value);
	}
}

void removeFirstElement(struct Lista* lista) {
	printf("Jestem tutaj \n");
	struct Lista *tmp = lista;
	*lista = *lista->next;
}


void removeElement(struct Lista* lista, int value) {
	if (lista->value == value) {
		removeFirstElement(lista);
	}
	else {
		removeNextElement(lista, lista->next, value);
	}
}


int main() {
	struct Lista lista;
	lista.value = 5;
	lista.next = NULL;


	addValueToList(&lista, 10);
	addValueToList(&lista, 15);
	addValueToList(&lista, 20);


	viewList(&lista);
	removeElement(&lista, 20);
	removeElement(&lista, 5);
	viewList(&lista);



	

	return 0;
}