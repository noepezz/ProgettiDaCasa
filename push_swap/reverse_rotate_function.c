#include "push_swap.h"

void reverseRotate(nodo *lista)
{
    // DA rifare
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

void rrr(nodo *listaA, nodo *listaB)
{
    rra(listaA);
    rrb(listaB);
    printf("rrr");
}