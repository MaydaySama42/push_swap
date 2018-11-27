# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdalil <mdalil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 13:54:48 by mdalil            #+#    #+#              #
#    Updated: 2018/11/19 06:48:54 by mdalil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER		=	checker
NAME_PUSH_SWAP		=	push_swap
NAME_GENERATOR		=	generator

CFLAGS				=	-Wall -Wextra -Werror #-g3 -fsanitize=address

INCLUDE_LIBFT		=	../libft/includes
INCLUDE				=	./includes/

SRC_CHECKER_FILE	=	checker.c\
						interpret.c
SRC_CHECKER_PATH	=	./srcs/checker/

SRC_ERROR_FILE		=	error.c
SRC_ERROR_PATH		=	./srcs/error/

SRC_GENERATOR_FILE	=	gen_method.c\
						generator.c\
						parse_args.c
SRC_GENERATOR_PATH	=	./srcs/generator/

SRC_PARSING_FILE	=	parsing.c
SRC_PARSING_PATH	=	./srcs/parsing/

SRC_PUSH_SWAP_FILE	=	push_swap.c
SRC_PUSH_SWAP_PATH	=	./srcs/push_swap/

SRC_SORTING_FILE	=	insertion_sort.c\
						list_utils.c\
						list.c\
						push.c\
						rotate_reverse.c\
						rotate.c\
						selection_sort.c\
						sort_utils.c\
						swap.c
SRC_SORTING_PATH	=	./srcs/sorting/


SRC_CHECKER			= $(addprefix $(SRC_CHECKER_PATH),$(SRC_CHECKER_FILE))
SRC_ERROR			= $(addprefix $(SRC_ERROR_PATH),$(SRC_ERROR_FILE))
SRC_GENERATOR		= $(addprefix $(SRC_GENERATOR_PATH),$(SRC_GENERATOR_FILE))
SRC_PARSING			= $(addprefix $(SRC_PARSING_PATH),$(SRC_PARSING_FILE))
SRC_PUSH_SWAP		= $(addprefix $(SRC_PUSH_SWAP_PATH),$(SRC_PUSH_SWAP_FILE))
SRC_SORTING			= $(addprefix $(SRC_SORTING_PATH),$(SRC_SORTING_FILE))

SRC_PUSH_SWAP += $(SRC_ERROR)
SRC_PUSH_SWAP += $(SRC_PARSING)
SRC_PUSH_SWAP += $(SRC_SORTING)

SRC_CHECKER += $(SRC_ERROR)
SRC_CHECKER += $(SRC_PARSING)
SRC_CHECKER += $(SRC_SORTING)

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
OBJ_GENERATOR = $(SRC_GENERATOR:.c=.o)

OBJ = $(OBJ_PUSH_SWAP)
OBJ += $(OBJ_CHECKER)

all: $(NAME_PUSH_SWAP) $(NAME_CHECKER)

$(NAME_PUSH_SWAP): $(OBJ_PUSH_SWAP)
	@make -C ../libft
	@clang $(CFLAGS) $(OBJ_PUSH_SWAP) -o $(NAME_PUSH_SWAP) -L../libft -lft

$(NAME_CHECKER): $(OBJ_CHECKER)
	@make -C ../libft
	@clang $(CFLAGS) $(OBJ_CHECKER) -o $(NAME_CHECKER) -L../libft -lft

$(NAME_GENERATOR): $(OBJ_GENERATOR)
	@make -C ../libft
	@clang $(CFLAGS) $(OBJ_GENERATOR) -o $(NAME_GENERATOR) -L../libft -lft

%.o : %.c
	@clang $(CFLAGS) -I $(INCLUDE_LIBFT) -I $(INCLUDE) -c $< -o $@

clean:
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf $(OBJ_GENERATOR)
	@make -C ../libft clean

fclean: clean
	@/bin/rm -rf $(NAME_PUSH_SWAP)
	@/bin/rm -rf $(NAME_CHECKER)
	@/bin/rm -rf $(NAME_GENERATOR)
	@make -C ../libft fclean

re: fclean all
