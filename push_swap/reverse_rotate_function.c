#include "push_swap.h"

void reverseRotate(nodo *lista)
{
    while (lista->prev != NULL)
    { // si ferma senza contare l'ultimo
        swap(lista);
        lista = lista->prev;
    }
}

void rra(nodo *listaA)
{
    reverseRotate(listaA);
    printf("rra");
}

void rrb(nodo *listaB)
{
    reverseRotate(listaB);
    printf("rrb");
}