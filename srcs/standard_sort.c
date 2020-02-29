/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   standard_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 14:13:49 by ihering-       #+#    #+#                */
/*   Updated: 2020/01/03 10:52:15 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		first_stack_a(t_stack *stack)
{
	int	m_index;

	m_index = min_index(stack->stack_a, stack->size_a);
	if (m_index <= stack->size_a / 2)
		while (m_index)
		{
			rotate_a(stack);
			m_index--;
		}
	else
		while ((stack->size_a - m_index) > 0)
		{
			reverse_a(stack);
			m_index++;
		}
}

static void		fill_stack_a(t_stack *stack, t_moves *rotate)
{
	int		rotation;

	rotation = 0;
	while (stack->size_b)
	{
		rotation = stack_a(stack->stack_a, stack->size_a, stack->stack_b[0], \
		rotate);
		while (rotation > 0)
		{
			if (rotate->rotate_a == 2)
				rotate_a(stack);
			else
				reverse_a(stack);
			rotation--;
		}
		push_a(stack);
	}
	first_stack_a(stack);
}

static void		fill_stack_b(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->size_a > 2)
	{
		i = min_index(stack->stack_a, stack->size_a);
		if (i == 0)
			push_b(stack);
		else if (i <= stack->size_a / 2)
			rotate_a(stack);
		else if (i > stack->size_a / 2)
			reverse_a(stack);
	}
}

static void		operations(t_moves *movement, t_stack *stack)
{
	while (movement->move_a)
	{
		if (movement->rotate_a == 2)
			rotate_a(stack);
		else
			reverse_a(stack);
		movement->move_a--;
	}
	while (movement->move_b)
	{
		if (movement->rotate_b == 2)
			rotate_b(stack);
		else
			reverse_b(stack);
		movement->move_b--;
	}
}

void			standard_sort(t_stack *stack)
{
	t_moves	*movement;
	int		define;

	define = 2;
	if (stack->size_a > 200)
		define = 50;
	while (stack->size_b != 2)
		push_b(stack);
	while (stack->size_a > define)
	{
		movement = moves(stack);
		while (movement->move_ab)
			best_move(movement, stack);
		operations(movement, stack);
		push_b(stack);
		free(movement);
	}
	fill_stack_b(stack);
	fill_stack_a(stack, movement);
}
