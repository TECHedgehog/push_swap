/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <ericllaca@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:00:37 by ellaca-f          #+#    #+#             */
/*   Updated: 2021/06/20 17:41:15 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	low(t_stack *s, int i, int l, int size)
{
	if (s->stack[i] < l && i != s->end)
		l = s->stack[i];
	// if (s->stack[i] > lh[1] && i != s->end)
	// 	lh[1] = s->stack[i];
	if (i == s->end/* || i == size*/)
		return (l);
	return (low(s, i + 1, l, size));
}

int	median(t_stack *s, int l, int size)
{
	int	i;
	int	j;

	j = 1;
	while (j < (size + 1) / 2 )
	{
		i = 1;
		l++;
		while ((l) != s->stack[i] && i < size)
			i++;
		if ((l) == s->stack[i] && i != s->end)
			j++;
	}
	return (s->stack[i]);
}
