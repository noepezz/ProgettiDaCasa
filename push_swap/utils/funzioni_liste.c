#include "../includes/push_swap.h"
int	dimensione_lista(t_nodo *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
t_nodo	*crea_t_nodo(int value)
{
    t_nodo	*temp;

	temp = (t_nodo *)malloc(sizeof(t_nodo));
	if (!temp)
		return NULL;
	temp->value = value;
	temp->index = -1;
	temp->next = NULL;
	return (temp);
}

int	*rimuovi_in_testa(t_nodo **lista)
{
	int	*valore;

	valore = malloc(sizeof(int));
	if (*lista != NULL)
	{
		*valore = (*lista)->value;
		*lista = (*lista)->next;
	}
	else
	{
		free_lista(lista);
	}
	return (valore);
}
void	inserisci_in_testa(t_nodo **testa, t_nodo *nuovo)
{
	nuovo->next = *testa;
	*testa = nuovo;
}

void	ft_lstadd_back(t_nodo **stack, t_nodo *new)
{
	t_nodo	*n;

	if (*stack)
	{
		n = ultimo_t_nodo(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}
void	inserisci_in_coda(t_nodo **testa, int elemento)
{
    t_nodo	*nuovot_nodo;
	t_nodo	*ultimo;

	nuovot_nodo = crea_t_nodo(elemento);
	ultimo = *testa;
    if (!nuovot_nodo)
        return;
    if (*testa == NULL)
    {
        *testa = nuovot_nodo;
        return;
    }
    while (ultimo->next != NULL)
        ultimo = ultimo->next;
    ultimo->next = nuovot_nodo;
}

void	stampaLista(t_nodo *listaA)
{
    printf("\nLista con gli indici assegnati:\n");
    while (listaA)
    {
        printf("Valore: %d, Indice: %d\n", listaA->value, listaA->index);
        listaA = listaA->next;
    }
    printf("\n");
}

t_nodo	*ultimo_t_nodo(t_nodo *lista){
	t_nodo	*coda;

	coda = lista;
	while (coda->next){
		coda = coda->next;
		if (coda->next == NULL)
			return (coda);
	}
	return (coda);
}
