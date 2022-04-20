/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:03:42 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/20 11:08:51 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(int i)
{
	write(1, "Error\n", 6);
	return (i);
}

int	ft_isspace(char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		return (1);
	return (0);
}

int	has_spaces(char *argv)
{
	int	k;

	k = 0;
	if (!argv)
		return (0);
	while (argv[k])
	{
		if (ft_isspace(argv, k))
			return (1);
		k++;
	}
	return (0);
}

int	copy_args(char *argv, t_stack *a, int k)
{
	int		j;
	int		neg;

	j = 0;
	neg = 1;
	while (argv[j])
	{
		while (ft_isspace(argv, j))
			j++;
		if (argv[j] == '-')
		{
			j++;
			neg = -1;
		}
		a->stack[k] = (argv[j] - 48) * neg;
		k++;
		j++;
		neg = 1;
	}
	return (k);
}

int	arg_size(char **argv, int argc)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	argc -= 1;
	while (argc > 0)
	{
		while (argv[argc][i])
		{
			while (ft_isspace(argv[argc], i) || argv[argc][i] == '-')
				i++;
			count++;
			i++;
		}
		argc--;
	}
	return (count);
}
