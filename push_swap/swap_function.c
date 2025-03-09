#include "push_swap.h"

void swap(nodo *listaA)
{
    int n = 0;
    if (listaA == NULL || listaA->next == NULL)
    {
        printf("la lista è nulla o ha un elemento solo, non faccio nulla\n");
        return;
    }
    if (listaA->next != NULL)
    {
        n = listaA->value;
        listaA->value = listaA->next->value;
        listaA->next->value = n;
    }
}

static void sa(nodo *listaA)
{
    swap(listaA);
    printf("sa");
}

static void sb(nodo *listaB)
{
    swap(listaB);
    printf("sb");
}

static void ss(nodo **listaA, nodo **listaB){
    swap(listaA);
    swap(listab);
    printf("ss");

}