/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:59:19 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/10 21:32:02 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_finder(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	
	return (0);
}

int	error_manager(int argc, char **argv)
{


	return (0);
}