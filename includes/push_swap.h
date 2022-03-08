/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:11:03 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/03/07 16:48:08 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ultimate_libft/ultra_utils.h"
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

void			print_stacks(t_stack *a, t_stack *b, int argc);
void			print_stacks_info(t_stack *a, t_stack *b, t_stack *sorted);

int				parse_stack(t_stack *a, t_stack *sorted, t_moves *moves);
int				init(t_stack *a, t_stack *b, int argc, char **argv);
void			pre_sort(t_stack *sorted);

int				low(t_stack *s, int l, int size);
int				median(t_stack *s, int l, int size);
int				stacklen(t_stack *s, int end);
int				find_low(t_stack *s, int l);
int				copy_stack(t_stack *source, t_stack *dest);
int				is_sorted(t_stack *s, t_stack *sorted);

int				push(t_stack *s, t_moves *moves);
int				swap(t_stack *s, t_moves *moves);
int				rev_rot(t_stack *s, t_moves *moves, char c);
int				rot(t_stack *s, t_moves *moves, char c);

void			quarters(t_stack *a, t_stack *s, t_moves *moves);

t_moves			*newlist(const char *move);
int				add_move(t_moves **start, t_moves *new);
unsigned int	move_count(t_moves *start);
void			print_moves(t_moves **start);

int				free_all(t_moves *m, t_stack *a, t_stack *b, t_stack *s);
void			free_list(t_moves *moves);
void			free_stacks(t_stack *a, t_stack *b, t_stack *sorted);
#endif