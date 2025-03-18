#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
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
bool isSorted(nodo **lista_a);
int calcoloDist(nodo **lista, int i);
char **ft_split(char const *s, char c);
bool push(nodo **a, nodo **b);
bool rotate(nodo **lista);
nodo *crea_nodo(int value);
int *rimuoviInTesta(nodo **lista);
void inserisciInTesta(nodo **testa, nodo *nuovo);//int elemento);
void inserisciInCoda(nodo **testa, int elemento);
// void stampaLista(nodo *listaA);
// void stampaListaB(nodo *listaB);
// void stampaListaA(nodo *listaA);
// void stampaListaContrario(nodo *coda);
bool swap(nodo **listaA);
bool reverseRotate(nodo **lista);
int *rimuoviNodo(nodo **lista, int valoreDaRimuovere);
void radix_sort(nodo **listaA, nodo **listaB);
int dimensioneLista(nodo *lista);
//static nodo *getMin(nodo **lista);
void simpleSort(nodo **lista_a, nodo **lista_b);
//int list_len(nodo *lista);
void indiceNodo(nodo **lista);
bool pa(nodo **listaA, nodo **listaB);
bool pb(nodo **listaA, nodo **listaB);
void inizializzaLista(nodo **lista, int ac, char **av);
void ordinamentoLista(nodo **lista_a, nodo **lista_b);
bool rra(nodo **listaA);
bool rrb(nodo **listaB);
bool rrr(nodo **listaA, nodo **listaB);
bool ra(nodo **listaA);
bool rb(nodo **listaB);
bool rr(nodo **listaA, nodo **listaB);
int is_digit(int c);
int get_min(nodo **lista, int valore);
void sortCinque(nodo **lista_a, nodo **lista_b);
void sortQuattro(nodo **lista_a, nodo **lista_b);
void sortTre(nodo **lista);
bool ss(nodo **listaA, nodo **listaB);
bool sa(nodo **listaA);
bool sb(nodo **listaB);
void ft_free(char **str);
void stampaLista(nodo *head);
nodo *ultimoNodo(nodo *lista);
void	ft_lstadd_back(nodo **stack, nodo *new);

#endif
