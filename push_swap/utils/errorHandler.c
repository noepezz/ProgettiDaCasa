#include "../includes/push_swap.h"

void	ft_error(char **str, int ac)
{
	if (ac == 2)
		ft_free(str);
	printf("errore");
	exit(1);
}
void	ft_free(char **str)
{
    int	i;

    i = 0;
	while (str[i]) {
		free(str[i]);
		i++;
	}
	free(str);
}
void	free_lista(t_nodo **lista)
{
    t_nodo	*testa;
    t_nodo	*tmp;

    testa = *lista;
    while (testa)
    {
        tmp = testa;
        testa = testa->next;
        free(tmp);
    }
    free(lista);
}
bool	is_sorted(t_nodo **lista)
{
	t_nodo	*testa;

	testa = *lista;
	while (testa && testa->next){
		if (testa->value > testa->next->value)
			return false;
		testa = testa->next;
	}
	return (true);
}

int	getDist(t_nodo **lista, int index)
{
	t_nodo	*testa;
	int		dist;

	dist = 0;
	testa = *lista;
	while(testa){
		if (testa->index == index)
			break ;
		dist++;
		testa = testa->next;
	}
	return (dist);
}
