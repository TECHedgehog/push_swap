/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:48:45 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/03/02 13:54:47 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = malloc(count * size);
	if (s != 0)
	{
		while (i < count * size)
		{
			s[i] = '\0';
			i++;
		}
		return (s);
	}
	return (0);
}
