#include "../includes/push_swap.h"

bool rotate(t_nodo **lista)
{
    t_nodo *testa;
    t_nodo *coda;

    if (dimensione_lista(*lista) < 2)
        return (false);
    testa = *lista;
    coda = ultimo_t_nodo(testa);
    *lista = testa->next;
    testa->next = NULL;
    coda->next = testa;
    return (true);
}

bool ra(t_nodo **lista)
{
    if (rotate(lista) == false)
        return (false);
    printf("ra\n");
    return (true);
}


bool rb(t_nodo **lista)
{
    if (rotate(lista) == false)
        return (false);
    printf("rb\n");
    return (true);
}

bool rr(t_nodo **listaA, t_nodo **listaB)
{
    if ((dimensione_lista(*listaA) < 2) || (dimensione_lista(*listaB) < 2))
        return (false);
    rotate (listaA);
    rotate (listaA);
    printf("rr\n");
    return (true);
}
