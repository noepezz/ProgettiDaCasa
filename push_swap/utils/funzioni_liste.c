#include "../includes/push_swap.h"
int dimensioneLista(nodo *lst)
{
    int		count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
nodo *crea_nodo(int value)
{
    nodo *temp = (nodo *)malloc(sizeof(nodo));
    if (!temp)
        return NULL;
    temp->value = value;
    temp->index = -1;
    temp->next = NULL;

    return temp;
}

int *rimuoviInTesta(nodo **lista)
{
    int *valore = malloc(sizeof(int));
    if (*lista != NULL)
    {
        *valore = (*lista)->value;
        //nodo *temp = *lista;
        *lista = (*lista)->next;
        //free(temp);
    }
    else
    {
        printf("la lista è vuota, non posso prendere il primo elemento\n");
    }
    return valore;
}
void inserisciInTesta(nodo **testa, nodo *nuovo)//int elemento)
{
    nuovo->next = *testa;
    *testa = nuovo;
    //nodo *nuovoNodo = crea_nodo(elemento);
    //nodo *tmp = *testa;
    //nuovoNodo->next = tmp;
    //testa = nuovoNodo;
}
// Funzione per inserire un elemento in coda alla lista
void	ft_lstadd_back(nodo **stack, nodo *new)
{
	nodo	*n;

	if (*stack)
	{
		n = ultimoNodo(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}
void inserisciInCoda(nodo **testa, int elemento)
{
    nodo *nuovoNodo = crea_nodo(elemento);
    if (!nuovoNodo)
    {
        printf("Non ho creato il nuovo nodo\n");
        return;
    }

    // Se la lista è vuota, il nuovo nodo diventa la testa
    if (*testa == NULL)
    {
        printf("La testa è vuota inserisco il nuovo nodo come testa\n");
        *testa = nuovoNodo;
        return;
    }

    // Trova l'ultimo nodo
    nodo *ultimo = *testa;
    while (ultimo->next != NULL)
    {
        printf("sto scorrendo la lista  fino in fondo, valore: %d\n", ultimo->value);
        ultimo = ultimo->next;
    }

    // Collega il nuovo nodo alla fine della lista
    ultimo->next = nuovoNodo;
}

void stampaLista(nodo *listaA)
{
    printf("\nLista con gli indici assegnati:\n");
    while (listaA)
    {
        printf("Valore: %d, Indice: %d\n", listaA->value, listaA->index);
        listaA = listaA->next;
    }
    printf("\n");
}
void stampaListaB(nodo *listaA)
{
    while (listaA != NULL)
    {
        printf("lista B: %d \n", listaA->value);
        listaA = listaA->next;
    }
}
nodo *ultimoNodo(nodo *lista){
    nodo *coda;
    coda = lista;
    while (coda->next){
        coda = coda->next;
        if (coda->next == NULL)
            return (coda);
    }
    return (coda);
}

/* int list_len(nodo *lista)
{
    int len = 0;

    while (lista->next != NULL)
    {
        len++;
        lista = lista->next;
    }
    return (len);
} */
/* int *rimuoviNodo(nodo **lista, int valoreDaRimuovere)
{
    int *valore = malloc(sizeof(int));
    nodo *current = *lista;
    nodo *temp = current;
    while (current != NULL && current->value != valoreDaRimuovere)
    {
        temp = current;
        current = current->next;
    }
    *valore = current->value;
    temp->next = current->next;
    free(current);

    return valore;
} */