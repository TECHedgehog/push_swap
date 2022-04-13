/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:25:55 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/10 11:29:27 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*str1;
	const unsigned char	*str2;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	i = 0;
	if (str2 < str1)
		while (++i <= len)
			str1[len - i] = str2[len - i];
	else
	{
		while (len-- > 0)
		{
			if (str1 == NULL && str2 == NULL && len > 0)
				return (dst);
			*(str1++) = *(str2++);
		}
	}
	return (dst);
}
