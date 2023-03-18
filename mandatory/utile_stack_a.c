/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 05:45:14 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/06 21:42:39 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack_s **a)
{
	t_stack_s	*stmp;

	if (ft_lstsize(*a) > 1)
	{
		stmp = *a;
		(*a) = (*a)->next;
		stmp->next = NULL;
		ft_lstadd_back(a, stmp);
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stack_s **b)
{
	t_stack_s	*stmp;
	int			tmp;

	if (ft_lstsize(*b) > 1)
	{
		tmp = (*b)->content;
		stmp = *b;
		(*b) = (*b)->next;
		ft_lstadd_back(b, ft_lstnew(tmp));
		free(stmp);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack_s **sa, t_stack_s **sb)
{
	rotate_a(sa);
	rotate_b(sb);
	write(1, "rrr\n", 4);
}

void	reverse_rotate_a(t_stack_s **a)
{
	t_stack_s	*stmp;
	int			tmp;

	stmp = *a;
	if (ft_lstsize(*a) > 1)
	{
		while (stmp->next->next != NULL)
			stmp = stmp->next;
		tmp = stmp->next->content;
		free(stmp->next);
		stmp->next = NULL;
		ft_lstadd_front(a, ft_lstnew(tmp));
		write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_stack_s **b)
{
	t_stack_s	*stmp;
	int			tmp;

	stmp = *b;
	if (ft_lstsize(*b) > 1)
	{
		while (stmp->next->next != NULL)
			stmp = stmp->next;
		tmp = stmp->next->content;
		free(stmp->next);
		stmp->next = NULL;
		ft_lstadd_front(b, ft_lstnew(tmp));
		write(1, "rrb\n", 4);
	}
}
