#include "push_swap.h"

void swap(nodo **lista)
{
    int n;
    int indice;
    nodo *listaA;
    listaA = *lista;
    n = 0;
    indice = 0;
    if (listaA == NULL || listaA->next == NULL)
    {
        printf("la lista è nulla o ha un elemento solo, non faccio nulla\n");
        return;
    }
    if (listaA->next != NULL)
    {
        n = listaA->value;
        indice = listaA->index;
        listaA->value = listaA->next->value;
        listaA->index = listaA->next->index;
        listaA->next->index = indice;
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

static void ss(nodo *listaA, nodo *listaB){
    sb(listaB);
    sa(listaA);
    printf("ss");

}