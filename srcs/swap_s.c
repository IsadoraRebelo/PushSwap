/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 11:33:50 by ihering-       #+#    #+#                */
/*   Updated: 2019/12/17 16:08:10 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int temp;

	if (stack->size_a < 2)
		return ;
	temp = stack->stack_a[0];
	stack->stack_a[0] = stack->stack_a[1];
	stack->stack_a[1] = temp;
	if (stack->checker == 0)
		ft_putstr("sa\n");
}

void	swap_b(t_stack *stack)
{
	int temp;

	if (stack->size_b < 2)
		return ;
	temp = stack->stack_b[0];
	stack->stack_b[0] = stack->stack_b[1];
	stack->stack_b[1] = temp;
	if (stack->checker == 0)
		ft_putstr("sb\n");
}

void	swap_ab(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
	if (stack->checker == 0)
		ft_putstr("ss\n");
}
