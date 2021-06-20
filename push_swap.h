/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <ericllaca@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 22:11:03 by ellaca-f          #+#    #+#             */
/*   Updated: 2021/06/20 15:19:51 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ultimate_libft/ultra_utils.h"
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
}				t_stack;

typedef struct s_moves
{
	char	*move;
	int		count;
	char	*prev_move;
	void	*next;
}				t_moves;

void			print_stacks(t_stack *a, t_stack *b, int argc);

int				low(t_stack *s, int i, int l, int size);
int				median(t_stack *s, int l, int size);

int				push(t_stack *s, t_moves *moves);
int				swap(t_stack *s, t_moves *moves);
int				rev_rot(t_stack *s, t_moves *moves, char c);
int				rot(t_stack *s, t_moves *moves, char c);

int				quicksort(t_stack *s, int size, t_moves *moves);
int				three_sort(t_stack *s, t_moves *moves);

t_moves			*newlist(const char *move);
int				add_move(t_moves **start, t_moves *new);
unsigned int	move_count(t_moves *start);
void			print_moves(t_moves **start);
void			free_list(t_moves *moves);

#endif