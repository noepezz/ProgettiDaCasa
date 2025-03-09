#include "push_swap.h"

void push(nodo **a, nodo **b)
{
    if (*a == NULL)
        return;

    int *oggetto = rimuoviInTesta2(a);
    if (oggetto)
    {
        if (*b == NULL)
        {
            *b = crea_nodo(*oggetto);
        }
        else
        {
            inserisciInTesta(b, *oggetto);
        }
        free(oggetto);
    }
}
static void pa(nodo **listaA, nodo **listaB)
{
    push(listaA, listaB);
    printf("pa");
}
static void pb(nodo **listaB, nodo **listaA)
{
    push(listaB, listaA);
    printf("pb");
}
