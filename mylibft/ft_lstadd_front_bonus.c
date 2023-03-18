/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:57:46 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/25 01:13:19 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	ft_lstadd_front(t_stack_s **lst, t_stack_s *new)
{
	new->next = *lst;
	*lst = new;
}
