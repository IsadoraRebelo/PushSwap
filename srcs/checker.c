/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 13:16:28 by ihering-       #+#    #+#                */
/*   Updated: 2020/01/03 11:27:18 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		ft_operations(t_stack *stack, char *op)
{
	if (ft_strequ(op, "sa"))
		swap_a(stack);
	else if (ft_strequ(op, "sb"))
		swap_b(stack);
	else if (ft_strequ(op, "ss"))
		swap_ab(stack);
	else if (ft_strequ(op, "pa"))
		push_a(stack);
	else if (ft_strequ(op, "pb"))
		push_b(stack);
	else if (ft_strequ(op, "ra"))
		rotate_a(stack);
	else if (ft_strequ(op, "rb"))
		rotate_b(stack);
	else if (ft_strequ(op, "rr"))
		rotate_ab(stack);
	else if (ft_strequ(op, "rra"))
		reverse_a(stack);
	else if (ft_strequ(op, "rrb"))
		reverse_b(stack);
	else if (ft_strequ(op, "rrr"))
		reverse_ab(stack);
	else
		return (0);
	return (1);
}

static	void	checker(t_stack *stack)
{
	char *op;

	while (get_next_line(0, &op) > 0)
	{
		if (!op)
			break ;
		if (!(ft_operations(stack, op)))
		{
			ft_putstr("Error\n");
			exit(1);
		}
		free(op);
		op = NULL;
	}
	free(op);
}

char			**split_args(int *argc, char ***argv)
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

int				main(int argc, char **argv)
{
	t_stack *stack;

	if (argc == 1)
	{
		ft_putendl("usage: ./checker list of numbers [ 1 2 3 ]");
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
	stack->checker = 1;
	stack = validate_nb(stack, argv, argc);
	if (!(is_sorted(stack->stack_a, stack->size_a)))
		checker(stack);
	if (is_sorted(stack->stack_a, stack->size_a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
