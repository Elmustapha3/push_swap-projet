/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_stack_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:01:35 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/08 17:41:59 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack(t_stack_s **s, int *tabl, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(s, ft_lstnew(tabl[i]));
		i++;
	}
	free(tabl);
}

void	check_sort(t_stack_s **s)
{
	t_stack_s	*tmp;
	t_stack_s	*aide;
	int			checker;

	tmp = *s;
	while (tmp->next != NULL)
	{
		checker = 0;
		aide = tmp->next;
		while (aide != NULL)
		{
			if (tmp->content > aide->content)
				checker = 1;
			aide = aide->next;
		}
		if (checker == 1)
			break ;
		tmp = tmp->next;
	}
	if (checker == 0)
	{
		exit(0);
	}
}

void	rrr(t_stack_s **sa, t_stack_s **sb)
{
	reverse_rotate_a(sa);
	reverse_rotate_b(sb);
	write(1, "rrr\n", 4);
}
