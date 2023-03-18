/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_stack_d_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:33:53 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/18 03:49:21 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_duplication(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] == tab[j])
				error_and_exit();
			j++;
		}
		i++;
	}
}

void	not_intiger(int argc, char const *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != 32 && argv[i][j] != '+' && argv[i][j] != '-'
				&& (argv[i][j] < 48 || argv[i][j] > 57))
				error_and_exit();
			if ((argv[i][j] == '+' || argv[i][j] == '-')
				&& ((argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0')
				|| (j != 0 && argv[i][j - 1] != ' ')))
				error_and_exit();
			j++;
		}
		i++;
	}
}

int	*join_arguments(int argc, char const *argv[], int len)
{
	int		i;
	size_t	j;
	int		k;
	char	**tmp;
	int		*tab;

	tab = malloc(sizeof(char *) * len);
	i = 1;
	k = 0;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		j = 0;
		while (tmp[j])
		{
			tab[k] = ft_atoi(tmp[j]);
			j++;
			k++;
		}
		free_2d(tmp);
		i++;
	}
	return (tab);
}

void	check_empty(int argc, char const *argv[])
{
	int	i;
	int	j;
	int	b;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			error_and_exit();
		j = 0;
		b = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ')
			{
				b = 1;
				break ;
			}
			j++;
		}
		i++;
		if (b == 0)
			error_and_exit();
	}
}

int	*check_arg(int argc, char const *argv[])
{
	int	len;
	int	*tab_int;

	tab_int = NULL;
	if (argc > 1)
	{
		check_empty(argc, argv);
		len = count_arg(argc, argv);
		not_intiger(argc, argv);
		tab_int = join_arguments(argc, argv, len);
		check_duplication(tab_int, len);
	}
	else
		exit(0);
	return (tab_int);
}
