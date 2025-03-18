#include "../includes/push_swap.h"

bool push(nodo **lista1, nodo **lista2)
{
    nodo *tmp;
    nodo *testa_a;
    nodo *testa_da;

    if (dimensioneLista(*lista2) == 0)
        return (false);
    testa_a = *lista1;
    testa_da = *lista2;
    tmp = testa_da;
    testa_da = testa_da->next;
    *lista2 = testa_da;
    if (!testa_a)
    {
        testa_a = tmp;
        testa_a->next = NULL;
        *lista1 = testa_a;
    }
    else
    {
        tmp->next = testa_a;
        *lista1 = tmp;
    }
    return (0);
}

bool pa(nodo **listaA, nodo **listaB)
{
    if (push(listaA, listaB) == false)
        return (false);
    printf("pa");
    return true;
}

bool pb(nodo **listaA, nodo **listaB)
{
    if (push(listaB, listaA) == false)
        return (false);
    printf("pb");
    return true;
}
