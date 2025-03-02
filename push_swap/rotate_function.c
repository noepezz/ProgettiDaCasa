#include "push_swap.h"

void rotate(nodo *lista)
{
    while (lista->next != NULL)
    { // si ferma senza contare l'ultimo
        swap(lista);
        lista = lista->next;
    }
}
void ra(nodo *listaA)
{
    rotate(listaA);
    printf("ra");
}
void rb(nodo *listaB)
{
    rotate(listaB);
    printf("rb");
}