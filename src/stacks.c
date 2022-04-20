/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <eric@llacafeijo.es>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:57:02 by ellaca-f          #+#    #+#             */
/*   Updated: 2022/04/20 11:09:24 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pre_init(t_stack *a, t_stack *b, int argc, char **argv)
{
	a->size = arg_size(argv, argc) + 1;
	b->size = 1;
	a->top = 1;
	b->top = b->size;
	a->name = 'a';
	b->name = 'b';
	a->stack = malloc((a->size + 1) * sizeof(int));
	b->stack = malloc((b->size + 1) * sizeof(int));
	return (1);
}

/**
 * Initialaizes two main stacks("a" & "b"). "argc" is used to know
 * the size of the stack. "argv" is used along with ft_atoi to copy
 * values passed in console to the stack(int[]).
 **/
int	init(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	j;

	j = pre_init(a, b, argc, argv);
	if (!a->stack || !b->stack)
		return (-1);
	while (a->top < a->size)
	{
		if (has_spaces(argv[j]))
			a->top = copy_args(argv[j], a, a->top);
		else
		{
			a->stack[a->top] = ft_atoi(argv[j]);
			b->stack[a->top++] = 0;
		}
		if (j < argc - 1)
			j++;
	}
	a->end = a->top;
	b->end = a->top;
	a->stack[a->top] = 0;
	b->stack[a->top] = 0;
	a->opp = b;
	b->opp = a;
	a->top = 1;
	return (0);
}

/**
 * Stores in "sorted" a solved version of the values passed
 * using bubble sort. FUNCTIONAL, not EFFICIENT (;
 * It's used to compare the final result of push_swap algo with the
 * correct result.
 **/
void	pre_sort(t_stack *sorted)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	j = 0;
	aux = 0;
	while (++i < (sorted->size + 1))
	{
		while (++j < sorted->size)
		{
			if (sorted->stack[j] > sorted->stack[j + 1])
			{
				aux = sorted->stack[j];
				sorted->stack[j] = sorted->stack[j + 1];
				sorted->stack[j + 1] = aux;
			}
		}
		j = 0;
	}
	sorted->top = sorted->stack[1];
	sorted->end = sorted->stack[sorted->size];
}

/**
 * Designed to copy the original stack("source") to the
 * sorted one("dest") before using 'pre_sort'. It's intended for that
 * just because it sets void pointers for the sorted stack in stacks a
 * and b. 
 * "source->sorted = dest"	a->sorted pointing sorted
 * "opp->sorted = dest"		b->sorted pointing sorted
 **/
int	copy_stack(t_stack *source, t_stack *dest)
{
	int		i;
	t_stack	*opp;

	i = -1;
	opp = source->opp;
	dest->name = 's';
	dest->opp = NULL;
	dest->size = source->size - 1;
	dest->sorted = NULL;
	dest->stack = malloc((dest->size + 1) * sizeof(int));
	if (!dest->stack)
		return (-1);
	while (++i < (dest->size + 1))
		dest->stack[i] = source->stack[i];
	source->sorted = dest;
	opp->sorted = dest;
	return (0);
}

void	free_stacks(t_stack *a, t_stack *b, t_stack *sorted)
{
	free(a->stack);
	free(b->stack);
	free(sorted->stack);
}
