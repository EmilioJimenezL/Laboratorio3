#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo del árbol
typedef struct Nodo {
    int valor;
    struct Nodo* izquierda;
    struct Nodo* derecha;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = valor;
    nuevoNodo->izquierda = nuevoNodo->derecha = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo en el árbol
Nodo* insertarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    if (valor < raiz->valor) {
        raiz->izquierda = insertarNodo(raiz->izquierda, valor);
    } else if (valor > raiz->valor) {
        raiz->derecha = insertarNodo(raiz->derecha, valor);
    }

    return raiz;
}

// Función para encontrar el valor más pequeño del árbol
int encontrarMinimo(Nodo* raiz) {
    if (raiz == NULL) {
        printf("El árbol está vacío.\n");
        return -1; // Puedes cambiar esto según tu lógica
    }

    while (raiz->izquierda != NULL) {
        raiz = raiz->izquierda;
    }

    return raiz->valor;
}

// Función para encontrar el valor más grande del árbol
int encontrarMaximo(Nodo* raiz) {
    if (raiz == NULL) {
        printf("El árbol está vacío.\n");
        return -1; // Puedes cambiar esto según tu lógica
    }

    while (raiz->derecha != NULL) {
        raiz = raiz->derecha;
    }

    return raiz->valor;
}

// Función para determinar la altura del árbol
int calcularAltura(Nodo* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int alturaIzquierda = calcularAltura(raiz->izquierda);
    int alturaDerecha = calcularAltura(raiz->derecha);

    return 1 + ((alturaIzquierda > alturaDerecha) ? alturaIzquierda : alturaDerecha);
}

// Función para imprimir el árbol en Pre-orden
void imprimirPreOrden(Nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimirPreOrden(raiz->izquierda);
        imprimirPreOrden(raiz->derecha);
    }
}

// Función para imprimir el árbol en In-orden
void imprimirInOrden(Nodo* raiz) {
    if (raiz != NULL) {
        imprimirInOrden(raiz->izquierda);
        printf("%d ", raiz->valor);
        imprimirInOrden(raiz->derecha);
    }
}

// Función para imprimir el árbol en Post-orden
void imprimirPostOrden(Nodo* raiz) {
    if (raiz != NULL) {
        imprimirPostOrden(raiz->izquierda);
        imprimirPostOrden(raiz->derecha);
        printf("%d ", raiz->valor);
    }
}

// Función para buscar un valor/nodo en el árbol
int buscarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return 0; // No se encontró el valor
    }

    if (raiz->valor == valor) {
        return 1; // Se encontró el valor
    } else if (valor < raiz->valor) {
        return buscarNodo(raiz->izquierda, valor);
    } else {
        return buscarNodo(raiz->derecha, valor);
    }
}

// Función para eliminar un nodo
Nodo* eliminarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->valor) {
        raiz->izquierda = eliminarNodo(raiz->izquierda, valor);
    } else if (valor > raiz->valor) {
        raiz->derecha = eliminarNodo(raiz->derecha, valor);
    } else {
        if (raiz->izquierda == NULL) {
            Nodo* temp = raiz->derecha;
            free(raiz);
            return temp;
        } else if (raiz->derecha == NULL) {
            Nodo* temp = raiz->izquierda;
            free(raiz);
            return temp;
        }

        Nodo* sucesor = raiz->derecha;
        while (sucesor->izquierda != NULL) {
            sucesor = sucesor->izquierda;
        }

        raiz->valor = sucesor->valor;
        raiz->derecha = eliminarNodo(raiz->derecha, sucesor->valor);
    }

    return raiz;
}

// Función para eliminar todo el árbol
void eliminarArbol(Nodo* raiz) {
    if (raiz != NULL) {
        eliminarArbol(raiz->izquierda);
        eliminarArbol(raiz->derecha);
        free(raiz);
    }
}

// Función principal
int main() {
    Nodo* raiz = NULL;
    int opcion, valor;

    do {
        // Menú interactivo
        printf("1. Insertar un nodo\n");
        printf("2. Eliminar un nodo\n");
        printf("3. Buscar un valor/nodo\n");
        printf("4. Encontrar el valor más pequeño del arbol\n");
        printf("5. Encontrar el valor más grande del arbol\n");
        printf("6. Determinar la altura del arbol\n");
        printf("7. Imprimir el arbol en Pre-orden\n");
        printf("8. Imprimir el arbol en In-orden\n");
        printf("9. Imprimir el arbol en Post-orden\n");
        printf("10. Eliminar todo el arbol\n");
        printf("0. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                raiz = insertarNodo(raiz, valor);
                break;
            case 2:
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &valor);
                raiz = eliminarNodo(raiz, valor);
                break;
            case 3:
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &valor);
                if (buscarNodo(raiz, valor)) {
                    printf("El valor %d existe en el arbol.\n", valor);
                } else {
                    printf("El valor %d no existe en el arbol.\n", valor);
                }
                break;
            case 4:
                printf("Valor minimo del arbol: %d\n", encontrarMinimo(raiz));
                break;
            case 5:
                printf("Valor mas grande del arbol: %d\n", encontrarMaximo(raiz));
                break;
            case 6:
                printf("Altura del arbol: %d\n", calcularAltura(raiz));
                break;
            case 7:
                printf("Arbol en Pre-orden: ");
                imprimirPreOrden(raiz);
                printf("\n");
                break;
            case 8:
                printf("Arbol en In-orden: ");
                imprimirInOrden(raiz);
                printf("\n");
                break;
            case 9:
                printf("Arbol en Post-orden: ");
                imprimirPostOrden(raiz);
                printf("\n");
                break;
            case 10:
                eliminarArbol(raiz);
                printf("El arbol ha sido eliminado.\n");
                break;
            case 0:
                // Salir del programa
                break;
            default:
                printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
        }
    } while (opcion != 0);

    return 0;
}
