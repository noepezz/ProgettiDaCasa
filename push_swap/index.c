#include "push_swap.h"

//inizializzo gli indici della lista con get min;

nodo +getMin(nodo **lista){
    nodo *testa = *lista;
    nodo *min = NULL; //VADO A CREARE UNA LISTA PARALLELA SOLO DI INDICI;
    int     nbMin = 0;

    if (testa){
        while (testa){
            if ((testa->index == -1) &&(!nbMin || testa->value < min->value)){
                min = testa;
                nbMin =  1;
            }
            testa = testa->next;
        }
    }
    return min;
}
void    indiceNodo(nodo **lista){
    nodo *testa;
    int i;

    i = 0;
    testa = getMin(lista);
    while (testa){
        testa->index = i++;
        testa = getMin(lista);
    }
}
