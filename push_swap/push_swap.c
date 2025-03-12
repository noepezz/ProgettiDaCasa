#include "push_swap.h"

void inizializzaLista(nodo **lista, int ac, char **av)
{
    nodo *nodoLista;
    char **argomenti;
    int i;
    int j;
    printf("\n entro in inizializza lista av: %s\n", av[1]);
    printf("ac: %d", ac);
    i = 1;
    if (av[0] == NULL)
    {
        printf("vuoto");
    }

    if (ac == 2)
        argomenti = ft_split(av[i], ' ');
    else
    {
        i = 1;
        argomenti = av;
    }

    j = 0;
    while (argomenti[j])
    {

        printf("argomento : %s\n", argomenti[j]); // modifica
        inserisciInCoda(lista, atoi(argomenti[j]));
        j++;
    }
    indiceNodo(*lista);
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

    // Stampa la lista per debugging
    stampaLista(lista_a);

    // Se la lista è già ordinata, libera la memoria ed esce
    if (isSorted(lista_a))
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
}
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