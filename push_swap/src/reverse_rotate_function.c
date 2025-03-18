#include "../includes/push_swap.h"

bool reverseRotate(nodo **lista)
{
    nodo *testa;
    nodo *coda;

    if (dimensioneLista(*lista) < 2)
        return false;
    testa = *lista;
    coda = ultimoNodo(testa);
    while(testa)
    {
        if (testa->next->next == NULL)
        {
            testa->next = NULL;
            break  ;
        }
        testa = testa->next;
    }
    coda->next = *lista;
    *lista = coda;
    return (true);
}

bool rra(nodo **listaA)
{
    if(reverseRotate(listaA) == false)
        return false;
    printf("rra");
    return true;
}
bool rrb(nodo **listaB)
{
    if(reverseRotate(listaB) == false)
        return false;
    printf("rrb");
    return true;
}

bool rrr(nodo **listaA, nodo **listaB)
{
    if ((dimensioneLista(*listaA) < 2) || (dimensioneLista(*listaB) < 2))
        return false; 
    rra(listaA);
    rrb(listaB);
    printf("rrr");
    return true;
}
