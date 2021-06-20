/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <ericllaca@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:23:04 by ellaca-f          #+#    #+#             */
/*   Updated: 2021/06/20 18:03:08 by ellaca-f         ###   ########.fr       */
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

void	init(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	i;

	i = 1;
	a->size = argc;
	b->size = 1;
	a->top = 1;
	b->top = argc;
	a->end = argc;
	b->end = argc;
	a->name = 'a';
	b->name = 'b';
	a->stack = malloc((argc + 1) * sizeof(int));
	b->stack = malloc((argc + 1) * sizeof(int));
	while (i < argc)
	{
		a->stack[i] = ft_atoi(argv[i]);
		b->stack[i] = 0;
		i++;
	}
	a->stack[i] = 0;
	b->stack[i] = 0;
	a->opp = b;
	b->opp = a;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_moves	*moves;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	moves = newlist("START");
	init(a, b, argc, argv);
	// print_stacks(a, b, argc);
	quicksort(a, a->size, moves);
	// three_sort(a, moves);
	// print_stacks(a, b, argc);
	print_moves(&moves);
	free_list(moves);
	return (0);
}
