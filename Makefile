# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ihering- <ihering-@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/16 10:20:01 by ihering-       #+#    #+#                 #
#    Updated: 2020/01/03 10:59:24 by ihering-      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC1 = push_swap push_p reverse_rr rotate_r swap_s validating stack_management \
		sorting standard_sort moves min_max rotates
SRC2 = checker push_p reverse_rr rotate_r stack_management swap_s validating
SRCF1 = $(SRC1:%=srcs/%.c)
SRCF2 = $(SRC2:%=srcs/%.c)
OBJ1 = $(SRC1:%=%.o)
OBJ2 = $(SRC2:%=%.o)
NAME1 = push_swap
NAME2 = checker
LIBFT = -I libft/includes -L libft -lft
FLAGS = -Wall -Werror -Wextra

MAKECOLOUR = \033[38;5;208m
CLEANCOLOUR = \033[38;5;229m
FCLEANCOLOUR = \033[38;5;214m
LIBCOLOUR = \033[38;5;220m
RESETCOLOUR = \033[0m

.PHONY: all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1): $(SRCF1)
	@echo "$(LIBCOLOUR)Compiling Libraries$(RESETCOLOUR)"
	@make -C libft/
	@echo "$(MAKECOLOUR)Compiling push_swap$(RESETCOLOUR)"
	@clang -g $(FLAGS) -I libft/includes -c $(SRCF1)
	@clang -o $(NAME1) $(OBJ1) $(LIBFT)

$(NAME2): $(SRCF2)
	@echo "$(MAKECOLOUR)Compiling checker$(RESETCOLOUR)"
	@clang -g $(FLAGS) -I libft/includes -c $(SRCF2)
	@clang -o $(NAME2) $(OBJ2) $(LIBFT)

clean:
	@echo "$(CLEANCOLOUR)Cleaning Libraries$(RESETCOLOUR)"
	@make -C libft/ clean
	@rm -f $(OBJ1) $(OBJ2)

fclean: clean
	@echo "$(FCLEANCOLOUR)Removing $(NAME1) & $(NAME2) $(RESETCOLOUR)"
	@make -C libft/ fclean
	@rm -f $(NAME1)
	@rm -f $(NAME2)

re: fclean all
