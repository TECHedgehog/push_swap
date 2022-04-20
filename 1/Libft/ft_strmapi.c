/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:26:43 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/10 11:29:53 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	int		i;

	if (s == NULL)
		return (0);
	newstr = malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (!newstr)
		return (0);
	i = -1;
	while (s[++i])
		newstr[i] = f(i, s[i]);
	newstr[i] = '\0';
	return (newstr);
}
