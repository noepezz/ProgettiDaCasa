#include "push_swap.h"

int sonoUguali(long nb, char **arg, int i)
{
    i++;
    while (arg[i])
    {
        if (atoi(arg[i]) == nb)
            return 1;
        i++;
    }
    return 0;
}
int is_digit(int c)
{
    return (c >= '0' && c <= '9');
}
bool isNumero(char *num)
{
    int i;
    i = 0;

    printf("analizzo il numero: %s\n", num);
    if (num[i] == '-')
    {
        i++;
        printf("trovato numero negativo");
    }
    while (num[i])
    {
        printf("analizzo il seguente digit %c\n", num[i]);
        if (!is_digit(num[i])) // in libft
        {
            printf("Non è un digit\n");
            return false;
        }
        else
        {
            printf(" e un digit\n");
        }
        i++;
    }
    return true;
}

void verificaArg(int ac, char **av)
{
    int i;
    int tmp = INT_MIN;
    char **arg;

    // printf("qui ci arrivo");
    i = 0;
    if (ac == 2)
    {
        arg = ft_split(av[1], ' '); // da implementare dopo
        printf("primo arg split :%c\n", av[1][i]);
        printf("secondo arg split :%c\n", arg[1][i]);
        printf("terzo arg split :%c\n", arg[2][i]);
    }
    else
    {
        i = 1;
        arg = av;
    }
    while (arg[i])
    {

        if (!isNumero(arg[i]))
        {
            ft_error("ERRORE");
            return; // da fare
        }
        else
        {
            tmp = atoi(arg[i]);
            printf("tmp con atoi: %d\n", tmp);
        }
        if (sonoUguali(tmp, arg, i))
            ft_error("ERRORE");
        else if (tmp < INT_MIN || tmp > INT_MAX) // includi limits.h
            ft_error("NUMERI FUORI DAL LIMITE");

        printf("anche qui ci arrivo");

        i++;
    }

    if (ac == 2)
        ft_free(arg);
}

bool isSorted(nodo *lista_a)
{
    int prev = lista_a->value;
    while (lista_a->next)
    {
        printf("Contfronto %d con %d\n", prev, lista_a->next->value);
        if (prev > lista_a->next->value)
            return false;
        lista_a = lista_a->next;
        prev = lista_a->value;
    }
    return true;
}

int calcoloDist(nodo **lista, int i)
{ // calcolo della distanza tra indice e testa
    int distanza;
    nodo *testa;

    testa = *lista;
    distanza = 0;
    while (testa)
    {
        if (testa->index == i)
            break;
        distanza++;
        testa = testa->next;
    }
    return distanza;
}
