/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/15 15:18:41 by ihering-       #+#    #+#                */
/*   Updated: 2020/01/03 10:52:43 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		**split_args(int *argc, char ***argv)
{
	char **tmp;

	tmp = ft_strsplit((*argv)[0], ' ');
	*argc = 0;
	while (tmp && tmp[*argc])
		(*argc)++;
	if (argc == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (tmp);
}

void			best_move(t_moves *movement, t_stack *stack)
{
	if (movement->rotate_ab == 2)
		rotate_ab(stack);
	else
		reverse_ab(stack);
	movement->move_ab--;
}

int				main(int argc, char **argv)
{
	t_stack *stack;

	if (argc == 1)
	{
		ft_putendl("usage: ./push_swap list of numbers [ 1 2 3 ]");
		exit(0);
	}
	else
	{
		argv++;
		argc--;
	}
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (argc == 1)
		argv = split_args(&argc, &argv);
	init_stacks(stack, argc);
	stack = validate_nb(stack, argv, argc);
	ft_sort(stack);
	return (0);
}
