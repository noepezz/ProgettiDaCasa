#include "../includes/push_swap.h"

bool push(t_nodo **lista1, t_nodo **lista2)
{
    t_nodo	*tmp;
    t_nodo	*testa_a;
    t_nodo	*testa_da;

	if (dimensione_lista(*lista2) == 0)
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
    return (true);
}

bool pa(t_nodo **listaA, t_nodo **listaB)
{
    if (push(listaA, listaB) == false)
        return (false);
    printf("pa\n");
    return true;
}

bool pb(t_nodo **listaA, t_nodo **listaB)
{
    if (push(listaB, listaA) == false)
        return (false);
    printf("pb\n");
    return true;
}
