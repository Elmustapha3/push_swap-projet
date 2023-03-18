/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:08:54 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/07 20:12:40 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	aide_push(t_stack_s **a, t_stack_s **b, int len, int in)
{
	if (in == 1)
	{
		swap_a(a);
	}
	else if (in >= (len + 1) / 2)
	{
		while (in++ < len)
			reverse_rotate_a(a);
	}
	else
	{
		while (in-- > 0)
			rotate_a(a);
	}
	push_b(b, a);
	len--;
	return (len);
}

void	indexe_stack(t_stack_s **s, int *tab, int len)
{
	t_stack_s	*tmp;
	int			i;

	tmp = *s;
	while (tmp != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (tmp->content == tab[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

int	pushing(int in, t_stack_s **a, t_stack_s **b, t_elements e)
{
	if (in >= (e.len + 1) / 2)
	{
		while (in++ < e.len)
			reverse_rotate_a(a);
		push_b(b, a);
		if ((*a)->index <= (e.parties * e.j) - e.parties / 2)
		{
			rotate_b(b);
		}
		e.len--;
	}
	else
	{
		while (in-- > 0)
			rotate_a(a);
		if ((*a)->index <= (e.parties * e.j) - e.parties / 2)
		{
			push_b(b, a);
			rotate_b(b);
		}
		else
			push_b(b, a);
		e.len--;
	}
	return (e.len);
}

void	copy_to_b(t_stack_s **a, t_stack_s **b, int len, int chnuk)
{
	t_stack_s	*tmp;
	int			in;
	t_elements	e;

	e.len = len;
	e.parties = e.len / chnuk + 1;
	e.j = 1;
	while (e.j <= chnuk)
	{
		in = 0;
		tmp = *a;
		while (tmp != NULL)
		{
			if (tmp->index >= 0 && tmp->index < e.parties * e.j)
			{
				e.len = pushing(in, a, b, e);
				tmp = *a;
				in = 0;
				continue ;
			}
			in++;
			tmp = tmp->next;
		}
		e.j++;
	}
}
