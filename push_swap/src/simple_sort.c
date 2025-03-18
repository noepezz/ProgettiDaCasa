#include "../includes/push_swap.h"
// funzioni per il sorting con meno di 5 elementi
int get_min(nodo **lista, int valore)
{
    nodo *testa;
    int min = -1;
	
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

void sortTre(nodo **lista)
{
    nodo *testa;
    int min;
    int next_min;

    testa = *lista;
    min = get_min(lista, -1);
    next_min = get_min(lista, min);
    if (isSorted(lista))
        return  ;
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
    printf("lista sort 3:");
    stampaLista(*lista);
}
void sortQuattro(nodo **lista_a, nodo **lista_b)
{
    int dist;
    if (isSorted(lista_a))
        return;
    dist = calcoloDist(lista_a, get_min(lista_a, -1)); // trovo distanza tra il primo idx e il piu piccolo;
    if (dist == 1)
    {
        ra(lista_a);
    } // se la distanza è 1 allora fa un semplice ra
    else if (dist == 2)
    {
        ra(lista_a);
        ra(lista_a);
    }
    else if (dist == 3)
    {
        rra(lista_a);
    }
    if (isSorted(lista_a))
        return ;
    pb(lista_a, lista_b);
    sortTre(lista_a);
    pa(lista_a, lista_b);
}
void sortCinque(nodo **lista_a, nodo **lista_b)
{
    int dist;
    if (isSorted(lista_a))
        return;
    dist = calcoloDist(lista_a, get_min(lista_a, -1)); // trovo distanza tra il primo idx e il piu piccolo;
    if (dist == 1)
    {
        ra(lista_a);
    } // se la distanza è 1 allora fa un semplice ra
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
    if (isSorted(lista_a))
        return;
    pb(lista_a, lista_b);
    sortQuattro(lista_a, lista_b);
    pa(lista_a, lista_b);
}
void simpleSort(nodo **lista_a, nodo **lista_b)
{
    int size;

    if (isSorted(lista_a) || dimensioneLista(*lista_a) == 0 || dimensioneLista(*lista_a) == 1)
        return  ;
    size = dimensioneLista(*lista_a);
    printf("dim lista: %d\n", size);
    stampaLista(*lista_a);
    stampaLista(*lista_b);
    if (size == 2)
        sa(lista_a);
    else if (size == 3){
        sortTre(lista_a);
        stampaLista(*lista_a);
    }
    else if (size == 4)
        sortQuattro(lista_a, lista_b);
    else if (size == 5)
        sortCinque(lista_a, lista_b);
}
