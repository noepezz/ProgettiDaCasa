#include "../includes/push_swap.h"

static nodo *getMin(nodo **lista)
{
    nodo *head = *lista;
    nodo *min = NULL;

    while (head)
    {
        if (head->index == -1 && (!min || head->value < min->value))
            min = head;
        head = head->next;
    }
    return min;
}

// Assegna gli indici ai nodi in ordine crescente di valore
void indiceNodo(nodo **lista)
{
    nodo *min;
    int index = 0;

    printf("Entrando in indiceNodo\n");
    
    while ((min = getMin(lista)) != NULL) // Finché esistono nodi senza indice
    {
        if (!min) {
            printf("Errore: min è NULL!\n");
            break;
        }
        printf("Assegno index %d al nodo con valore %d\n", index, min->value);
        min->index = index++;
    }
    printf("Uscendo da indiceNodo\n");
    stampaLista(*lista);
}





/*static nodo *getMin(nodo **lista)
{
    nodo *testa;
    nodo *min; // VADO A CREARE UNA LISTA PARALLELA SOLO DI INDICI;
    int nbMin;
    //printf("entro in getmin");
    testa = *lista;
    min = NULL;
    nbMin = 0;
    
    if(testa){
        while (testa)
        {
            if ((testa->index == -1) && (!nbMin || testa->value < min->value))
            {
                min = testa;
                nbMin = 1;
            }
            testa = testa->next;
        }
    }
   // printf("Min is this: %d", min->index);
    return min;
}


void indiceNodo(nodo **lista)
{
    nodo *testa;
    int index;

    index = 0;
    printf("sono in indice nodo");
    testa = getMin(lista);
    printf("indice partenza: %d", testa->index);
    while (testa)
    {
        testa->index = index++;
        testa = getMin(lista);
        printf("indice della lista: %d", testa->index);
    }
  //  stampaLista(testa);
}*/
