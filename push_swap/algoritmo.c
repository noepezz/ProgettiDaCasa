#include "push_swap.h"

//algoritmi di quick sort 
static int getMaxBits(nodo *+lista{
    nodo *testa;
    int max;
    int maxBits;

    testa = *lista;
    max = head->index;
    maxBits = 0;
    while (head){
        if(head->index > max)
            max = head->index;
        head = head->next;
    }
    while((max >> maxBits) != 0)
        maxBits++;
    return maxBits;
}
void radix_sort(nodo **listaA, nodo **listaB){
    nodo *testa;
    int i;
    int j;
    int size;
    int max_bits;

    i = 0;
    testa = *listaA;
    size = dimensioniLista(testa);
    max_bits = getMaxBits(listaA);
    while (i < max_bits){
        j = 0;
        while (j++ <  size){
            testa = *lista;
            if (((testa->index >> i) & 1) == 1)
                ra(listaA);
            else
                pb(listaA, listaB);
        }
        while (dimensioniLista(*listaB) != 0)
            pa(listaA, listaB);
        i++;
    }
}



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