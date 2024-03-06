/*Estructuras de datos - LIS 2032-01
 * Nombres Completos: Emilio Ivan Jimenez Lopez 179543
 * Descripción breve del programa: Lista circular doblemente enlazada
 * */
#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *prevLink;
    struct node *nextLink;
};

void printList(struct node *tail) {
    int i = 0;
    struct node *temp = tail->nextLink;
    do {
        printf("%i: %i", i, temp->data);
        temp = temp->nextLink;
        i++;
    } while (temp != tail->nextLink);
}

struct node *createNode(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->prevLink = temp;
    temp->nextLink = temp;
    temp->data = data;
    return temp;
}

struct node *insertAtStart(struct node *tail, int data) {
    struct node *new = createNode(data);
    struct node *temp = tail->nextLink;
    new->prevLink = tail;
    new->nextLink = temp;
    temp->prevLink = new;
    tail->nextLink = new;
    return tail;
}

int main() {
    int menu;
    struct node *tail = NULL;
    printf("Bienvenido\n");
    do {
        printf("Que accion desea realizar?\n");
        printf("1) Insertar");
        printf("2) Eliminar");
        printf("3) Imprimir");
        printf("0) Salir");
        scanf("%i", &menu);
        switch (menu) {
            case 1:

                break;
            case 2:
                break;
            case 3:
                if(tail == NULL){

                }
                break;
            default:
                printf("Ingrese un numero valido\n");
                break;
        }
    } while (menu != 0);
    return 0;
}
