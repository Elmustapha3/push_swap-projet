/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 23:37:56 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/14 21:46:37 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	error_and_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
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

int	main(int argc, char const *argv[])
{
	t_stack_s	*a;
	t_stack_s	*b;
	int			*mytab;
	int			len;

	b = NULL;
	len = count_arg(argc, argv);
	mytab = check_arg(argc, argv);
	initialize_stack(&a, mytab, len);
	check_sort(&a);
	if (len == 2)
		swap_a(&a);
	else if (len == 3)
		sort_three(&a);
	else if (len < 50)
		sort_small_number(&a, &b, len, len);
	else if (len <= 100)
		sort_big_number(&a, &b, len, 5);
	else
		sort_big_number(&a, &b, len, 11);
}
