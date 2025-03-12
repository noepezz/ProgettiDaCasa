#include "push_swap.h"

void ft_error(char *str)
{
    while (str)
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
    while (testa->next != NULL)
    {
        tmp = testa;
        testa = testa->next;
        free(tmp);
    }
    free(lista);
}