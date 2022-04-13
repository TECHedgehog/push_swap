/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:59:55 by ellaca-f          #+#    #+#             */
/*   Updated: 2019/11/05 12:09:38 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	int		flag;
	char	*str;

	i = 0;
	j = 0;
	flag = 0;
	str = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			j = i;
			flag = 1;
		}
		i++;
	}
	if (flag == 1)
		return (&str[j]);
	if (s[i] == c)
		return (&str[i]);
	return (0);
}
