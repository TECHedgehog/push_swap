/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:16:59 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/13 14:07:37 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*newlist(const char *move)
{
	t_moves	*m;

	m = malloc(sizeof(t_moves));
	if (!m)
		return (0);
	m->move = ft_strdup(move);
	m->count = 0;
	m->prev_move = NULL;
	m->next = NULL;
	return (m);
}

int	add_move(t_moves **start, t_moves *new)
{
	int		count;
	char	*tmp;
	t_moves	*aux;

	if (!start || !new)
		return (0);
	if (!(*start))
	{
		*start = new;
		return (0);
	}
	count = (*start)->count;
	aux = (*start);
	tmp = ft_strdup(aux->move);
	while (aux->next)
	{
		free(tmp);
		count = aux->count;
		aux = aux->next;
		tmp = ft_strdup(aux->move);
	}
	aux->next = new;
	count = add_moves_new(new, tmp, count);
	free(tmp);
	return (1);
}

unsigned int	move_count(t_moves *start)
{
	int	count;

	count = 0;
	while (start)
	{
		count++;
		start = start->next;
	}
	return (count);
}

void	print_moves(t_moves **start)
{
	t_moves	*aux;

	aux = *start;
	aux = aux->next;
	while (aux)
	{
		printf("%s\n", aux->move);
		aux = aux->next;
	}
}

int	free_list(t_moves *moves)
{
	void	*aux;

	while (moves)
	{
		aux = moves->next;
		free(moves->move);
		free(moves->prev_move);
		free(moves);
		moves = aux;
	}
	return (1);
}
