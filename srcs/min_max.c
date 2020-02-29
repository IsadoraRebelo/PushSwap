/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   min_max.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 11:07:55 by ihering-       #+#    #+#                */
/*   Updated: 2019/12/19 11:21:05 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		min_index(int *stack, int width)
{
	int	i;
	int	temp;
	int	index;

	if (width == 0)
		return (-1);
	i = 0;
	index = 0;
	temp = stack[i];
	while (i < width)
	{
		if (temp > stack[i])
		{
			temp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		max_index(int *stack, int width)
{
	int	i;
	int	temp;
	int	index;

	if (width == 0)
		return (-1);
	i = 0;
	index = 0;
	temp = stack[i];
	while (i < width)
	{
		if (temp < stack[i])
		{
			temp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}
