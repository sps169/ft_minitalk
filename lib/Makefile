# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 17:42:35 by sperez-s          #+#    #+#              #
#    Updated: 2022/10/11 10:16:31 by sperez-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = ./src/

SRC = 	$(SRC_DIR)ft_printf.c				\
		$(SRC_DIR)ft_printf_handler.c		\
		$(SRC_DIR)ft_printf_handler_2.c		\
		$(SRC_DIR)ft_printf_utils.c

OBJS = $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

CFLAGS = -Wextra -Wall -Werror

INCLUDE = -Iinclude

CC = gcc

$(NAME): libft.a $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

libft.a:
	make -C libft
	mv libft/libft.a $(NAME)

all: $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
