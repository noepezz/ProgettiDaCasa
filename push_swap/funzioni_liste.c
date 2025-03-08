#include "push_swap.h"
int dimensioneLista(nodo *lista){
    nodo *tmp;
    int count;
    count = 0;
    tmp = lista;

    while(tmp->next != NULL){
        tmp = tmp->next;
        count++;
    }
    return count;
}
nodo *crea_nodo(int value, nodo *prev, nodo *next)
{
    nodo *temp = (nodo *)malloc(sizeof(nodo));
    temp->value = value;
    temp->index = -1; //inizializzo a -1 cosi da poter indicizzare dopo
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

int list_len(nodo *lista){
    int len = 0;

    while (lista->next != NULL){
        len++;
        lista = lista->next;
    }
    return (len);
}
int *rimuoviNodo(nodo **lista, int valoreDaRimuovere)
{
    int *valore = malloc(sizeof(int));
    nodo *current = *lista; 
    nodo *temp = current;
     while (current != NULL && current->value != valoreDaRimuovere) {
        temp = current;
        current = current->next;
    }
    *valore = current->value;
    temp->next = current->next;
    free(current);
    
    return valore;
}