/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:53:21 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/18 03:52:52 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_and_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

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

void	appel_for_s_3(t_stack_s **a, t_stack_s **b, char *inst)
{
	if (inst[0] == 's' && inst[1] == 'a' && inst[2] == 10)
		swap_a(a);
	else if (inst[0] == 's' && inst[1] == 'b' && inst[2] == 10)
		swap_b(b);
	else if (inst[0] == 's' && inst[1] == 's' && inst[2] == 10)
		ss(a, b);
	else if (inst[0] == 'r' && inst[1] == 'a' && inst[2] == 10)
		rotate_a(a);
	else if (inst[0] == 'r' && inst[1] == 'b' && inst[2] == 10)
		rotate_b(b);
	else if (inst[0] == 'r' && inst[1] == 'r' && inst[2] == 10)
		rr(a, b);
	else if (inst[0] == 'p' && inst[1] == 'a' && inst[2] == 10)
		push_a(a, b);
	else if (inst[0] == 'p' && inst[1] == 'b' && inst[2] == 10)
		push_b(b, a);
	else
		error_and_exit();
}

void	apple_for_s_4(t_stack_s **a, t_stack_s **b, char *inst)
{
	if (inst[0] == 'r' && inst[1] == 'r' && inst[2] == 'a' && inst[3] == 10)
		reverse_rotate_a(a);
	else if (inst[0] == 'r' && inst[1] == 'r'
		&& inst[2] == 'b' && inst[3] == 10)
		reverse_rotate_b(b);
	else if (inst[0] == 'r' && inst[1] == 'r'
		&& inst[2] == 'r' && inst[3] == 10)
		rrr(a, b);
	else
		error_and_exit();
}

int	main(int argc, const char *argv[])
{
	t_stack_s	*a;
	t_stack_s	*b;
	char		*inst;
	int			*mytab;
	int			len;

	b = NULL;
	len = count_arg(argc, argv);
	mytab = check_arg(argc, argv);
	initialize_stack(&a, mytab, len);
	while (1)
	{
		inst = get_next_line(0);
		if (!inst)
			break ;
		len = ft_strlen(inst);
		if (len == 3)
			appel_for_s_3(&a, &b, inst);
		else if (len == 4)
			apple_for_s_4(&a, &b, inst);
		else
			error_and_exit();
		free(inst);
	}
	check_sort(&a, &b, len);
}
