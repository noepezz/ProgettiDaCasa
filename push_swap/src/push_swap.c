#include "../includes/push_swap.h"

void inizializzaLista(nodo **lista, int ac, char **av)
{
    char **argomenti;
    int i;
    nodo *new;

    printf("\n entro in inizializza lista av: %s\n", av[1]);
    printf("ac: %d", ac);
    
    if (ac == 2) {
        argomenti = ft_split(av[1], ' ');
        if (!argomenti) {
            printf("Errore: ft_split ha restituito NULL\n");
            return;
        }
        i = 0;
    } else {
        argomenti = &av[1];  // Ignora argv[0] (nome del programma)
        i = 0;
    }

    if (argomenti[i] == NULL) {
        printf("Errore: Nessun numero valido trovato\n");
        return;
    }

    while (argomenti[i]) {
        new = crea_nodo(ft_atoi(argomenti[i]));
        if (!new) {
            printf("Errore: impossibile creare il nodo\n");
            return;
        }
        ft_lstadd_back(lista, new);
        i++;
    }
    printf("lista con indici negativi: ");
    stampaLista(*lista);
    indiceNodo(lista);
    //stampaLista(*lista);
    
    if (ac == 2)
        ft_free(argomenti);
}
void ordinamentoLista(nodo **lista_a, nodo **lista_b)
{
    int dim = dimensioneLista(*lista_a);
    printf("Dimensione della lista: %d\n", dim);

    if (dim == 0) {
        printf("Errore: lista vuota, impossibile ordinare!\n");
        return;
    }

    if (dim <= 5)
    {
        printf("La lista ha dimensione inferiore di 5\n");
        simpleSort(lista_a, lista_b);
    }
    else {
        printf("La lista ha dimensione superiore a 5, eseguo radix_sort.\n");
        radix_sort(lista_a, lista_b);
    }
}

int main(int argc, char **argv)
{
    nodo **stack_a;
    nodo **stack_b;
    stack_a = (nodo **)malloc(sizeof(nodo *));
	stack_b = (nodo **)malloc(sizeof(nodo *));
	*stack_a = NULL;
	*stack_b = NULL;
    if (argc < 2)
        return (-1);

    verificaArg(argc, argv);
    inizializzaLista(stack_a, argc, argv);
    stampaLista(*stack_a);
    if (isSorted(stack_a)) 
        printf("la lista è ordinata\n");
    else
        ordinamentoLista(stack_a, stack_b);
    freeLista(stack_a);
    freeLista(stack_b);
    return (0);
}

/*void inizializzaLista(nodo **lista, int ac, char **av)
{
    //nodo *nodoLista;
    char **argomenti;
    int i;
    nodo *new;
    printf("\n entro in inizializza lista av: %s\n", av[1]);
    printf("ac: %d", ac);
    i = 0;
    if (ac == 2)
        argomenti = ft_split(av[1], ' ');
    else
    {
        i = 1;
        argomenti = av;
    }
    printf("split: %c\n", argomenti[0][0]);
    printf("split: %c\n", argomenti[1][0]);
    printf("split: %c\n", argomenti[2][0]);
    printf("split: %c\n", argomenti[3][0]);
    while (argomenti[i])
    {
        new = crea_nodo(ft_atoi(argomenti[i]));
     //   printf("argomento : %s\n", argomenti[j]); // modifica
        ft_lstadd_back(lista, new);
        i++;
       // printf("lista prima di i\n");
        //stampaLista(*lista);
    }
    stampaLista(*lista);
    indiceNodo(lista);
    if (ac == 2)
        ft_free(argomenti);
}

void ordinamentoLista(nodo **lista_a, nodo **lista_b)
{
    if (dimensioneLista(*lista_a) <= 5)
    {
        printf("La lista ha dimensione inferiore di 5\n");
        simpleSort(lista_a, lista_b);
    }
    else
        radix_sort(lista_a, lista_b);
}
int	main(int argc, char **argv)
{
	nodo	**stack_a;
	nodo	**stack_b;

	if (argc < 2)
		return (-1);
	verificaArg(argc, argv);
	stack_a = (nodo **)malloc(sizeof(nodo));
	stack_b = (nodo **)malloc(sizeof(nodo));
	*stack_a = NULL;
	*stack_b = NULL;
	inizializzaLista(stack_a, argc, argv);
	if (isSorted(stack_a))
	{
		printf("la lista is ordinata");
		freeLista(stack_a);
		freeLista(stack_b);
		return (0);
	}
	ordinamentoLista(stack_a, stack_b);
	freeLista(stack_a);
	freeLista(stack_b);
	return (0);
}
int main(int ac, char **av)
{
    nodo *lista_a = NULL;
    nodo *lista_b = NULL;

    if (ac < 2)
        return -1;

    // Controllo degli argomenti
    verificaArg(ac, av);

    // Inizializza la lista con gli argomenti passati
    inizializzaLista(&lista_a, ac, av);
 	if (isSorted(&lista_a))
    {
        printf("->lista già ordinata");
        freeLista(&lista_a);
        return 0;
    }
    // Stampa la lista per debugging
    stampaLista(lista_a);

    // Se la lista è già ordinata, libera la memoria ed esce
    if (isSorted(&lista_a))
    {
        printf("lista già ordinata");
        freeLista(&lista_a);
        return 0;
    }

    // Ordinamento della lista
    ordinamentoLista(&lista_a, &lista_b);

    // Libera la memoria
    freeLista(&lista_a);
    freeLista(&lista_b);

    return 0;
}*/

/*  int array[5] = {1, 2, 3, 4, 5};
    nodo *testa;
    nodo *coda;
    nodo *listaA;
    nodo *listaB;

    testa = crea_nodo(array[0], NULL, NULL);
    coda = testa;
    listaA = testa;
    listaB = (nodo *)malloc(sizeof(nodo));
    listaB = NULL;
    for (int i = 1; i < 5; i++)
    {
        inserisciInTesta(&listaA, array[i]);
    }
    // swap(listaA);
    // int *valore = rimuoviInTesta2(&listaA);
    // if (valore != NULL)
    //     printf("valore: %d\n", *valore);
    // reverseRotate(coda->prev);
    push(&listaA, &listaB);
    stampaListaB(listaB);
    stampaLista(listaA);
    // stampaListaContrario(coda);
    return 0;*/
