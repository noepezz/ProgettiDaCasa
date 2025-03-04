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


void *find_lis(nodo **listaA, nodo **listaB){
    //int i = listaA->value;
    //int j = listaA->next->value;
 //   int len = list_len(listaA);
    nodo *lista = *listaA;
    nodo *da_spostare = malloc(sizeof(nodo));
    int valore = 0;
    
    printf("valore:%d\n", valore);
    while (lista->next != NULL)
    {
          if (lista->value < lista->next->value){
              valore = lista->next->value;
              printf("valore dopo assegnazione:%d\n", valore);
              inserisciInTesta(listaB, valore);
              rimuoviNodo(listaA, valore);
            }
            lista = lista->next;
        }
        stampaLista(*listaB);
                
    
}

int main (int ac, char **av)
{
    int array[5] = {1, 3, 6, 5};
    nodo *testa;
    nodo *coda;
    nodo *listaA;
    nodo *listaB = malloc(sizeof(nodo));
    testa = crea_nodo(array[0], NULL, NULL);
    coda = testa;
    listaA = testa;

    for(int i = 1; i < 5; i++){
        inserisciInTesta(&listaA, array[i]);
    }
    //swap(listaA);
    find_lis(&listaA, &listaB);
    stampaLista(listaB);
    int *valore = rimuoviInTesta2(&listaA);
    // if(valore != NULL)
    //     printf("valore: %d\n", *valore);
   // reverseRotate(coda->prev);
    stampaLista(listaA);
    //stampaListaContrario(coda);
    return 0;
}