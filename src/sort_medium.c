/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 00:32:00 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/03/07 21:29:52 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quarter_in_b(t_stack *a, t_stack *b, t_moves *moves, int *quarters)
{
	int	j;

	j = quarters[4];
	push(a, moves);
	while (b->top < b->end)
	{
		if (b->stack[b->top] > a->stack[a->top])
		{
			push(a, moves);
			swap(a, moves);
		}
		else
			push(a, moves);
	}
	while (a->stack[a->top] < quarters[j + 1])
		rot(a, moves, 0);
}

void	quarters(t_stack *a, t_stack *s, t_moves *moves)
{
	int		quarters[5];
	int		q[2];
	int		i;
	int		j;
	t_stack	*b;

	b = a->opp;
	(void)a;
	q[0] = s->size / 4;
	q[1] = 0;
	i = a->top;
	j = 0;
	while (j < 4)
	{
		quarters[j] = s->stack[i];
		j++;
		i += q[0];
	}
	j = 0;
	i = 1;
	quarters[4] = 0;
	while (quarters[4] < 4)
	{
		while (q[1] < q[0] && i < a->end)
		{
			if (a->stack[i] >= quarters[quarters[4]]
				&& a->stack[i] < quarters[quarters[4] + 1])
			{
				push(b, moves);
				i++;
				q[1]++;
			}
			else if ((a->stack[i + 1] >= quarters[quarters[4]]
					&& a->stack[i + 1] < quarters[quarters[4] + 1])
				&& (a->stack[i + 2] >= quarters[quarters[4]]
					&& a->stack[i + 2] < quarters[quarters[4] + 1]))
				swap(a, moves);
			else if (a->stack[a->end - 1] >= quarters[quarters[4]]
				&& a->stack[i] < quarters[quarters[4] + 1])
				rev_rot(a, moves, 0);
			else
				rot(a, moves, 0);
		}
		quarter_in_b(a, b, moves, quarters);
		q[1] = 0;
		quarters[4]++;
	}
}
