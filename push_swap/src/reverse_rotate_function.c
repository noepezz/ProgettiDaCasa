#include "../includes/push_swap.h"

bool reverse_rotate(t_nodo **lista)
{
    t_nodo *testa;
    t_nodo *coda;

    if (dimensione_lista(*lista) < 2)
        return (false);
    testa = *lista;
    coda = ultimo_t_nodo(testa);
    while(testa)
    {
        if (testa->next && testa->next->next == NULL)
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

bool rra(t_nodo **listaA)
{
    if(reverse_rotate(listaA) == false)
        return (false);
    printf("rra");
    return (true);
}
bool rrb(t_nodo **listaB)
{
    if(reverse_rotate(listaB) == false)
        return (false);
    printf("rrb");
    return (true);
}

bool rrr(t_nodo **listaA, t_nodo **listaB)
{
    if ((dimensione_lista(*listaA) < 2) || (dimensione_lista(*listaB) < 2))
        return (false); 
    rra(listaA);
    rrb(listaB);
    printf("rrr");
    return (true);
}
