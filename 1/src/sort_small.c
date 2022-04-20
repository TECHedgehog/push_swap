/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 00:31:39 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/09 16:58:48 by ellaca-f         ###   ########.fr       */
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

int	four_sort(t_stack *s, t_moves *moves)
{
	t_stack	*opp;
	int		*lim;

	opp = s->opp;
	lim = malloc(sizeof(int) * 2);
	find_limits(s, lim);
	while (s->stack[s->top] != lim[0])
	{
		if (s->stack[s->end] == lim[0] || s->stack[s->end - 1] == lim[0])
			rev_rot(s, moves, 0);
		else
			rot(s, moves, 0);
	}
	push(opp, moves);
	three_sort(s, moves);
	push(s, moves);
	free(lim);
	return (1);
}

int	five_sort(t_stack *s, t_moves *moves)
{
	t_stack	*opp;
	int		*lim;

	opp = s->opp;
	lim = malloc(sizeof(int) * 2);
	find_limits(s, lim);
	while (s->stack[s->top] != lim[0])
	{
		if (s->stack[s->end] == lim[0] || s->stack[s->end - 1] == lim[0])
			rev_rot(s, moves, 0);
		else
			rot(s, moves, 0);
	}
	push(opp, moves);
	four_sort(s, moves);
	push(s, moves);
	free(lim);
	return (1);
}
