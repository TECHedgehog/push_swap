/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 13:22:17 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/08 13:15:47 by ellaca-f         ###   ########.fr       */
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

void	print_stacks_info(t_stack *a, t_stack *b, t_stack *sorted)
{
	int	i;

	i = 1;
	dprintf(2, "----a----  |  ----b----  |  ---sorted---\n");
	dprintf(2, "|       |  |  |       |  |  |          |\n");
	while (i < sorted->size + 1)
	{
		dprintf(2, "|%7d|  |  |%7d|  |  |%10d|\n", a->stack[i], b->stack[i], sorted->stack[i]);
		i++;
	}
	dprintf(2, "|----------------top-------------------|\n");
	dprintf(2, "|%7d|  |  |%7d|  |  |%10d|\n", a->top, b->top, sorted->top);
	dprintf(2, "|----------------end-------------------|\n");
	dprintf(2, "|%7d|  |  |%7d|  |  |%10d|\n", a->end, b->end, sorted->end);
	dprintf(2, "|----------------size------------------|\n");
	dprintf(2, "|%7d|  |  |%7d|  |  |%10d|\n", a->size, b->size, sorted->size);
	dprintf(2, "|--------------------------------------|\n");
}
