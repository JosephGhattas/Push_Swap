/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jghattas <jghattas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:52:49 by jghattas          #+#    #+#             */
/*   Updated: 2025/02/03 14:34:45 by jghattas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_2d(char **arr, int j)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (i < j)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	free2_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	split_init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free2_2d(argv);
			free_errors(a);
		}
		if (error_duplicate(*a, (int)n))
		{
			free2_2d(argv);
			free_errors(a);
		}
		append_node(a, (int)n);
		i++;
	}
}
