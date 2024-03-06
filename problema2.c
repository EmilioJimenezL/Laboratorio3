/*Estructuras de datos - LIS 2032-01
 * Nombres Completos: Emilio Ivan Jimenez Lopez 179543
 * Descripción breve del programa: Arbol
 * */
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

    // Insertar nodos en el árbol
    raiz = insertarNodo(raiz, 50);
    raiz = insertarNodo(raiz, 30);
    raiz = insertarNodo(raiz, 70);
    raiz = insertarNodo(raiz, 20);
    raiz = insertarNodo(raiz, 40);

    // Imprimir el árbol en In-orden
    printf("Arbol en In-orden: ");
    imprimirInOrden(raiz);
    printf("\n");

    // Buscar un valor/nodo
    int valorBuscado = 30;
    if (buscarNodo(raiz, valorBuscado)) {
        printf("El valor %d existe en el arbol.\n", valorBuscado);
    } else {
        printf("El valor %d no existe en el arbol.\n", valorBuscado);
    }

    // Encontrar el valor más pequeño del árbol
    printf("Valor minimo del arbol: %d\n", encontrarMinimo(raiz));

    // Encontrar el valor más grande del árbol
    printf("Valor mas grande del arbol: %d\n", encontrarMaximo(raiz));

    // Determinar la altura del árbol
    printf("Altura del arbol: %d\n", calcularAltura(raiz));

    // Imprimir el árbol en Pre-orden
    printf("Arbol en Pre-orden: ");
    imprimirPreOrden(raiz);
    printf("\n");

    // Imprimir el árbol en Post-orden
    printf("Arbol en Post-orden: ");
    imprimirPostOrden(raiz);
    printf("\n");

    // Eliminar un nodo
    int valorEliminar = 30;
    raiz = eliminarNodo(raiz, valorEliminar);

    // Imprimir el árbol después de eliminar un nodo
    printf("Arbol en In-orden despues de eliminar el nodo con valor %d: ", valorEliminar);
    imprimirInOrden(raiz);
    printf("\n");

    // Eliminar todo el árbol
    eliminarArbol(raiz);

    return 0;
}