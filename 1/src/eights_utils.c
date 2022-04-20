/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eights_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:41:14 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/09 16:43:42 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_uneven_e(t_stack *s, int e, int *eights)
{
	int	mod;
	int	el;

	mod = s->size % 8;
	if (mod != 0)
	{
		if (eights[16] == 14)
		{
			el = (s->size / 8) + 1;
			return (s->size - el * 7);
		}
	}
	return (e);
}
