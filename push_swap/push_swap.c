#include "push_swap.h"
// repohttps://github.com/42YerevanProjects/push_swap/blob/master/utils/check_args.c#L43
static void    inizializzaLista(nodo **lista, int ac, char **av){
    nodo *nodoLista;
    char **argomenti;
    int i;

    i = 0;
    if (ac == 2)
        argomenti = ft_split(av[i], ' ');
    else{
        i = 1;
        argomenti = av;
    }
    while (argomenti[i]){
        nodoLista = crea_nodo(ft_atoi(argomenti[i]));
        inserisciInCoda(lista, nodoLista);
        i++;
    }
    indiceNodo(lista);
    if(ac == 2)
        ft_free(argomenti);
}
static void ordinamentoLista(nodo **lista_a, nodo **lista_b)
{
    if(dimensioneLista(*lista_a) <= 5)
        simpleSort(lista_a, lista_b);
    else
        radix_sort(lista_a, lista_b);
}
int main(int ac, char **av)
{
    nodo **lista_a;
    nodo **lista_b;

    if(ac < 2)
        return -1;
    verificaArg(ac, av);
    lista_a = (nodo **) malloc(sizeof(nodo));
    lista_b = (nodo **) malloc(sizeof(nodo));
    *lista_a = NULL;
    *lista_b = NULL;
    inizializzaLista(lista_a, ac, av);
    if (isSorted(lista_a)){
        freeLista(lista_a);
        freeLista(lista_a);
        return 0;
    }
    ordinamentoLista(lista_a, lista_b);
    freeLista(lista_a);
    freeLista(lista_b);
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