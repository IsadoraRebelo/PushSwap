/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validating.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 16:00:06 by ihering-       #+#    #+#                */
/*   Updated: 2020/01/03 11:13:20 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_valid(char **nb, char *num, int start)
{
	int i;

	i = 0;
	while (*num && num[i])
	{
		if (!ft_isdigit(num[i]) && num[i] != '-')
			return (0);
		i++;
	}
	if (ft_atoi(num) > INT_MAX || ft_atoi(num) < INT_MIN)
		return (0);
	while (nb[start] && nb && num)
	{
		if (ft_strequ(nb[start], num))
			return (0);
		start++;
	}
	return (1);
}

t_stack			*validate_nb(t_stack *stack, char **nb, int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		if (is_valid(nb, nb[i], i + 1))
			stack->stack_a[i] = ft_atoi(nb[i]);
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	return (stack);
}
