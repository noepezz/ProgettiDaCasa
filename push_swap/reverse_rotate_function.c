#include "push_swap.h"

void reverseRotate(nodo *lista)
{
    while (lista->prev != NULL)
    { // si ferma senza contare l'ultimo
        swap(lista);
        lista = lista->prev;
    }
}

static void rra(nodo *listaA)
{
    reverseRotate(listaA);
    printf("rra");
}

static void rrb(nodo *listaB)
{
    reverseRotate(listaB);
    printf("rrb");
}