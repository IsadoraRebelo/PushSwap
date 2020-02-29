/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 11:41:43 by ihering-       #+#    #+#                */
/*   Updated: 2020/01/03 10:35:22 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"
# include <limits.h>

typedef struct	s_stack
{
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
	int			checker;
}				t_stack;

typedef struct	s_moves
{
	int			nb;
	int			move_a;
	int			move_b;
	int			move_ab;
	int			rotate_a;
	int			rotate_b;
	int			rotate_ab;
	int			result;
}				t_moves;

t_stack			*validate_nb(t_stack *stack, char **nb, int width);
int				width_count(char **nb);
int				is_sorted(int *stack, int width);
void			init_stacks(t_stack *stack, int width);
int				width_count(char **nb);
int				stack_a(int *stack, int width, int nb, t_moves *rotate);
void			best_move(t_moves *movement, t_stack *stack);

/*
** Define Rotate
*/
int				define_a(int width, int i, t_moves *rotate);
int				define_b(int width, int i, t_moves *rotate);
int				define_ab(t_moves *moves);

/*
** Set Min and Max
*/
int				min_index(int *stack, int width);
int				max_index(int *stack, int width);

/*
** Sorting Functions
*/
void			ft_sort(t_stack *stack);
void			standard_sort(t_stack *stack);
t_moves			*moves(t_stack *stack);

/*
** Swaps Operations
*/
void			swap_a(t_stack *stack);
void			swap_b(t_stack *stack);
void			swap_ab(t_stack *stack);

/*
** Push Operations
*/
void			push_a(t_stack *stack);
void			push_b(t_stack *stack);

/*
** Rotate Operations
*/
void			rotate_a(t_stack *stack);
void			rotate_b(t_stack *stack);
void			rotate_ab(t_stack *stack);

/*
** Reverse Rotate Operations
*/
void			reverse_a(t_stack *stack);
void			reverse_b(t_stack *stack);
void			reverse_ab(t_stack *stack);

#endif
