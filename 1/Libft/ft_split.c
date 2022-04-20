/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:45:57 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/10 11:25:32 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_blocks(char const *string, char bounding)
{
	int		i;
	size_t	blocks;

	i = 0;
	blocks = 0;
	while (string[i] && string[i] == bounding)
		i++;
	while (string[i])
	{
		while (string[i] && string[i] != bounding)
			i++;
		blocks++;
		while (string[i] && string[i] == bounding)
			i++;
	}
	return (blocks);
}

static size_t	block_size(char const *string, char bounding)
{
	size_t	i;

	i = 0;
	while (string[i] && string[i] != bounding)
		i++;
	return (i);
}

static char const	*next_block(char const *string, char bounding)
{
	while (*string && *string == bounding)
		string++;
	return (string);
}

static void	free_memory(char **splitted, size_t current)
{
	size_t	i;

	i = 0;
	while (i < current)
		free(splitted[i++]);
	free(splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	blocks;
	size_t	current;

	if (s == NULL)
		return (0);
	blocks = get_blocks(s, c);
	splitted = malloc(sizeof(const char *) * (blocks + 1));
	if (!splitted)
		return (0);
	current = 0;
	while (current < blocks)
	{
		s = next_block(s, c);
		splitted[current] = ft_substr(s, 0, block_size(s, c));
		if (splitted[current] == NULL)
		{
			free_memory(splitted, current);
			return (NULL);
		}
		current++;
		s += block_size(s, c);
	}
	splitted[blocks] = NULL;
	return (splitted);
}
