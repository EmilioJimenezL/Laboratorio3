/*Estructuras de datos - LIS 2032-01
 * Nombres Completos: Emilio Ivan Jimenez Lopez 179543
 * Descripción breve del programa: Lista enlazada simple
 * */
//todo implementar insercion al final e intermedio, eliminar al inicio, final e intermedio
#include "stdio.h"
#include "stdlib.h"

struct node {
    int data;
    struct node *link;
};
void countNodes(struct node *head) {
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
        printf("%d\n", count);
    }
}
void printData(struct node *head) {
    int i = 1;
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
void insertAtEnd(struct node *head, int data){
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while (ptr->link != NULL){
        ptr=ptr->link;
    }
    ptr->link = temp;
}
struct node* insertAtStart(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    return head;
}
int main() {
    int menu, input;
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
                if(head == NULL){
                    head = malloc(sizeof(struct node));
                    printf("Ingrese el dato Int que desea almacenar:\n");
                    scanf("%i", &input);
                    head->data = input;
                    head->link = NULL;
                } else{
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
                            break;
                        default:
                            printf("Por favor ingrese un valor valido, regresando al menu...\n");
                            break;
                    }
                }
                break;
            case 2:
                if(head == NULL){
                    printf("La lista no existe, inserte un nodo primero\n");
                }
                printf("Que nodo desea eliminar?\n");
                break;
            case 3:
                if(head == NULL){
                    printf("La lista no existe, inserte un nodo primero\n");
                }else{
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
    } while (menu!=0);
    return 0;
}