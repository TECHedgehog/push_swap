/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_eights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 00:31:29 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/13 14:18:46 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	eights_in_order(t_stack *a, t_moves *moves, int *eights, int j)
{
	if (j)
	{
		j = eights[16] - 2;
		while (a->stack[a->end - 1] != eights[j + 1])
		{
			if (a->stack[a->top] <= eights[j + 1]
				&& a->stack[a->top] >= eights[j])
				rot(a, moves, 0);
			else
				rev_rot(a, moves, 0);
		}
	}
	else
	{
		j = eights[16];
		while (a->stack[a->end - 1] != eights[j + 1])
		{
			if (a->stack[a->top] <= eights[j + 1]
				&& a->stack[a->top] >= eights[j])
				rot(a, moves, 0);
			else
				rev_rot(a, moves, 0);
		}
	}
}

void	eight_in_b(t_stack *a, t_stack *b, t_moves *moves, int *eights)
{
	int	*lim;

	lim = malloc(sizeof(int) * 2);
	if (eights[16] != 0)
		eights_in_order(a, moves, eights, 1);
	while (b->top < b->end)
	{
		find_limits(b, lim);
		if (b->stack[b->top] == lim[0])
			push_n_rot(a, moves, 0);
		else if (b->stack[b->top] == lim[1])
			push(a, moves);
		else if (b->stack[b->end - 1] == lim[0])
		{
			rev_rot(b, moves, 0);
			push_n_rot(a, moves, 0);
		}
		else if (b->stack[b->end - 1] == lim[1])
			rev_rot_n_push_opp(b, moves, 0);
		else
			rot(b, moves, 0);
	}
	eights_in_order(a, moves, eights, 0);
	free(lim);
}

void	eights_init(t_stack *a, t_stack *s, t_moves *moves)
{
	int		e;
	t_stack	*b;

	b = a->opp;
	if (s->size % 8 != 0)
		e = (s->size / 8) + 1;
	else
		e = s->size / 8;
	eights(a, b, moves, e);
}

int	eights_pushing_conditions(t_stack *a, t_stack *b, t_moves *m, int *eights)
{
	if (a->stack[a->top] >= eights[eights[16]]
		&& a->stack[a->top] <= eights[eights[16] + 1])
		return (push(b, m));
	else if (a->stack[a->top + 1] >= eights[eights[16]]
		&& a->stack[a->top + 1] <= eights[eights[16] + 1])
		swap(a, m);
	else
		rot(a, m, 0);
	return (0);
}

void	eights(t_stack *a, t_stack *b, t_moves *moves, int e)
{
	int		*eights;
	int		i;

	i = 0;
	eights = get_eights(a->sorted, e);
	while (eights[16] < 16)
	{
		e = if_uneven_e(a->sorted, e, eights);
		while (i < e && a->top < a->end)
			i += eights_pushing_conditions(a, b, moves, eights);
		eight_in_b(a, b, moves, eights);
		i = 0;
		eights[16] += 2;
	}
	free(eights);
}
