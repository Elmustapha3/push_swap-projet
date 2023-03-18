/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:24:02 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/07 20:21:25 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_s **s)
{
	while (1)
	{
		if ((*s)->content > (*s)->next->content)
			swap_a(s);
		else if ((*s)->next->content > (*s)->next->next->content)
			reverse_rotate_a(s);
		else
			break ;
	}
}

int	get_in(t_stack_s *a)
{
	t_stack_s	*tmp;
	int			min;
	int			index;
	int			in;

	index = 1;
	in = 0;
	min = a->content;
	tmp = a->next;
	while (tmp != NULL)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			in = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (in);
}

void	sort_small_number(t_stack_s **a, t_stack_s **b, int len, int cons)
{
	int	in;

	in = get_in(*a);
	len = aide_push(a, b, len, in);
	if (len == 3)
	{
		sort_three(a);
		while (len++ < cons)
			push_a(a, b);
	}
	else
		sort_small_number(a, b, len, cons);
}

void	tsort(int *array, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	sort_big_number(t_stack_s **a, t_stack_s **b, int len, int decider)
{
	int			i;
	int			*tab;
	t_stack_s	*tmp;

	tab = malloc(4 * len);
	tmp = *a;
	i = 0;
	while (tmp != NULL)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	tsort(tab, len);
	indexe_stack(a, tab, len);
	free(tab);
	copy_to_b(a, b, len, decider);
	copy_to_a(a, b, len, len);
}
