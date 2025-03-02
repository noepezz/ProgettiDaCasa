#include "push_swap.h"

nodo *crea_nodo(int value, nodo *prev, nodo *next)
{
    nodo *temp = (nodo *)malloc(sizeof(nodo));
    temp->value = value;
    temp->prev = prev;
    temp->next = next;

    return temp;
}

int *rimuoviInTesta(nodo **lista)
{
    int *valore = malloc(sizeof(int));
    if (*lista != NULL)
    {
        *valore = (*lista)->value;
        nodo *temp = *lista;
        *lista = (*lista)->next;
        free(temp);
    }
    else
    {
        printf("la lista è vuota, non posso prendere il primo elemento\n");
    }
    return valore;
}
void inserisciInTesta(nodo **testa, int elemento)
{
    nodo *nuovoNodo;
    if (*testa == NULL)
        *testa = nuovoNodo;
    nuovoNodo = crea_nodo(elemento, NULL, *testa);
    (*testa)->prev = nuovoNodo;
    *testa = nuovoNodo;
}
void inserisciInCoda(nodo **coda, int elemento)
{
    nodo *nuovoNodo;
    nuovoNodo = crea_nodo(elemento, *coda, NULL);
    (*coda)->next = nuovoNodo;
    *coda = nuovoNodo;
}
void stampaLista(nodo *listaA)
{
    while (listaA != NULL)
    {
        printf("lista A: %d \n", listaA->value);
        listaA = listaA->next;
    }
}
void stampaListaB(nodo *listaA)
{
    while (listaA != NULL)
    {
        printf("lista B: %d \n", listaA->value);
        listaA = listaA->next;
    }
}
void stampaListaContrario(nodo *coda)
{
    while (coda != NULL)
    {
        printf("listContrario: %d \n", coda->value);
        coda = coda->prev;
    }
}