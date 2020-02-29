/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 11:36:54 by ihering-       #+#    #+#                */
/*   Updated: 2019/12/17 16:09:09 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stack)
{
	int i;

	if (stack->size_b == 0)
		return ;
	i = stack->size_a;
	while (i >= 0)
	{
		stack->stack_a[i + 1] = stack->stack_a[i];
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i <= stack->size_b)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->size_a++;
	stack->size_b--;
	if (stack->checker == 0)
		ft_putstr("pa\n");
}

void	push_b(t_stack *stack)
{
	int i;

	if (stack->size_a == 0)
		return ;
	i = stack->size_b;
	while (i >= 0)
	{
		stack->stack_b[i + 1] = stack->stack_b[i];
		i--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i <= stack->size_a - 1)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->size_b++;
	stack->size_a--;
	if (stack->checker == 0)
		ft_putstr("pb\n");
}
