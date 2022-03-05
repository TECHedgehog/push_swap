/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:23:42 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/03/05 00:25:47 by ellaca-f         ###   ########.fr       */
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

int	parse_stack(t_stack *a, t_stack *sorted)
{
	(void)a;
	(void)sorted;
	// int	quarters[4];
	// int	eight[8];
	// int	q;
	// int	e;
	// int	i;

	// if (!a || a->size <= 1 || is_sorted(a, sorted))
	// 	return (-1);
	// if (a->size > 5 && a->size < 500)
	// {
	// 	quarter = a->size / 4;
	// }
	return (1);
}
