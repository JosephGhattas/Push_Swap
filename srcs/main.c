/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghattas <jghattas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:03:40 by jghattas          #+#    #+#             */
/*   Updated: 2025/02/03 14:32:56 by jghattas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

static int	check_argc(int argc, char **argv, t_stack_node **a)
{
	char	**argv_split;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv_split = split(argv[1], ' ');
		if (!argv_split)
			return (1);
		if (split_errors(argv_split, len(argv_split)) == 1)
		{
			free_2d(argv_split, len(argv_split));
			return (1);
		}
		split_init_stack_a(a, argv_split);
		free_2d(argv_split, stack_len(*a));
	}
	else
		init_stack_a(a, argv + 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len;
	int				check;

	a = NULL;
	b = NULL;
	check = check_argc(argc, argv, &a);
	if (check != 0)
		return (check);
	len = stack_len(a);
	if (!stack_sorted(a))
	{
		if (len == 2)
			sa(&a, false);
		else if (len == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
