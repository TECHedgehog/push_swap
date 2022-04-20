/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:24:29 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/10 11:17:59 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstack, const char *ndle, size_t len)
{
	unsigned long int	i;
	unsigned long int	j;

	i = 0;
	j = 0;
	if (ndle[0] == '\0')
		return ((char *)hstack);
	while (hstack[i] != '\0' && i < len)
	{
		j = 0;
		if (hstack[i] == ndle[j])
		{
			while (hstack[i + j] == ndle[j] && ndle[j] != '\0')
				j++;
			if (ndle[j] == '\0' && i + j <= len)
				return ((char *)&hstack[i]);
		}
		i++;
	}
	return (0);
}
