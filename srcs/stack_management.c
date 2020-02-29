/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_management.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 16:14:34 by ihering-       #+#    #+#                */
/*   Updated: 2019/12/17 16:14:36 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *stack, int width)
{
	stack->stack_a = (int *)malloc(sizeof(int) * (width + 1));
	stack->stack_b = (int *)ft_memalloc(sizeof(int) * (width + 1));
	stack->size_a = width;
	stack->size_b = 0;
	stack->checker = 0;
}

void	free_stack(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	free(stack);
	stack = NULL;
}

int		width_count(char **nb)
{
	int width;

	width = 0;
	while (nb[width] != '\0')
		width++;
	return (width);
}

int		is_sorted(int *stack, int width)
{
	int	i;

	i = 0;
	while (i < width - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
