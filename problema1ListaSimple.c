/*Estructuras de datos - LIS 2032-01
 * Nombres Completos: Emilio Ivan Jimenez Lopez 179543
 * Descripción breve del programa: Lista enlazada simple
 * */
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
    if (head == NULL) {
        printf("La lista esta vacia");
    } else {
        struct node *ptr = head;
        while (ptr != NULL) {
            printf("%d\n", ptr->data);
            ptr = ptr->link;
        }
    }
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;
    struct node *node1 = malloc(sizeof(struct node));
    node1->data = 2;
    node1->link = NULL;
    head->link = node1;
    struct node *node2 = malloc(sizeof(struct node));
    node2->data = 3;
    node2->link = NULL;
    node1->link = node2;
    head->link->link = node2;
    countNodes(head);
    printData(head);
    return 0;
}