/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:00:37 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/02/25 16:21:39 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Returns LOWEST number from the range of numbers 
 * in the stack("s") defined by "size". When calling 
 * the function, "l" should be set to a number contained 
 * in the range, for instance, "s->stack[size]".
 **/
int	low(t_stack *s, int l, int size)
{
	if (s->stack[size] < l && size)
		l = s->stack[size];
	if (!size)
		return (l);
	return (low(s, l, --size));
}

/**
 * Returns MEDIAN from the range of numbers in the
 * stack("s") defined by "size". Uses the lowest("l")
 * number in the range to calculate it.
 **/
int	median(t_stack *s, int l, int size)
{
	int	i;
	int	j;

	j = 1;
	while (j < (size + 1) / 2)
	{
		i = s->top;
		l++;
		while (l != s->stack[i] && i < size)
			i++;
		if (l == s->stack[i] && i != s->end)
			j++;
	}
	return (s->stack[i]);
}

/**
 * Returns LENGTH of stack("s"). Begins counting
 * backwards from the "end" of the stack.
 **/
int	stacklen(t_stack *s, int end)
{
	int	i;

	i = 0;
	while (s->stack[--end])
		i++;
	return (i);
}

/**
 * Returns LENGTH until the lowest("l") number in the stack("s").
 * Can be used to calculate the LENGHT of a range in the stack
 * setting "l" to the number where we want to stop counting.
 **/
int	find_low(t_stack *s, int l)
{
	int	i;

	i = 1;
	while (s->stack[i] != l)
		i++;
	return (i);
}
