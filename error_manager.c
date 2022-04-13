/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:59:19 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/13 12:28:20 by ellaca-f         ###   ########.fr       */
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
	(void)argc;
	(void)argv;

	return (0);
}