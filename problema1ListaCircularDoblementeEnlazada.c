/*Estructuras de datos - LIS 2032-01
 * Nombres Completos: Emilio Ivan Jimenez Lopez 179543
 * Descripción breve del programa: Lista circular doblemente enlazada
 * */
#include "stdio.h"
#include "stdlib.h"
struct node{
    int data;
    struct node *prevLink;
    struct node *nextLink;
};
