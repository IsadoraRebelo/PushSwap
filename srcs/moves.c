/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 10:41:05 by ihering-       #+#    #+#                */
/*   Updated: 2019/12/21 14:42:52 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				stack_a(int *stack, int width, int nb, t_moves *rotate)
{
	int	i;
	int index;

	i = 0;
	index = 0;
	if (width == 2 && nb > stack[0] && nb < stack[1])
		index = 1;
	else if (width == 2 && nb < stack[0] && nb > stack[1])
		index = 0;
	else if (nb > stack[max_index(stack, width)] || \
		nb < stack[min_index(stack, width)])
		index = min_index(stack, width);
	else
		while (i < width)
		{
			if (nb > stack[i] && ((i + 1 < width && nb < stack[i + 1]) || \
				(i + 1 == width && nb < stack[0])))
			{
				index = i + 1;
				break ;
			}
			i++;
		}
	return (define_a(width, index, rotate));
}

static int		stack_b(int *stack, int width, int nb, t_moves *rotate)
{
	int	i;
	int index;

	i = 0;
	index = 0;
	if (width == 2 && nb > stack[0] && nb < stack[width - 1])
		index = 0;
	else if (width == 2 && nb < stack[0] && nb > stack[width - 1])
		index = 1;
	else if (nb > stack[max_index(stack, width)] || \
		nb < stack[min_index(stack, width)])
		index = max_index(stack, width);
	else
		while (i < width)
		{
			if (nb < stack[i] && ((i + 1 < width && nb > stack[i + 1]) || \
				(i + 1 == width && nb > stack[0])))
			{
				index = i + 1;
				break ;
			}
			i++;
		}
	return (define_b(width, index, rotate));
}

static t_moves	*initi_moves(t_stack *stack, int i)
{
	t_moves	*move;

	move = (t_moves *)ft_memalloc(sizeof(t_moves));
	move->nb = stack->stack_a[i];
	move->rotate_a = 0;
	move->rotate_b = 0;
	move->rotate_ab = 0;
	move->move_a = define_a(stack->size_a, i, move);
	move->move_b = stack_b(stack->stack_b, stack->size_b, \
							stack->stack_a[i], move);
	move->move_ab = define_ab(move);
	move->result = move->move_a + move->move_b + move->move_ab + 1;
	return (move);
}

t_moves			*moves(t_stack *stack)
{
	int			i;
	t_moves		*chosen_move;
	t_moves		*moves;

	i = 0;
	while (i < stack->size_a)
	{
		moves = initi_moves(stack, i);
		if (i == 0)
			chosen_move = moves;
		else if (chosen_move->result > moves->result)
		{
			free(chosen_move);
			chosen_move = moves;
		}
		else
			free(moves);
		i++;
	}
	return (chosen_move);
}
