#include "push_swap.h"

static int sonoUguali(long nb, char **arg, int i){
    i++;
    while (arg[i]) {
        if (ft_atoi(arg[i]) == nb)
            return 1;
        i++;
    }
    return 0;
}
static int controlloNumero(char *num){
    int i;
    i = 0;
    if (num[i] == '-')
        i++;
    while (num[i]){
        if(!is_digit(num[i]))//in libft
            return 1;
        i++;
    }
    return 0;
}

void verificaArg(int ac, char **av){
    int i;
    long tmp;
    char **arg;

    i = 0;
    if (ac == 2)
        arg = ft_split(av[1], ' '); //da implementare dopo
    else {
        i = 1;
        arg = av;
    }
    while (arg[i]){
        tmp = ft_atoi(arg[i]);//da impl
        if(!controlloNumero(arg[i]))//da fare
            ft_error("ERRORE"); //da fare
        if(sonoUguali(tmp, arg, i))
            ft_error("ERRORE");
        if (tmp < INT_MIN || tmp > INT_MAX) // includi limits.h
            ft_error("NUMERI FUORI DAL LIMITE");
        i++;
    }
    if (ac == 2)
        ft_free(arg);
}

int isSorted(nodo **lista_a){
    //int valore = lista_a->value;
    nodo *tmp = *lista_a;
    while (tmp && tmp->next){
        if (tmp->value > tmp->next->value)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}

static int  calcoloDist(nodo **lista, int i){ //calcolo della distanza tra indice e testa
    int distanza;
    nodo *testa;

    testa = *lista;
    distanza = 0;
    while (testa){
        if(testa->index == i)
            break ;
        distanza++;
        testa = testa->next;
    }
    return distanza;
}