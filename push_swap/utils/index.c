#include "../includes/push_swap.h"

static t_nodo	*getMin(t_nodo **lista)
{
    t_nodo	*head;
    t_nodo	*min;

	head = *lista;
	min = NULL;
	while (head)
	{
		if (head->index == -1 && (!min || head->value < min->value))
			min = head;
		head = head->next;
	}
	return (min);
}

// Assegna gli indici ai nodi in ordine crescente di valore
void	indice_t_nodo(t_nodo **lista)
{
	t_nodo	*min;
	int		index;

	index = 0;    
	while ((min = getMin(lista)) != NULL)
	{
		if (!min) {
			break;
		}
		min->index = index++;
	}
}
