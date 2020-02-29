/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 16:17:17 by ihering-       #+#    #+#                */
/*   Updated: 2019/12/19 14:48:34 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	exception_sort(t_stack *stack)
{
	int	max_i;

	if (stack->size_a == 1)
		return ;
	if (stack->size_a == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			swap_a(stack);
		return ;
	}
	else if (stack->size_a == 3)
	{
		max_i = max_index(stack->stack_a, stack->size_a);
		if (max_i == 0)
			rotate_a(stack);
		if (max_i == 1)
			reverse_a(stack);
		if (stack->stack_a[0] > stack->stack_a[1])
			swap_a(stack);
	}
}

void			ft_sort(t_stack *stack)
{
	if (is_sorted(stack->stack_a, stack->size_a) && stack->size_b == 0)
		return ;
	if (stack->size_a <= 3)
		return (exception_sort(stack));
	else
		standard_sort(stack);
}
