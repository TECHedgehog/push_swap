/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 22:14:11 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/13 13:54:48 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_moves_new(t_moves *new, char *tmp, int count)
{
	while (new)
	{
		new->count = ++count;
		new->prev_move = ft_strdup(tmp);
		new = new->next;
	}
	return (count);
}
