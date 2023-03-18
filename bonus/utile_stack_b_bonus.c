/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_stack_b_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:01:44 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/06 21:42:48 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_a(t_stack_s **s)
{
	int	tmp;

	if (ft_lstsize(*s) > 1)
	{
		tmp = (*s)->content;
		(*s)->content = (*s)->next->content;
		(*s)->next->content = tmp;
	}
}

void	swap_b(t_stack_s **s)
{
	int	tmp;

	if (ft_lstsize(*s) > 1)
	{
		tmp = (*s)->content;
		(*s)->content = (*s)->next->content;
		(*s)->next->content = tmp;
	}
}

void	ss(t_stack_s **sa, t_stack_s **sb)
{
	swap_a(sa);
	swap_b(sb);
}

void	push_a(t_stack_s **sa, t_stack_s **sb)
{
	t_stack_s	*stmp;

	if ((*sb) != NULL)
	{
		stmp = *sb;
		(*sb) = (*sb)->next;
		ft_lstadd_front(sa, stmp);
	}
}

void	push_b(t_stack_s **sb, t_stack_s **sa)
{
	t_stack_s	*stmp;

	if ((*sa) != NULL)
	{
		stmp = *sa;
		(*sa) = (*sa)->next;
		ft_lstadd_front(sb, stmp);
	}
}
