/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:53:41 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/15 00:23:28 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

t_stack_s	*ft_lstnew(int content)
{
	t_stack_s	*n;

	n = malloc(sizeof(t_stack_s));
	if (!n)
		return (NULL);
	n->content = content;
	n->next = NULL;
	return (n);
}
