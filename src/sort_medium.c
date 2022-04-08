/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 00:32:00 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/08 21:14:26 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_quarters_loop(t_stack *s, int *quarters, int q, int mod)
{
	int	i;

	i = 1;
	while (quarters[8] < 7)
	{
		quarters[quarters[8]++] = s->stack[i];
		if (mod && quarters[8] == 7)
			q += mod;
		i += q;
		quarters[quarters[8]++] = s->stack[i - 1];
	}
}

int	*get_quarters(t_stack *s, int q)
{
	int	*quarters;
	int	mod;

	mod = s->size % 4;
	quarters = malloc(sizeof(int) * 9);
	quarters[8] = 0;
	if (mod != 0)
	{
		get_quarters_loop(s, quarters, q, mod);
		quarters[7] = s->end;
		quarters[8] = 0;
		return (quarters);
	}
	get_quarters_loop(s, quarters, q, mod);
	quarters[8] = 0;
	return (quarters);
}

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
	int e;
	int i;

	i = 0;
	e = 0;
	lim = malloc(sizeof(int) * 2);
	if (quarters[8] != 0)
		quarters_in_order(a, moves, quarters, 1);
	while (b->top < b->end)
	{
		e = b->stack[b->top];
		find_limits(b, lim);
		if (b->stack[b->top] == lim[0])
		{
			push(a, moves);
			rot(a, moves, 0);
		}
		else if (b->stack[b->top] == lim[1])
			push(a, moves);
		else if (b->stack[b->end] == lim[0])
		{
			rev_rot(b, moves, 0);
			push(a, moves);
			rot(a, moves, 0);
		}
		else if (b->stack[b->end - 1] == lim[1])
		{
			rev_rot(b, moves, 0);
			push(a, moves);
		}
		else
			rot(b, moves, 0);
		i++;
		(void)e;
		// print_stacks_info(a, b, a->sorted);
	}
	quarters_in_order(a, moves, quarters, 0);
	print_stacks_info(a, b, a->sorted);
	free(lim);
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

void	quarters(t_stack *a, t_stack *s, t_moves *moves)
{
	int		*quarters;
	int		q[2];
	t_stack	*b;

	b = a->opp;
	if (s->size % 4 != 0)
		q[0] = (s->size / 4) + 1;
	else
		q[0] = s->size / 4;
	q[1] = 0;
	quarters = get_quarters(s, q[0]);
	while (quarters[8] < 8)
	{
		q[0] = if_uneven(s, q[0], quarters);
		while (q[1] < q[0] && a->top < a->end)
		{
			if (a->stack[a->top] >= quarters[quarters[8]]
				&& a->stack[a->top] <= quarters[quarters[8] + 1])
			{
				push(b, moves);
				q[1]++;
			}
			else if (a->stack[a->top + 1] >= quarters[quarters[8]]
				&& a->stack[a->top + 1] <= quarters[quarters[8] + 1])
				swap(a, moves);
			else
				rot(a, moves, 0);
			print_stacks_info(a, b, s);
		}
		print_stacks_info(a, b, s);
		quarter_in_b(a, b, moves, quarters);
		q[1] = 0;
		quarters[8] += 2;
	}
	print_stacks_info(a, b, s);
}
