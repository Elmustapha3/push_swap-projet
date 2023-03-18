/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:06:00 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/07 20:22:20 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack_s *s)
{
	int	max;

	max = s->content;
	while (s != NULL)
	{
		if (s->content > max)
			max = s->content;
		s = s->next;
	}
	return (max);
}

int	get_index_max(t_stack_s *s, int max)
{
	int	index;
	int	in;

	in = 0;
	index = 0;
	while (s != NULL)
	{
		if (s->content == max)
		{
			in = index;
			break ;
		}
		index++;
		s = s->next;
	}
	return (in);
}

int	check_pos_in_stack(t_stack_s **b, t_stack_s **a, t_len_in e, int count)
{
	t_stack_s	*tmp;

	tmp = *b;
	if (e.in >= (e.len + 1) / 2)
		while (e.in++ < e.len)
			reverse_rotate_b(b);
	else
	{
		while (tmp->content != e.max)
		{
			if (count == 0 || tmp->content > ft_lstlast(*a)->content)
			{
				push_a(a, b);
				rotate_a(a);
				count++;
			}
			else
				rotate_b(b);
			tmp = *b;
		}
	}
	return (count);
}

int	up_element_if_the_case(t_stack_s **a, int count, int max)
{
	while (count != 0 && max < ft_lstlast(*a)->content)
	{
		reverse_rotate_a(a);
		count--;
	}
	return (count);
}

void	copy_to_a(t_stack_s **a, t_stack_s **b, int len, int len_cnst)
{
	int			count;
	t_len_in	e;

	count = 0;
	while (ft_lstsize(*b) != 0)
	{
		len = ft_lstsize(*b);
		if (len == len_cnst)
		{
			if ((*b)->content != get_max(*b))
				count++;
			push_a(a, b);
			len--;
			continue ;
		}
		e.max = get_max(*b);
		e.in = get_index_max(*b, e.max);
		count = up_element_if_the_case(a, count, e.max);
		e.len = len;
		count = check_pos_in_stack(b, a, e, count);
		push_a(a, b);
	}
	while (count-- != 0)
		reverse_rotate_a(a);
}
