#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
    int value;
    struct nodo *next;
    struct nodo *prev;
} nodo;


nodo *crea_nodo(int value, nodo* prev, nodo* next)
{
    nodo* temp = (nodo *)malloc(sizeof(nodo));
    temp->value = value;
    temp->prev = prev;
    temp->next = next;

    return temp;
}
bool rimuoviInTesta(nodo **lista, int **value){
    if (*lista == NULL){
        printf("la lista è vuota, non posso prendere il primo elemento\n");
        return false;
    }
    **value = (*lista)->value;
    nodo *temp = *lista;
    *lista = (*lista)->next;
    free(temp);
    return true;
}

int *rimuoviInTesta2(nodo **lista){
    int *valore = malloc(sizeof(int));
    if (*lista != NULL){
        *valore = (*lista)->value;
        nodo *temp = *lista;
        *lista = (*lista)->next;
        free(temp);
    } else{
          printf("la lista è vuota, non posso prendere il primo elemento\n");
    }
    return valore;
}
void inserisciInTesta(nodo **testa, int elemento){
    nodo* nuovoNodo;
    nuovoNodo = crea_nodo(elemento, NULL, *testa);
    (*testa)->prev = nuovoNodo;
    *testa = nuovoNodo;
}
void inserisciInCoda(nodo **coda, int elemento){
    nodo* nuovoNodo;
    nuovoNodo = crea_nodo(elemento, *coda, NULL);
    (*coda)->next = nuovoNodo;
    *coda = nuovoNodo;
}
void stampaLista(nodo *listaA){
    while(listaA != NULL){
        printf("list: %d \n", listaA->value);
        listaA = listaA->next;
    }
}
void stampaListaContrario(nodo *coda){
    while(coda != NULL){
        printf("listC: %d \n", coda->value);
        coda = coda->prev;
    }
}

void swap(nodo *listaA){
    int n = 0;
    if (listaA == NULL || listaA->next == NULL){
        printf("la lista è nulla o ha un elemento solo, non faccio nulla\n");
        return ;        
    }
    if (listaA->next != NULL){
        n = listaA->value;
        listaA->value = listaA->next->value;
        listaA->next->value = n;
    }
}
void rotate(nodo *lista){
    while(lista->next != NULL){ // si ferma senza contare l'ultimo 
        swap(lista);
        lista = lista->next;
    }
}

void reverseRotate(nodo *lista){
    while(lista->prev != NULL){ // si ferma senza contare l'ultimo 
        swap(lista);
        lista = lista->prev;
    }
}

void push(nodo *listaA, nodo *listaB){
    
}
int main (int ac, char **av)
{
    int array[5] = {1, 2, 3, 4, 5};
    nodo *testa;
    nodo *coda;
    nodo *listaA;

    testa = crea_nodo(array[0], NULL, NULL);
    coda = testa;
    listaA = testa;

    for(int i = 1; i < 5; i++){
        inserisciInTesta(&listaA, array[i]);
    }
    //swap(listaA);
    int *valore = rimuoviInTesta2(&listaA);
    if(valore != NULL)
        printf("valore: %d\n", *valore);
   // reverseRotate(coda->prev);
    stampaLista(listaA);
    //stampaListaContrario(coda);
    return 0;
}