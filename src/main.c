/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:01:59 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/08 22:23:02 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *s, t_moves *moves)
{
	t_stack	*opp;

	opp = (t_stack *)s->opp;
	if (s->top == 1)
		s->stack[s->top] = opp->stack[opp->top];
	else
		s->stack[--s->top] = opp->stack[opp->top];
	opp->stack[opp->top++] = 0;
	opp->size--;
	s->size++;
	if (s->name == 'b')
		return (add_move(&moves, newlist("pb")));
	return (add_move(&moves, newlist("pa")));
}

int	swap(t_stack *s, t_moves *moves)
{
	int		tmp;
	t_stack	*opp;

	opp = s->opp;
	tmp = s->stack[s->top];
	s->stack[s->top] = s->stack[s->top + 1];
	s->stack[s->top + 1] = tmp;
	if (opp->stack[opp->top] > opp->stack[opp->top + 1] && opp->top < opp->size)
	{
		tmp = opp->stack[opp->top];
		opp->stack[opp->top] = opp->stack[opp->top + 1];
		opp->stack[opp->top + 1] = tmp;
		return (add_move(&moves, newlist("ss")));
	}
	else if (s->name == 'a')
		return (add_move(&moves, newlist("sa")));
	return (add_move(&moves, newlist("sb")));
}

int	rev_rot(t_stack *s, t_moves *moves, char c)
{
	int		tmp;
	int		i;
	t_stack	*opp;

	opp = s->opp;
	i = s->end;
	tmp = s->stack[s->end - 1];
	while (--i > s->top)
		s->stack[i] = s->stack[i - 1];
	s->stack[i] = tmp;
	if (c == '+')
	{
		i = opp->end;
		tmp = opp->stack[opp->end - 1];
		while (--i > opp->top)
			opp->stack[i] = opp->stack[i - 1];
		opp->stack[i] = tmp;
		return (add_move(&moves, newlist("rrr")));
	}
	if (s->name == 'a')
		return (add_move(&moves, newlist("rra")));
	return (add_move(&moves, newlist("rrb")));
}

int	rot(t_stack *s, t_moves *moves, char c)
{
	int		tmp;
	int		i;
	t_stack	*opp;

	opp = s->opp;
	i = s->top - 1;
	tmp = s->stack[s->top];
	while (++i < s->end)
		s->stack[i] = s->stack[i + 1];
	s->stack[i - 1] = tmp;
	if (c == '+')
	{
		i = opp->top - 1;
		tmp = opp->stack[opp->top];
		while (++i < opp->end)
			opp->stack[i] = opp->stack[i + 1];
		opp->stack[i - 1] = tmp;
		return (add_move(&moves, newlist("rr")));
	}
	if (s->name == 'a')
		return (add_move(&moves, newlist("ra")));
	return (add_move(&moves, newlist("rb")));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*sorted;
	t_moves	*moves;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	sorted = malloc(sizeof(t_stack));
	moves = newlist("START");
	if (init(a, b, argc, argv) == -1)
		return (free_all(moves, a, b, sorted));
	if (parse_stack(a, sorted, moves) == -1)
		return (free_all(moves, a, b, sorted));
	print_moves(&moves);
	return (free_all(moves, a, b, sorted));
}
