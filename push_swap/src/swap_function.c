#include "../includes/push_swap.h"

bool swap(nodo **lista)
{	
    nodo	*testa;
	nodo 	*next;
	int		tmp_val;
	int		tmp_index;

	if (dimensioneLista(*lista) < 2)
		return (false);
	testa = *lista;
	next = testa->next;
	if (!testa && !next)
		ft_error("Errore di swap");
	tmp_val = testa->value;
	tmp_index = testa->index;
	testa->value = next->value;
	testa->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (true);
}
    /* int n;
    int indice;
    nodo *listaA;
    listaA = *lista;
    n = 0;
    indice = 0;
    if (dimensioneLista(listaA) < 2)
        return false;
    if (listaA == NULL || listaA->next == NULL)
    {
        printf("la lista è nulla o ha un elemento solo, non faccio nulla\n");
    }
    n = listaA->value;
    indice = listaA->index;
    listaA->value = listaA->next->value;
    listaA->index = listaA->next->index;
    listaA->next->index = indice;
    listaA->next->value = n;
    return true; */
//}

bool sa(nodo **listaA)
{
    if (swap(listaA) == false)
        return false;
    
    printf("sa");
    return true;
}

bool sb(nodo **listaB)
{
    if (swap(listaB) == false)
        return false;
    
    printf("sb");
    return true;
}

bool ss(nodo **listaA, nodo **listaB)
{
    if ((dimensioneLista(*listaA) < 2) || (dimensioneLista(*listaA) < 2))
        return false;
    sb(listaB);
    sa(listaA);
    printf("ss");
    return true;
}
