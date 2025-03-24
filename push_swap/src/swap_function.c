#include "../includes/push_swap.h"

bool swap(t_nodo **lista)
{	
    t_nodo	*testa;
	t_nodo 	*next;
	int		tmp_val;
	int		tmp_index;

	if (dimensione_lista(*lista) < 2){
		return (false);
	}
	testa = *lista;
	next = testa->next;
	if (!testa && !next)
		free_lista(lista);
	tmp_val = testa->value;
	tmp_index = testa->index;
	testa->value = next->value;
	testa->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (true);
}

bool sa(t_nodo **listaA)
{
    if (swap(listaA) == false)
        return (false);
    printf("sa\n");
    return (true);
}

bool sb(t_nodo **listaB)
{
    if (swap(listaB) == false)
        return (false);
    printf("sb\n");
    return (true);
}

bool ss(t_nodo **listaA, t_nodo **listaB)
{
    if ((dimensione_lista(*listaA) < 2) || (dimensione_lista(*listaA) < 2))
        return (false);
    sb(listaB);
    sa(listaA);
    printf("ss\n");
    return (true);
}
