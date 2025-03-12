#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct nodo
{
    int value;
    int index;
    struct nodo *next;
} nodo;
void ft_error(char *str);
void freeLista(nodo **lista);
int getMaxBits(nodo **lista);
int sonoUguali(long nb, char **arg, int i);
bool isNumero(char *num);
void verificaArg(int ac, char **av);
bool isSorted(nodo *lista_a);
int calcoloDist(nodo **lista, int i);
char **ft_split(char const *s, char c);
void push(nodo **a, nodo **b);
void rotate(nodo *lista);
nodo *crea_nodo(int value);
int *rimuoviInTesta(nodo **lista);
void inserisciInTesta(nodo **testa, int elemento);
void inserisciInCoda(nodo **testa, int elemento);
// void stampaLista(nodo *listaA);
// void stampaListaB(nodo *listaB);
// void stampaListaA(nodo *listaA);
// void stampaListaContrario(nodo *coda);
void swap(nodo **listaA);
void reverseRotate(nodo *lista);
int *rimuoviNodo(nodo **lista, int valoreDaRimuovere);
void radix_sort(nodo **listaA, nodo **listaB);
int dimensioneLista(nodo *lista);
nodo *getMin(nodo *lista);
void simpleSort(nodo *lista_a, nodo *lista_b);
int list_len(nodo *lista);
void indiceNodo(nodo *lista);
void pa(nodo *listaA, nodo *listaB);
void pb(nodo *listaA, nodo *listaB);
void inizializzaLista(nodo *lista, int ac, char **av);
void ordinamentoLista(nodo *lista_a, nodo *lista_b);
void rra(nodo *listaA);
void rrb(nodo *listaB);
void rrr(nodo *listaA, nodo *listaB);
void ra(nodo *listaA);
void rb(nodo *listaB);
void rr(nodo *listaA, nodo *listaB);
int is_digit(int c);
int get_min(nodo *lista, int valore);
void sortCinque(nodo *lista_a, nodo *lista_b);
void sortQuattro(nodo *lista_a, nodo *lista_b);
void sortTre(nodo *lista);
void ss(nodo *listaA, nodo *listaB);
void sa(nodo *listaA);
void sb(nodo *listaB);
void ft_free(char **str);
void stampaLista(nodo *head);
