#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_nodo
{
	int value;
	int index;
	struct s_nodo *next;
}	t_nodo;

typedef struct s_radix {
	int i;
	int size;
	int moved;
	int bit;
}	t_radix;

void	do_moves(t_nodo **lista, int min, int next_min);
void	ft_error(char **str, int ac);
void	free_lista(t_nodo **lista);
int		get_max_bits(t_nodo **lista);
int		sono_uguali(long nb, char **arg, int i);
bool	is_numero(char *num);
void	verifica_arg(int ac, char **av);
bool	is_sorted(t_nodo **lista_a);
int		calcolo_dist(t_nodo **lista, int i);
char	**ft_split(char const *s, char c);
bool	push(t_nodo **a, t_nodo **b);
bool	rotate(t_nodo **lista);
t_nodo	*crea_t_nodo(int value);
int		*rimuovi_in_testa(t_nodo **lista);
void	inserisci_in_testa(t_nodo **testa, t_nodo *nuovo);//int elemento);
void	inserisci_in_coda(t_nodo **testa, int elemento);
bool	swap(t_nodo **listaA);
bool	reverse_rotate(t_nodo **lista);
int		*rimuovi_t_nodo(t_nodo **lista, int valoreDaRimuovere);
void	radix_sort(t_nodo **listaA, t_nodo **listaB);
int		dimensione_lista(t_nodo *lista);
void	simple_sort(t_nodo **lista_a, t_nodo **lista_b);
void	indice_t_nodo(t_nodo **lista);
bool	pa(t_nodo **listaA, t_nodo **listaB);
bool	pb(t_nodo **listaA, t_nodo **listaB);
void	inizializza_lista(t_nodo **lista, int ac, char **av);
void	ordinamento_lista(t_nodo **lista_a, t_nodo **lista_b);
bool	rra(t_nodo **listaA);
bool	rrb(t_nodo **listaB);
bool	rrr(t_nodo **listaA, t_nodo **listaB);
bool	ra(t_nodo **listaA);
bool	rb(t_nodo **listaB);
bool	rr(t_nodo **listaA, t_nodo **listaB);
int		is_digit(int c);
int		get_min(t_nodo **lista, int valore);
void	sort_cinque(t_nodo **lista_a, t_nodo **lista_b);
void	sort_quattro(t_nodo **lista_a, t_nodo **lista_b);
void	sort_tre(t_nodo **lista);
bool	ss(t_nodo **listaA, t_nodo **listaB);
bool	sa(t_nodo **listaA);
bool	sb(t_nodo **listaB);
void	ft_free(char **str);
t_nodo	*ultimo_t_nodo(t_nodo *lista);
void	ft_lstadd_back(t_nodo **stack, t_nodo *new);

#endif
