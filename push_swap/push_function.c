#include "push_swap.h"

void push(nodo **a, nodo **b)
{
    if (*a == NULL)
        return;

    int *oggetto = rimuoviInTesta(a);
    if (oggetto)
    {
        inserisciInTesta(b, *oggetto);
        free(oggetto);
    }
}
void pa(nodo **listaA, nodo **listaB)
{
    push(listaA, listaB);
    printf("pa");
}
void pb(nodo **listaA, nodo **listaB)
{
    push(listaB, listaA);
    printf("pb");
}