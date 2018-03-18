# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/31 16:14:13 by ygarrot           #+#    #+#              #
#    Updated: 2018/01/10 15:43:56 by ygarrot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

INCLUDES = includes/

FLAGS =  -Wall -Werror -Wextra 

SRC = chooseconv.c convuimax.c convs.c ft_printf.c parser.c\
	  parsecolor.c printp.c print_nchar.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@libtool -static -o $@ $^
		@ranlib $@
$(LIBFT):
	@make -C libft

%.o:%.c
	@gcc -o $@ $(FLAGS) -c $< -I $(INCLUDES)

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all, clean, fclean, re
