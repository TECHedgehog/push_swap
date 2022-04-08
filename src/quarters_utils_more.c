/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarters_utils_more.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:51:01 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/08 21:52:29 by ellaca-f         ###   ########.fr       */
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
