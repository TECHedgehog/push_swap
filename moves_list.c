/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <ericllaca@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:16:59 by ellaca-f          #+#    #+#             */
/*   Updated: 2021/06/20 18:12:59 by ellaca-f         ###   ########.fr       */
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
	while (new)
	{
		new->count = ++count;
		new->prev_move = ft_strdup(tmp);
		new = new->next;
	}
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

void	free_list(t_moves *moves)
{
	void	*aux;

	while (moves)
	{
		aux = moves->next;
		free(moves->move);
		free(moves);
		moves = aux;
	}
}
