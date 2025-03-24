#include "../includes/push_swap.h"

int	sono_uguali(long nb, char **arg, int i)
{
	i++;
	while (arg[i])
	{
		if (atoi(arg[i]) == nb)
			return 1;
		i++;
	}
    return (0);
}

int is_digit(int c)
{
	return (c >= '0' && c <= '9');
}
bool	is_numero(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!is_digit(num[i]))
			return (false);
		i++;
	}
	return (true);
}

void	verifica_arg(int ac, char **av)
{
    int		i;
    long	tmp;
    char	**arg;

	i = 0;
	if (ac == 2)
		arg = ft_split(av[1], ' ');
	else
	{
		i = 1;
		arg = av;
	}
	while (arg[i])
	{
		if (!is_numero(arg[i]))
			ft_error(arg, ac);
		else
			tmp = atol(arg[i]);
		if (sono_uguali(tmp, arg, i))
			ft_error(arg, ac);
		else if (tmp < INT_MIN || tmp > INT_MAX)
			ft_error(arg, ac);
		i++;
	}
	if (ac == 2)
		ft_free(arg);
}

int	calcolo_dist(t_nodo **lista, int i)
{
	int		distanza;
	t_nodo	*testa;

	testa = *lista;
	distanza = 0;
	while (testa)
	{
		if (testa->index == i)
			break;
		distanza++;
		testa = testa->next;
	}
	return (distanza);
}
