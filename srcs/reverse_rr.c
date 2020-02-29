/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 11:39:52 by ihering-       #+#    #+#                */
/*   Updated: 2019/12/17 16:09:46 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size_a == 0)
		return ;
	i = stack->size_a - 1;
	temp = stack->stack_a[i];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = temp;
	if (stack->checker == 0)
		ft_putstr("rra\n");
}

void	reverse_b(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size_b == 0)
		return ;
	i = stack->size_b - 1;
	temp = stack->stack_b[i];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = temp;
	if (stack->checker == 0)
		ft_putstr("rrb\n");
}

void	reverse_ab(t_stack *stack)
{
	int	temp_checker;

	temp_checker = stack->checker;
	stack->checker = 1;
	reverse_a(stack);
	reverse_b(stack);
	stack->checker = temp_checker;
	if (stack->checker == 0)
		ft_putstr("rrr\n");
}
