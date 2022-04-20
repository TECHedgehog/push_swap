/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:43:07 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/10 11:28:40 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned long int	i;
	unsigned long int	j;
	unsigned long int	k;
	unsigned long int	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (dst[i] && i < dstsize)
		i++;
	l = i;
	while (src[k])
		k++;
	if (i >= dstsize || dstsize == 0)
		return (k + dstsize);
	while (src[j] != '\0' && dstsize > (dstsize - i - 2))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (k + l);
}
