# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 17:58:29 by abartole          #+#    #+#              #
#    Updated: 2019/12/11 21:20:57 by abartole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

SRCS_DIR=sources
OBJS_DIR=objects

LIBFT_DIR=libft

INCLUDES = -I . -I $(LIBFT_DIR)

SOURCES=\
	check_format.c\
	conversion1.c\
	flags.c\
	for_help1.c\
	ft_big_pow.c\
	integral_part.c\
	number.c\
	check_format1.c\
	double.c\
	flags_for_int.c\
	for_help2.c\
	ft_printf.c\
	lets_work.c\
	unordinary_flags.c\
	conversion.c\
	double_main.c\
	for_help.c\
	fractional_part.c\
	int_flags.c\
	norme.c\
	work_with_bits.c\
	get_args.c\
	print_str.c\
	norm.c\

SRCS=$(addprefix $(SRCS_DIR)/, $(SOURCES))

OBJECTS=$(SOURCES:.c=.o)
OBJS=$(addprefix $(OBJS_DIR)/, $(OBJECTS))

LIBFT_A=$(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS_DIR) $(OBJS)
	@echo "Making ft_printf..."
	@cp libft/libft.a ./$(NAME)
	@ar rc $@ $(OBJS)
	@ranlib $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT_DIR)
	
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(CC) $(INCLUDES) $(FLAGS) -o $@ -c $<

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

re: fclean all
