/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eights_utils_more.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:32:43 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/09 16:39:18 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_eights_loop(t_stack *s, int *eights, int e, int mod)
{
	int	i;

	i = 1;
	while (eights[16] < 15)
	{
		eights[eights[16]++] = s->stack[i];
		if (mod && eights[16] == 15)
			e += mod;
		i += e;
		eights[eights[16]++] = s->stack[i - 1];
	}
}

int	*get_eights(t_stack *s, int e)
{
	int	*eights;
	int	mod;

	mod = s->size % 8;
	eights = malloc(sizeof(int) * 17);
	eights[16] = 0;
	if (mod != 0)
	{
		get_eights_loop(s, eights, e, mod);
		eights[15] = s->end;
		eights[16] = 0;
		return (eights);
	}
	get_eights_loop(s, eights, e, mod);
	eights[16] = 0;
	return (eights);
}
