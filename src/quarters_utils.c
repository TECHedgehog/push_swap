/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarters_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:35:43 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/08 21:52:36 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_limits(t_stack *b, int *lim)
{
	int	i;

	i = b->top;
	lim[0] = b->stack[i];
	lim[1] = b->stack[i];
	while (++i < b->end)
	{
		if (b->stack[i] < lim[0])
			lim[0] = b->stack[i];
		if (b->stack[i] > lim[1])
			lim[1] = b->stack[i];
	}
}

int	if_uneven(t_stack *s, int q, int *quarters)
{
	int	mod;
	int	ql;

	mod = s->size % 4;
	if (mod != 0)
	{
		if (quarters[8] == 6)
		{
			ql = (s->size / 4) + 1;
			return (s->size - ql * 3);
		}
	}
	return (q);
}

void	push_n_rot(t_stack *s, t_moves *moves, int mode)
{
	push(s, moves);
	rot(s, moves, mode);
}

void	rev_rot_n_push_opp(t_stack *s, t_moves *moves, int mode)
{
	rev_rot(s, moves, mode);
	push(s->opp, moves);
}
