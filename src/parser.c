/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:23:42 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/20 11:10:07 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Compares two stacks and returns 1 if they are equal.
 * Returns 0 if different. I use it to check with "sorted" stack if the
 * result("s") of push_swap algo is correct.
 **/
int	is_sorted(t_stack *s, t_stack *sorted)
{
	int		i;

	i = 0;
	while (i++ < sorted->size)
		if (s->stack[i] != sorted->stack[i])
			return (0);
	return (1);
}

int	is_duplicated(t_stack *s)
{
	int	i;

	i = 2;
	while (i < s->size)
	{
		if (s->stack[i] == s->stack[i - 1])
			return (1);
		i++;
	}
	return (0);
}

int	parse_stack(t_stack *a, t_stack *sorted, t_moves *moves)
{
	if (copy_stack(a, sorted) == -1)
		return (-1);
	pre_sort(sorted);
	if (is_sorted(a, sorted) || is_duplicated(sorted))
		return (-1);
	if (a->size - 1 == 2)
		swap(a, moves);
	else if (a->size - 1 == 3)
		three_sort(a, moves);
	else if (a->size - 1 == 4)
		four_sort(a, moves);
	else if (a->size - 1 == 5)
		five_sort(a, moves);
	else if (a->size - 1 > 5 && a->size - 1 < 500)
		quarters_init(a, sorted, moves);
	else
		eights_init(a, sorted, moves);
	return (1);
}
