/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_quarters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 00:32:00 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/13 14:18:15 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quarters_in_order(t_stack *a, t_moves *moves, int *quarters, int j)
{
	if (j)
	{
		j = quarters[8] - 2;
		while (a->stack[a->end - 1] != quarters[j + 1])
		{
			if (a->stack[a->top] <= quarters[j + 1]
				&& a->stack[a->top] >= quarters[j])
				rot(a, moves, 0);
			else
				rev_rot(a, moves, 0);
		}
	}
	else
	{
		j = quarters[8];
		while (a->stack[a->end - 1] != quarters[j + 1])
		{
			if (a->stack[a->top] <= quarters[j + 1]
				&& a->stack[a->top] >= quarters[j])
				rot(a, moves, 0);
			else
				rev_rot(a, moves, 0);
		}
	}
}

void	quarter_in_b(t_stack *a, t_stack *b, t_moves *moves, int *quarters)
{
	int	*lim;

	lim = malloc(sizeof(int) * 2);
	if (quarters[8] != 0)
		quarters_in_order(a, moves, quarters, 1);
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
	quarters_in_order(a, moves, quarters, 0);
	free(lim);
}

void	quarters_init(t_stack *a, t_stack *s, t_moves *moves)
{
	int		q;
	t_stack	*b;

	b = a->opp;
	if (s->size % 4 != 0)
		q = (s->size / 4) + 1;
	else
		q = s->size / 4;
	quarters(a, b, moves, q);
}

int	quarters_pushing_conditions(t_stack *a, t_stack *b, t_moves *m, int *quart)
{
	if (a->stack[a->top] >= quart[quart[8]]
		&& a->stack[a->top] <= quart[quart[8] + 1])
		return (push(b, m));
	else if (a->stack[a->top + 1] >= quart[quart[8]]
		&& a->stack[a->top + 1] <= quart[quart[8] + 1])
		swap(a, m);
	else
		rot(a, m, 0);
	return (0);
}

void	quarters(t_stack *a, t_stack *b, t_moves *moves, int q)
{
	int		*quarters;
	int		i;

	i = 0;
	quarters = get_quarters(a->sorted, q);
	while (quarters[8] < 8)
	{
		q = if_uneven(a->sorted, q, quarters);
		while (i < q && a->top < a->end)
			i += quarters_pushing_conditions(a, b, moves, quarters);
		quarter_in_b(a, b, moves, quarters);
		i = 0;
		quarters[8] += 2;
	}
	free(quarters);
}
