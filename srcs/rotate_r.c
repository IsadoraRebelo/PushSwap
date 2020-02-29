/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_r.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 11:37:34 by ihering-       #+#    #+#                */
/*   Updated: 2019/12/17 16:09:23 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size_a == 0)
		return ;
	i = 1;
	temp = stack->stack_a[0];
	while (i < stack->size_a)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->stack_a[i - 1] = temp;
	if (stack->checker == 0)
		ft_putstr("ra\n");
}

void	rotate_b(t_stack *stack)
{
	int	i;
	int	temp;

	if (stack->size_b == 0)
		return ;
	i = 1;
	temp = stack->stack_b[0];
	while (i < stack->size_b)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->stack_b[i - 1] = temp;
	if (stack->checker == 0)
		ft_putstr("rb\n");
}

void	rotate_ab(t_stack *stack)
{
	int	temp_checker;

	temp_checker = stack->checker;
	stack->checker = 1;
	rotate_a(stack);
	rotate_b(stack);
	stack->checker = temp_checker;
	if (stack->checker == 0)
		ft_putstr("rr\n");
}
