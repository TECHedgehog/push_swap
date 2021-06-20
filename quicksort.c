/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <ericllaca@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:48:56 by ellaca-f          #+#    #+#             */
/*   Updated: 2021/06/20 18:03:28 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	three_sort(t_stack *s, t_moves *moves)
{
	if (s->stack[s->top + 1] > s->stack[s->top]
		&& s->stack[s->top + 2] > s->stack[s->top + 1])
		return (1);
	else if (s->stack[s->top] < s->stack[s->top + 2]
		&& s->stack[s->top + 2] < s->stack[s->top + 1])
	{
		swap(s, moves);
		rot(s, moves, 0);
	}
	else if (s->stack[s->top + 1] < s->stack[s->top]
		&& s->stack[s->top] < s->stack[s->top + 2])
		swap(s, moves);
	else if (s->stack[s->top + 2] < s->stack[s->top]
		&& s->stack[s->top] < s->stack[s->top + 1])
		rev_rot(s, moves, 0);
	else if (s->stack[s->top + 1] < s->stack[s->top + 2]
		&& s->stack[s->top + 2] < s->stack[s->top])
		rot(s, moves, 0);
	else if (s->stack[s->top + 2] < s->stack[s->top + 1]
		&& s->stack[s->top + 1] < s->stack[s->top])
	{
		rot(s, moves, 0);
		swap(s, moves);
	}
	return (1);
}

int	sort(t_stack *s, t_moves *moves)
{
	int		i;
	int		l;
	t_stack	*opp;

	opp = (t_stack *)s->opp;
	i = s->top;
	while (1)
	{
		l = low(s, s->top, s->stack[s->top], s->size);
		if (s->stack[i] == l)
		{
			push(opp, moves);
			rot(opp, moves, 0);
			i++;
			if (i == s->end)
				return (1);
		}
		else if (s->stack[i + 1] == l)
			swap(s, moves);
		else if (s->stack[s->end - 1] == l)
		{
			// if (opp->stack[opp->top] > opp->stack[opp->end])
			// 	rev_rot(s, moves, '+');
			// else
				rev_rot(s, moves, 0);
		}
		else
		{
			// if (opp->stack[opp->top] > opp->stack[opp->end])
			// 	rot(s, moves, '+');
			// else
				rot(s, moves, 0);
		}
		// print_stacks(s->opp, s, 11);
	}
	return (1);
}

int	push_all_sort(t_stack *s, int l, t_moves *moves)
{
	t_stack	*opp;
	int		i;

	opp = s->opp;
	i = s->top;
	while (s->stack[i++] != l)
		push(opp, moves);
	sort(opp, moves);
	return (1);
}

int	quicksort(t_stack *s, int size, t_moves *moves)
{
	int	i;
	int	l;
	int	m;

	i = s->top;
	l = low(s, 1, s->stack[s->top], size - 1);
	m = median(s, l, size);
	size = (size + 1) / 2 + 1;
	while (i < size)
	{
		if (s->stack[i] <= m)
		{
			push(s->opp, moves);
			i++;
		}
		else if (s->stack[i + 1] <= m)
			swap(s, moves);
		else
			rot(s, moves, 0);
		// print_stacks(s, s->opp, 11);
	}
	sort(s->opp, moves);
	// print_stacks(s, s->opp, 11);
	if (s->stack[1] != l)
		push_all_sort(s, l, moves);
	// print_moves(&moves);
	return (1);
}
