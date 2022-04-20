/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:11:03 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/20 16:52:49 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int		*stack;
	int		top;
	int		size;
	int		end;
	char	name;
	void	*opp;
	void	*sorted;
}				t_stack;

typedef struct s_moves
{
	char	*move;
	int		count;
	char	*prev_move;
	void	*next;
}				t_moves;

int				parse_stack(t_stack *a, t_stack *sorted, t_moves *moves);
int				init(t_stack *a, t_stack *b, int argc, char **argv);
void			pre_sort(t_stack *sorted);

int				low(t_stack *s, int l, int size);
int				median(t_stack *s, int l, int size);
int				stacklen(t_stack *s, int end);
int				find_low(t_stack *s, int l);
int				copy_stack(t_stack *source, t_stack *dest);
int				is_sorted(t_stack *s, t_stack *sorted);
int				ft_isspace(char *str, int i);
int				has_spaces(char *argv);
int				copy_args(char *argv, t_stack *a, int k);
int				arg_size(char **argv, int argc);

int				push(t_stack *s, t_moves *moves);
int				swap(t_stack *s, t_moves *moves);
int				rev_rot(t_stack *s, t_moves *moves, char c);
int				rot(t_stack *s, t_moves *moves, char c);
void			push_n_rot(t_stack *s, t_moves *moves, int mode);
void			rev_rot_n_push_opp(t_stack *s, t_moves *moves, int mode);

int				three_sort(t_stack *s, t_moves *moves);
int				four_sort(t_stack *a, t_moves *moves);
int				five_sort(t_stack *a, t_moves *moves);

void			quarters(t_stack *a, t_stack *b, t_moves *moves, int q);
void			quarters_init(t_stack *a, t_stack *s, t_moves *moves);
void			find_limits(t_stack *b, int *lim);
int				if_uneven(t_stack *s, int q, int *quarters);
int				*get_quarters(t_stack *s, int q);

void			eights(t_stack *a, t_stack *b, t_moves *moves, int e);
void			eights_init(t_stack *a, t_stack *s, t_moves *moves);
int				if_uneven_e(t_stack *s, int e, int *eights);
int				*get_eights(t_stack *s, int e);

t_moves			*newlist(const char *move);
int				add_move(t_moves **start, t_moves *new);
unsigned int	move_count(t_moves *start);
void			print_moves(t_moves **start);
int				add_moves_new(t_moves *new, char *tmp, int count);

int				free_all(t_moves *m, t_stack *a, t_stack *b, t_stack *s);
int				free_list(t_moves *moves);
void			free_stacks(t_stack *a, t_stack *b, t_stack *sorted);
int				print_error(int i);
int				error_check(int argc, char **argv);
#endif