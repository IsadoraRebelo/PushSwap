/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotates.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 12:45:06 by ihering-       #+#    #+#                */
/*   Updated: 2019/12/21 14:21:14 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		define_a(int width, int i, t_moves *rotate)
{
	if (i > width / 2)
	{
		rotate->rotate_a = 1;
		if (width > 2)
			i = width - i;
	}
	else
		rotate->rotate_a = 2;
	return (i);
}

int		define_b(int width, int i, t_moves *rotate)
{
	if (i > width / 2)
	{
		rotate->rotate_b = 1;
		if (width > 2)
			i = width - i;
	}
	else
		rotate->rotate_b = 2;
	return (i);
}

int		define_ab(t_moves *moves)
{
	int	moviment;

	moviment = 0;
	if ((moves->rotate_a == 1 && moves->rotate_b == 1) || \
			(moves->rotate_a == 2 && moves->rotate_b == 2))
	{
		if (moves->move_a > moves->move_b)
			moviment = moves->move_b;
		else
			moviment = moves->move_a;
		if (moviment)
		{
			moves->rotate_ab = moves->rotate_a;
			moves->move_a -= moviment;
			moves->move_b -= moviment;
		}
	}
	return (moviment);
}
