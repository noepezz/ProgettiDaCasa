#define PUSH_SWAP_H
// #ifdef PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct nodo
{
    int value;
    int index;
    struct nodo *next;
    struct nodo *prev;
} nodo;
void push(nodo **a, nodo **b);
void rotate(nodo *lista);
nodo *crea_nodo(int value);
int *rimuoviInTesta(nodo **lista);
void inserisciInTesta(nodo **testa, int elemento);
void inserisciInCoda(nodo **coda, int elemento);
void stampaLista(nodo *listaA);
void stampaListaB(nodo *listaB);
void stampaListaA(nodo *listaA);
void stampaListaContrario(nodo *coda);
void swap(nodo **listaA);
void reverseRotate(nodo *lista);
int *rimuoviNodo(nodo **lista, int valoreDaRimuovere);
