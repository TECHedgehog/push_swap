/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 09:30:35 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/04/24 09:31:01 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		count;
	int		i;
	char	c;

	count = 0;
	while (str[count] != '\0')
		count++;
	count = count - 1;
	i = 0;
	while (i < ((count + 1) / 2))
	{
		c = str[i];
		str[i] = str[count - i];
		str[count - i] = c;
		i++;
	}
	return (str);
}
