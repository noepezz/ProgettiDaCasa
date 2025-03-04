#include "push_swap.h"

//algoritmi di quick sort 

void *small_num(int pivot, nodo **lista){
    nodo *temp = *lista;
    nodo *small_list = NULL;
    while (temp->next != NULL){
        if (temp->value < pivot){
            inserisciInCoda(&small_list, temp->value);
            
        }
    }
}
void *big_num(int pivot, nodo **lista){

}
void *quick_sort(nodo **lista){
    nodo *temp = ; //deve essere uguale alla lista senza pivot
    nodo *small_n;
    nodo *big_n;
    int pivot = temp->value;

    while ()
}
