/*Estructuras de datos - LIS 2032-01
 * Nombres Completos:
 * Emilio Ivan Jimenez Lopez
 * Hector Canizales Peña
 * Brandon Yahir Castro Ramos
 * Descripción breve del programa: Lista circular doblemente enlazada

	     * • Insertar un nodo al inicio
	     * • Insertar un nodo al final
	     * • Insertar un nodo intermedio
	     * • Eliminar un nodo al inicio
	     * • Eliminar un nodo al final
	     * • Eliminar un nodo intermedio
	     * • Imprimir los elementos de la lista
	     *
*/
#include "stdio.h"
#include "stdlib.h"


// debugging
// src: https://stackoverflow.com/a/1644898
// function debug_print() must take at least TWO arguments
// set DEBUG to 1 to print debug_print() to stderr
#define DEBUG 1
#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr, fmt, __VA_ARGS__); } while (0)

struct node {
    int data;
    struct node *prevLink;
    struct node *nextLink;
};

int isEmpty(struct node*);

void printList(struct node *tail) {
    if(tail == NULL){
    	printf("\nLISTA esta VACIA!\n\n");
	return;
    }	
    debug_print("tail is %d\n", tail->data);
    
    printf("\n");

    int i = 0;
    struct node *temp = tail;
    do {
	if(i > 5){
		printf("StOPPING...\n");
		return;
	}
        printf("[%i]: %i\n", i, temp->data);
        temp = temp->nextLink;
        i++;
    } while (temp != tail);
    printf("\n");

}


struct node *createNode(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->prevLink = temp;
    temp->nextLink = temp;
    temp->data = data;
    return temp;
}

/*
 */
struct node *insertAtStart(struct node *tail, int data) {
    if(isEmpty(tail)){
	printf("LISTA esta VACIA, creando nodo\n");
	return createNode(data);
    }
    struct node *new = createNode(data);
    //struct node *temp = tail;
    new->prevLink = tail->prevLink;
    new->prevLink->nextLink = new;
    new->nextLink = tail;
    tail->prevLink = new;
    return new;
}


/*
 */
struct node *insertAtEnd(struct node *tail, int data) {
    if(isEmpty(tail)){
	printf("LISTA esta VACIA, creando nodo\n");
	return createNode(data);
    }

//    struct node *temp = tail->nextLink;
//    do {
//        //printf("[%i]: %i\n", i, temp->data);
//        temp = temp->nextLink;
//    } while (temp != tail->nextLink);
//    struct node *end = temp->prevLink;
//
//    struct node *new = createNode(data);
//
//    new->prevLink = end;
//    new->nextLink = end->nextLink;
//    new->nextLink->prevLink = new;
//    end->nextLink = new;
//
//    return tail;

    // turns out you don't need that much code to insert a node at the end of a circular doubly linked list
    // just insert at start and return the next node as if the new node were the end now.
    struct node *temp = insertAtStart(tail, data);
    return temp->nextLink;
}

/*
 */
struct node *insertAfterNode(struct node *tail, int data, int sourceNodeData) {
    debug_print("*********\n", 0);
    //printList(tail);
    debug_print("tail data is %d\n", tail->data);
    if(isEmpty(tail)){
	printf("LISTA esta VACIA, creando nodo\n");
	return createNode(data);
    }

    struct node *temp = tail;
    while(temp->data != sourceNodeData) {
        temp = temp->nextLink;
    }
    struct node *sourceNode = temp;

    struct node *new = createNode(data);

    new->prevLink = sourceNode;
    new->nextLink = sourceNode->nextLink;
    new->nextLink->prevLink = new;
    sourceNode->nextLink = new;

    return tail;
}

/*
 */
struct node *insertBeforeNode(struct node *tail, int data, int sourceNodeData) {
    debug_print("*********\n", 0);
    //printList(tail);
    debug_print("tail data is %d\n", tail->data);
    if(isEmpty(tail)){
	printf("LISTA esta VACIA, creando nodo\n");
	return createNode(data);
    }

    struct node *temp = tail;
    while(temp->data != sourceNodeData) {
        //printf("[%i]: %i\n", i, temp->data);
        temp = temp->nextLink;
    }
    struct node *sourceNode = temp->prevLink;

    struct node *new = createNode(data);

    new->prevLink = sourceNode;
    new->nextLink = sourceNode->nextLink;
    new->nextLink->prevLink = new;
    sourceNode->nextLink = new;

    return tail;
}


/*
 * Assumes non-NULL tail
 */
struct node *deleteNode(struct node *tail, int valueToDelete){
	struct node *firstTail = tail;
	printf("Deleting node with value %d...\n\n", valueToDelete);
	while(tail->data != valueToDelete){
		tail = tail->nextLink;
	}
	struct node *previous = tail->prevLink;
	struct node *next = tail->nextLink;

	debug_print("Previous is %d\n", previous->data);
	debug_print("Next is %d\n", next->data);

	// if exactly one element, delete (free) ourselves and return NULL
	if(previous == next && next == tail){
		free(tail);
		return NULL;
	}
	previous->nextLink = next;
	next->prevLink = previous;

	// means we're killing first element
	if(firstTail == tail){
		free(tail);
		return next;
	}

	free(tail);

	return firstTail;

}


/*
 * Assumes non-NULL tail
 */
struct node *deleteFirstNode(struct node *tail){
	return deleteNode(tail, tail->data);
}


/*
 * Assumes non-NULL tail
 */
struct node *deleteLastNode(struct node *tail){
	struct node *firstTail = tail;

	//last node is the previous node to the first node.
	tail = tail->prevLink;

	printf("Deleting node with value %d...\n\n", tail->data);

	struct node *previous = tail->prevLink;
	struct node *next = tail->nextLink;

	debug_print("Previous is %d\n", previous->data);
	debug_print("Next is %d\n", next->data);

	// if exactly one element, delete (free) ourselves and return NULL
	if(previous == next && next == tail){
		free(tail);
		return NULL;
	}
	previous->nextLink = next;
	next->prevLink = previous;

	// means we're killing first element
	if(firstTail == tail){
		free(tail);
		return next;
	}

	free(tail);

	return firstTail;

}

int isEmpty(struct node *tail){
	return (tail == NULL)?1:0;
}

int main() {
    int menu;
    struct node *tail = NULL;
    printList(tail);
    //tail = createNode(1);
    //tail = insertAtStart(tail, 0);
    //debug_print("^^tail is %d\n", tail->data);

    printf("Bienvenido\n");
    do {
	    /*
	     * • Insertar un nodo al inicio
	     * • Insertar un nodo al final
	     * • Insertar un nodo intermedio
	     * • Eliminar un nodo al inicio
	     * • Eliminar un nodo al final
	     * • Eliminar un nodo intermedio
	     * • Imprimir los elementos de la lista
	     * */
        printf("Que accion desea realizar?\n");
        printf("1) Insertar\n");
        printf("2) Eliminar\n");
        printf("3) Imprimir\n");
        printf("4) Eliminar primer nodo\n");
        printf("5) Eliminar ultimo nodo\n");
        printf("0) Salir\n");
        scanf("%i", &menu);
        switch (menu) {
            case 1:
		    printf("1) Insertar un nodo al inicio\n");
		    printf("2) Insertar un nodo al final\n");
		    printf("3) Insertar un nodo despues de otro nodo\n");
		    printf("4) Insertar un nodo antes de otro nodo\n");
		    printf("0) Regresar\n");
		    scanf("%i", &menu);
		    switch(menu){
			case 1:
				{
				int inputInsertar;
				printf("Ingrese el valor del elemento a insertar al inicio:\n");
				scanf("%i", &inputInsertar);
				tail = insertAtStart(tail, inputInsertar);
				printList(tail);
		    		}

				    break;
			case 2:
				{
				int inputInsertar;
				printf("Ingrese el valor del elemento a insertar al final:\n");
				scanf("%i", &inputInsertar);
				tail = insertAtEnd(tail, inputInsertar);
				printList(tail);
				}

				    break;
			case 3:
				{
				int inputInsertar, afterNodeValue;
				printf("Ingrese el valor del elemento a insertar seguido de el valor del nodo raiz (new src):\n");
				scanf("%i %i", &inputInsertar, &afterNodeValue);
				debug_print("%d %d\n", inputInsertar, afterNodeValue);
				tail = insertAfterNode(tail, inputInsertar, afterNodeValue);
				printList(tail);
				
				}
				    break;
			case 4:
				{
				int inputInsertar, beforeNodeValue;
				printf("Ingrese el valor del elemento a insertar seguido de el valor del nodo raiz (new src):\n");
				scanf("%i %i", &inputInsertar, &beforeNodeValue);
				tail = insertBeforeNode(tail, inputInsertar, beforeNodeValue);
				printList(tail);
				
				}
				    break;
			default:
				printf("OPCION invalida\n");
				break;
		    }


                break;
            case 2:
		if(isEmpty(tail)){
		    printf("no se puede eliminar, LISTA esta VACIA!\n");
		    break;
		}
		int inputEliminar;
		printf("Ingrese el valor del elemento a eliminar:\n");
		scanf("%i", &inputEliminar);

		tail = deleteNode(tail, inputEliminar);
		printList(tail);

                break;
            case 3:
		printList(tail);
                break;
	    case 4:
		if(isEmpty(tail)){
			printf("no se puede eliminar, LISTA esta VACIA!\n");
			break;
		}
		tail = deleteFirstNode(tail);
		printList(tail);
		break;
	    case 5:
		if(isEmpty(tail)){
			printf("no se puede eliminar, LISTA esta VACIA!\n");
			break;
		}
		tail = deleteLastNode(tail);
		printList(tail);
		break;
            default:
                printf("Ingrese un numero valido\n");
                break;
        }
    } while (menu != 0);
    printf("Saliendo...\n");
    //TODO: free memory all nodes
 
    return 0;
}
