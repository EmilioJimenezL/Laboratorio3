/*Estructuras de datos - LIS 2032-01
 * Nombres Completos:
 * Emilio Ivan Jimenez Lopez
 * Hector Canizales Peña
 * Brandon Yahir Castro Ramos
 * Descripción breve del programa: Lista enlazada simple
 * */
#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *link;
};

int countNodes(struct node *head) {
    int count = 0;
    if (head == NULL) {
        printf("La lista esta vacia");
    } else {
        struct node *ptr = NULL;
        ptr = head;
        while (ptr != NULL) {
            count++;
            ptr = ptr->link;
        }
    }
    return count;
}

void printData(struct node *head) {
    int i = 0;
    if (head == NULL) {
        printf("La lista esta vacia");
    } else {
        struct node *ptr = head;
        while (ptr != NULL) {
            printf("%i: %i\n", i, ptr->data);
            ptr = ptr->link;
            i++;
        }
    }
}

void insertAtEnd(struct node *head, int data) {
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

struct node *insertAtStart(struct node *head, int data) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    return head;
}

void insertAtPosition(struct node *head, int position, int data) {
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;
    position--;
    while (position != 0) {
        ptr = ptr->link;
        position--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

struct node *delFirstNode(struct node *head) {
    struct node *temp = head;
    head = head->link;
    free(temp);
    return head;
}

void delLastNode(struct node *head) {
    if (head->link == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        while (temp->link->link != NULL) {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}

void delNodeAtPosition(struct node **head, int position) {
    struct node *current = *head;
    struct node *previous = *head;
    if (position == 0) {
        *head = current->link;
        free(current);
        current = NULL;
    } else {
        while (position != 0){
            previous = current;
            current = current->link;
            position--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}

int main() {
    int menu, input, position;
    struct node *head = NULL;
    printf("Bienvenido\n");
    do {
        printf("Seleccione que opcion desea realizar:\n");
        printf("1) Insertar un nodo\n");
        printf("2) Eliminar un nodo\n");
        printf("3) Imprimir la lista\n");
        printf("0) Salir\n");
        scanf("%i", &menu);
        switch (menu) {
            case 1:
                if (head == NULL) {
                    head = malloc(sizeof(struct node));
                    printf("Ingrese el dato Int que desea almacenar:\n");
                    scanf("%i", &input);
                    head->data = input;
                    head->link = NULL;
                } else {
                    printf("Donde desea insertar el nodo?\n");
                    printf("1) Al inicio\n");
                    printf("2) Al final\n");
                    printf("3) Despues de un nodo intermedio\n");
                    scanf("%i", &menu);
                    switch (menu) {
                        case 1:
                            printf("Ingrese el dato que desea almacenar\n");
                            scanf("%i", &input);
                            head = insertAtStart(head, input);
                            break;
                        case 2:
                            printf("Ingrese el dato Int que desea almacenar:\n");
                            scanf("%i", &input);
                            insertAtEnd(head, input);
                            break;
                        case 3:
                            if (countNodes(head) <= 1) {
                                printf("La lista solo tiene un nodo, inserte otro nodo al inicio o al final para poder insertar en una posicion intermedia\n");
                            } else {
                                printf("La lista tiene %i nodos, puede insertar un valor en una posicion del 1 al %i, inserte la posicion y el dato a insertar:\n",
                                       countNodes(head), countNodes(head) - 1);
                                scanf("%i", &position);
                                scanf("%i", &input);
                                insertAtPosition(head, position, input);
                            }
                            break;
                        default:
                            printf("Por favor ingrese un valor valido, regresando al menu...\n");
                            break;
                    }
                }
                break;
            case 2:
                if (head == NULL) {
                    printf("La lista no existe, inserte un nodo primero\n");
                }
                printf("Que nodo desea eliminar?\n");
                printf("1) El primer nodo\n");
                printf("2) El ultimo nodo\n");
                printf("3) Elegir un nodo intermedio\n");
                scanf("%i", &menu);
                switch (menu) {
                    case 1:
                        head = delFirstNode(head);
                        break;
                    case 2:
                        delLastNode(head);
                        break;
                    case 3:
                        printf("La lista tiene %i nodos, puede eliminar un valor en una posicion del 1 al %i, inserte la posicion que desea despejar:\n",
                               countNodes(head), countNodes(head) - 1);
                        scanf("%i", &position);
                        delNodeAtPosition(&head, position);
                        break;
                    default:
                        printf("Eliga un numero valido, regresando al menu...");
                        break;
                }
                break;
            case 3:
                if (head == NULL) {
                    printf("La lista no existe, inserte un nodo primero\n");
                } else {
                    printData(head);
                }
                break;
            case 0:
                printf("Saliendo...");
                break;
            default:
                printf("Ingrese un numero valido\n");
                break;
        }
    } while (menu != 0);
    return 0;
}