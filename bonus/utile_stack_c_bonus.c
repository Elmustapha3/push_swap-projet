/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_stack_c_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:01:35 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/18 03:53:31 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	disp_stack(t_stack_s *lst)
{
	if (lst == NULL)
		printf("stack vide");
	while (lst != NULL)
	{
		printf("%d\n", lst->content);
		lst = lst->next;
	}
}

void	check_sort(t_stack_s **s, t_stack_s **b, int len)
{
	t_stack_s	*tmp;
	t_stack_s	*aide;
	int			checker;

	checker = 1;
	tmp = *s;
	while (!ft_lstsize(*b) && tmp->next != NULL)
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
	if (checker == 0 || len == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	rrr(t_stack_s **sa, t_stack_s **sb)
{
	reverse_rotate_a(sa);
	reverse_rotate_b(sb);
}

int	count_arg(int argc, char const *argv[])
{
	int		i;
	int		j;
	int		count;
	char	**tmp;

	count = 0;
	i = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		j = 0;
		while (tmp[j])
		{
			count++;
			j++;
		}
		free_2d(tmp);
		i++;
	}
	return (count);
}
