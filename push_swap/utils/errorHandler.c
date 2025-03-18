#include "../includes/push_swap.h"

void ft_error(char *str)
{
    if (str)
        printf("%s\n", str);
}
void ft_free(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    while (i >= 0)
        free(str[i--]);
}
void freeLista(nodo **lista)
{
    nodo *testa;
    nodo *tmp;

    testa = *lista;
    while (testa)
    {
        tmp = testa;
        testa = testa->next;
        free(tmp);
    }
    free(lista);
}
bool isSorted(nodo **lista){
    nodo *testa;

    testa = *lista;
    while (testa && testa->next){
        if (testa->value > testa->next->value)
            return false;
        testa = testa->next;
    }
    return true;
}
int getDist(nodo **lista, int index){
    nodo *testa;
    int dist;

    dist = 0;
    testa = *lista;
    while(testa){
        if (testa->index == index)
            break ;
        dist++;
        testa = testa->next;
    }
    return dist;
}
