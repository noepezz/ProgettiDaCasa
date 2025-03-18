#include "../includes/push_swap.h"

bool rotate(nodo **lista)
{
    nodo *testa;
    nodo *coda;

    if (dimensioneLista(*lista) < 2)
        return (-1);
    testa = *lista;
    coda = ultimoNodo(testa);
    *lista = testa->next;
    testa->next = NULL;
    coda->next = testa;
    return (true);
}

bool ra(nodo **lista)
{
    if (rotate(lista) == false)
        return (false);
    printf("ra");
    return (true);
}


bool rb(nodo **lista)
{
    if (rotate(lista) == false)
        return (false);
    printf("rb");
    return (true);
}

bool rr(nodo **listaA, nodo **listaB)
{
    if ((dimensioneLista(*listaA) < 2) || (dimensioneLista(*listaB) < 2))
        return (false);
    rotate (listaA);
    rotate (listaA);
    printf("rr");
    return (true);
}
