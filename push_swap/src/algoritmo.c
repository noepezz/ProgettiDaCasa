#include "../includes/push_swap.h"

int	get_max_bits(t_nodo **lista)
{
    t_nodo	*head;
	int		max;
	int		max_bits;

	head = *lista;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_nodo **listaA, t_nodo **listaB)
{
    int i = 0, j;
    int size;
    int max_bits;

    size = dimensione_lista(*listaA);
    max_bits = get_max_bits(listaA);
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if ((((*listaA)->index >> i) & 1) == 1)
                ra(listaA);
            else
                pb(listaA, listaB);
            j++;
        }
        while (dimensione_lista(*listaB) > 0)
			pa(listaA, listaB);
        i++;
    }
}
