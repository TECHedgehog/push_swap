/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <ericllaca@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:22:17 by ellaca-f          #+#    #+#             */
/*   Updated: 2021/06/13 13:25:48 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		dprintf(2, "\n%d   -   %d", a->stack[i], b->stack[i]);
		i++;
	}
	dprintf(1, "\n---------\n");
	dprintf(1, "A   -   B\n");
}
