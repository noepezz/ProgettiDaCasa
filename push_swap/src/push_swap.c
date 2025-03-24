#include "../includes/push_swap.h"

void	inizializza_lista(t_nodo **lista, int ac, char **av)
{
	char	**argomenti;
	int		i;
	t_nodo	*new;

	i = 0;
	if (ac == 2) {
		argomenti = ft_split(av[1], ' ');
		if (!argomenti)
			return;
	}
	else
		argomenti = &av[1];
	if (argomenti[i] == NULL)
        return;
	while (argomenti[i]) {
		new = crea_t_nodo(ft_atoi(argomenti[i]));
		if (!new)
			return;
		ft_lstadd_back(lista, new);
		i++;
	}
	indice_t_nodo(lista);
	if (ac == 2)
		ft_free(argomenti);
}

void	ordinamento_lista(t_nodo **lista_a, t_nodo **lista_b)
{
	int dim;

	dim = dimensione_lista(*lista_a);
	if (dim == 0)
		return ;
	if (dim <= 5)
		simple_sort(lista_a, lista_b);
	else
		radix_sort(lista_a, lista_b);
}

int	main(int argc, char **argv)
{
	t_nodo **stack_a;
	t_nodo **stack_b;

	stack_a = (t_nodo **)malloc(sizeof(t_nodo *));
	stack_b = (t_nodo **)malloc(sizeof(t_nodo *));
	*stack_a = NULL;
	*stack_b = NULL;
	if (argc < 2)
		return (-1);
	verifica_arg(argc, argv);
	inizializza_lista(stack_a, argc, argv);
	if (!is_sorted(stack_a))
		ordinamento_lista(stack_a, stack_b);
	free_lista(stack_a);
	free_lista(stack_b);
	return (0);
}
