#include "../includes/push_swap.h"


int getMaxBits(nodo **lista)
{
    nodo	*head;
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
void radix_sort(nodo **listaA, nodo **listaB)
{
    int i = 0;
    int size;
    int max_bits;
    int count_ones, count_zeros;

    if (!listaA || !(*listaA)) {
        printf("Errore: radix_sort() chiamato con listaA vuota\n");
        return;
    }

    size = dimensioneLista(*listaA);
    max_bits = getMaxBits(listaA);
    printf("Radix Sort: size = %d, max_bits = %d\n", size, max_bits);

    while (i < max_bits)
    {
        count_ones = 0;
        count_zeros = 0;

        // Conta quanti numeri hanno il bit i-esimo impostato a 1 o 0
        nodo *temp = *listaA;
        while (temp)
        {
            if (((temp->index >> i) & 1) == 1)
                count_ones++;
            else
                count_zeros++;
            temp = temp->next;
        }

        // Sposta gli elementi in base al bit corrente (0 -> listaB, 1 -> resta in listaA)
        int moved = 0;
        while (moved < size) 
        {
            if (!(*listaA)) {
                printf("Errore: listaA è NULL prima di PB in radix_sort()\n");
                return;
            }

            int bit = ((*listaA)->index >> i) & 1;

            if (bit == 0) 
            {
                printf("PB: Sposto nodo %d in listaB\n", (*listaA)->index);
                pb(listaA, listaB);
            }
            else 
            {
                printf("RA: Ruoto nodo %d\n", (*listaA)->index);
                ra(listaA);
            }
            moved++;
        }

        // Riporta gli elementi da listaB a listaA (mantiene l'ordine crescente)
        while (dimensioneLista(*listaB) > 0)
        {
            printf("PA: Sposto nodo %d da listaB a listaA\n", (*listaB)->index);
            pa(listaA, listaB);
        }

        printf("Stato listaA dopo ciclo %d:\n", i);
        stampaLista(*listaA);

        i++;
    }
}



/*void radix_sort(nodo **listaA, nodo **listaB)
{
    nodo    *testa;
    int     i;
    int     j;
    int     size;
    int     max_bits;

    i = 0;
    testa = *listaA;
    size = dimensioneLista(testa);
    max_bits = getMaxBits(listaA);
    while (i < max_bits){
        j = 0;
        while (j++ < size)
        {
            testa = *listaA;
            if (((testa->index >> i) & 1) == 1)
                ra(listaA);
            else
                pb(listaA, listaB);
        }
        while (dimensioneLista(*listaA) != 0)
            pa(listaA, listaB);
        i++;
    }
}


void radix_sort(nodo **listaA, nodo **listaB)
{
    int i = 0;
    int size;
    int max_bits;
    int count_ones, count_zeros;

    if (!listaA || !(*listaA)) {
        printf("Errore: radix_sort() chiamato con listaA vuota\n");
        return;
    }

    size = dimensioneLista(*listaA);
    max_bits = getMaxBits(listaA);
    printf("Radix Sort: size = %d, max_bits = %d\n", size, max_bits);

    while (i < max_bits)
    {
        count_ones = 0;
        count_zeros = 0;

        // Conta quanti numeri hanno il bit i-esimo impostato a 1
        nodo *temp = *listaA;
        while (temp)
        {
            if (((temp->index >> i) & 1) == 1)
                count_ones++;
            else
                count_zeros++;
            temp = temp->next;
        }

        // Se ci sono più `1` che `0`, invertiamo la strategia
        int threshold = (count_zeros < count_ones) ? 0 : 1;

        // Sposta gli elementi in base al bit corrente
        int moved = 0;
        while (moved < size)  // Usa una variabile "moved" invece di un ciclo con dimensione fissa
        {
            if (!(*listaA)) {
                printf("Errore: listaA è NULL prima di PB in radix_sort()\n");
                return;
            }

            int bit = ((*listaA)->index >> i) & 1;

            if (bit == threshold) 
            {
                printf("PB: Sposto nodo %d in listaB\n", (*listaA)->index);
                pb(listaA, listaB);
            }
            else 
            {
                printf("RA: Ruoto nodo %d\n", (*listaA)->index);
                ra(listaA);
            }
            moved++;
        }

        // Porta indietro i numeri da listaB a listaA
        while (dimensioneLista(*listaB) > 0)
        {
            printf("PA: Sposto nodo %d da listaB a listaA\n", (*listaB)->index);
            pa(listaA, listaB);
        }

        printf("Stato listaA dopo ciclo %d:\n", i);
        stampaLista(*listaA);

        i++;
    }
}


void radix_sort(nodo **listaA, nodo **listaB)
{
    int i = 0, j;
    int size;
    int max_bits;

    if (!listaA || !(*listaA)) {
        printf("Errore: radix_sort() chiamato con listaA vuota\n");
        return;
    }

    size = dimensioneLista(*listaA);
    max_bits = getMaxBits(listaA);
    printf("Radix Sort: size = %d, max_bits = %d\n", size, max_bits);

    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if (!(*listaA)) {
                printf("Errore: listaA è NULL prima di PB in radix_sort()\n");
                return;
            }

            printf("Bit %d di nodo con indice %d -> %d\n", i, (*listaA)->index, ((*listaA)->index >> i) & 1);

            if ((((*listaA)->index >> i) & 1) == 1)
            {
                printf("RA: Ruoto nodo %d\n", (*listaA)->index);
                ra(listaA);
            }
            else
            {
                printf("PB: Sposto nodo %d in listaB\n", (*listaA)->index);
                pb(listaA, listaB);
            }
            j++;
        }

        printf("Stato listaB prima di PA:\n");
        stampaLista(*listaB);

        while (dimensioneLista(*listaB) > 0)
        {
            printf("PA: Sposto nodo %d da listaB a listaA\n", (*listaB)->index);
            pa(listaA, listaB);
        }

        printf("Stato listaA dopo ciclo %d:\n", i);
        stampaLista(*listaA);

        i++;
    }
}


void radix_sort(nodo **listaA, nodo **listaB)
{
    nodo	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *listaA;
	size = dimensioneLista(head_a);
	max_bits = getMaxBits(listaA);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *listaA;
			if (((head_a->index >> i) & 1) == 1)
				ra(listaA);
			else
				pb(listaA, listaB);
		}
		while (dimensioneLista(*listaB) != 0)
			pa(listaA, listaB);
		i++;
	}
    printf("listaB: \n");
    stampaLista(*listaB);
    printf("listaA: \n");
    stampaLista(*listaA);

}


void radix_sort(nodo **listaA, nodo **listaB)
{
    nodo *testa;
    int i;
    int j;
    int size;
    int max_bits;

    i = 0;
    testa = *listaA;
    size = dimensioneLista(testa);
    max_bits = getMaxBits(listaA);
    while (i < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            testa = *listaA;
            if (((testa->index >> i) & 1) == 1)
                ra(listaA);
            else
                pb(listaA, listaB);
        }
        while (dimensioneLista(*listaB) != 0)
            pa(listaA, listaB);
        i++;
    }
} */

/*nodo *small_num(int pivot, nodo **lista){
    nodo *temp = *lista;
    nodo *small_list = NULL;
    while (temp->next != NULL){
        if (temp->value < pivot){
            pa(&small_list, temp->value);
        }
        temp = temp->next;
    }
    free(temp);
    return (small_list);
}

void *big_num(int pivot, nodo **lista){
    nodo *temp = *lista;
    nodo *big_list = NULL;
    while (temp->next != NULL){
        if (temp->value > pivot){
            pb(&big_list, temp->value);
        }
        temp = temp->next;
    }
    free(temp);
    return (big_list);
}

void *small_sort(nodo **lista){
    nodo *tmp = *lista;
    //int valoreSuccessivo = tmp->next->value;
    while (tmp->next != NULL){
        if (tmp->value > tmp->next->value){
            sa(tmp);
        }
        ra(tmp);
    }
}
void *quick_sort(nodo **lista){
   // nodo *temp = ; deve essere uguale alla lista senza pivot
    nodo *small_n;
    nodo *big_n;
    nodo *tmp = *lista;
    int pivot = tmp->value;

    while (tmp->next != NULL){
        rimuoviInTesta(&tmp);
        small_n = small_num(pivot, &tmp);
        big_n = big_num(pivot, &tmp);
    }

}

 void sort_small_stack(nodo **stack, int size)
{
    if (size == 2 && (*stack)->value > (*stack)->next->value)
        sa(stack);
    else if (size == 3)
    {
        int first = (*stack)->value;
        int second = (*stack)->next->value;
        int third = (*stack)->next->next->value;

        if (first > second && second < third && first < third)
            sa(stack);
        else if (first > second && second > third)
        {
            sa(stack);
            rra(stack);
        }
        else if (first > second && second < third && first > third)
            ra(stack);
        else if (first < second && second > third && first < third)
        {
            sa(stack);
            ra(stack);
        }
        else if (first < second && second > third && first > third)
            rra(stack);
    }
}

int select_pivot(nodo *stack, int size)
{
    int *arr = malloc(sizeof(int) * size);
    nodo *tmp = stack;
    for (int i = 0; i < size && tmp; i++)
    {
        arr[i] = tmp->value;
        tmp = tmp->next;
    }

    // Semplice ordinamento per selezionare la mediana (bubble sort, semplice ma efficace per piccoli gruppi)
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int tmp_val = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp_val;
            }

    int pivot = arr[size / 2];
    free(arr);
    return pivot;
}

void quick_sort_b_to_a(nodo **a, nodo **b, int size)
{
    if (size <= 3)
    {
        while (size--)
            pa(a, b);
        sort_small_stack(a, size);
        return;
    }

    int pivot = select_pivot(*b, size);
    int pushed = 0;
    int rotated = 0;
    int count = size;

    while (count--)
    {
        if ((*b)->value >= pivot)
        {
            pa(a, b);
            pushed++;
        }
        else
        {
            rb(b);
            rotated++;
        }
    }

    // Ripristina la rotazione per mantenere ordine originale
    while (rotated--)
        rrb(b);

    quick_sort_push_swap(a, b, pushed);           // ordina elementi appena pushati in A
    quick_sort_push_swap_b_to_a(a, b, size - pushed); // ordina rimanenti in B
}
void quick_sort_push_swap(nodo **a, nodo **b, int size)
{
    if (size <= 3)
    {
        sort_small_stack(a, size);  // usa semplici operazioni base (sa, ra, rra)
        return;
    }

    int pivot = select_pivot(*a, size);
    int pushed = 0;
    int rotated = 0;
    int count = size;

    while (count--)
    {
        if ((*a)->value < pivot)
        {
            pb(a, b);
            pushed++;
        }
        else
        {
            ra(a);
            rotated++;
        }
    }

    // Ripristina la rotazione per mantenere ordine originale
    while (rotated--)
        rra(a);

    quick_sort_push_swap(a, b, size - pushed);  // ordina pila A
    quick_sort_b_to_a(a, b, pushed);  // ordina e reinserisci elementi da B
}

 */