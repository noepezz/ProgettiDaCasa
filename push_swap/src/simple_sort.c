#include "../includes/push_swap.h"
// funzioni per il sorting con meno di 5 elementi
int	get_min(t_nodo **lista, int valore)
{
	t_nodo	*testa;
	int		min;

	min = -1;
	testa = *lista;
	min = testa->index;
	while (testa->next)
	{
		testa = testa->next;
		if ((testa->index < min) && testa->index != valore)
			min = testa->index;
	}
	return (min);
}
void	do_moves(t_nodo **lista, int min, int next_min)
{
	t_nodo	*testa;

	testa = *lista;
	if (testa->index == min && testa->next->index != next_min)
	{
		ra(lista);
		sa(lista);
		rra(lista);
	}
	else if (testa->index == next_min)
	{
		if (testa->next->index == min)
			sa(lista);
		else
			rra(lista);
	}
	else
	{
		if (testa->next->index == min)
			ra(lista);
        else
        {
            sa(lista);
            rra(lista);
        }
    }
}

void	sort_tre(t_nodo **lista)
{
	int	min;
	int	next_min;

	min = get_min(lista, -1);
	next_min = get_min(lista, min);
	if (is_sorted(lista))
		return  ;
	else
		do_moves(lista, min, next_min);
}

void	sort_quattro(t_nodo **lista_a, t_nodo **lista_b)
{
	int dist;

	if (is_sorted(lista_a))
		return ;
	dist = calcolo_dist(lista_a, get_min(lista_a, -1)); 
	if (dist == 1)
		ra(lista_a);
	else if (dist == 2)
	{
		ra(lista_a);
		ra(lista_a);
	}
	else if (dist == 3)
	{
		rra(lista_a);
	}
	if (is_sorted(lista_a))
		return ;
	pb(lista_a, lista_b);
	sort_tre(lista_a);
	pa(lista_a, lista_b);
}

void	sort_cinque(t_nodo **lista_a, t_nodo **lista_b)
{
	int dist;

	if (is_sorted(lista_a))
		return ;
	dist = calcolo_dist(lista_a, get_min(lista_a, -1));
	if (dist == 1)
	{
		ra(lista_a);
	}
	else if (dist == 2)
	{
		ra(lista_a);
		ra(lista_a);
	}
	else if (dist == 3)
	{
		rra(lista_a);
		rra(lista_a);
	}
	else if (dist == 4)
		rra(lista_a);
	if (is_sorted(lista_a))
		return ;
	pb(lista_a, lista_b);
	sort_quattro(lista_a, lista_b);
	pa(lista_a, lista_b);
}

void	simple_sort(t_nodo **lista_a, t_nodo **lista_b)
{
	int	size;

	if (is_sorted(lista_a) || dimensione_lista(*lista_a) == 0 || dimensione_lista(*lista_a) == 1)
		return  ;
	size = dimensione_lista(*lista_a);
	if (size == 2)
		sa(lista_a);
	else if (size == 3)
		sort_tre(lista_a);
	else if (size == 4)
		sort_quattro(lista_a, lista_b);
	else if (size == 5)
		sort_cinque(lista_a, lista_b);
}
