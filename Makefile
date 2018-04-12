# **************************************************************************** #
                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleclet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 16:28:13 by eleclet           #+#    #+#              #
#    Updated: 2018/04/12 14:28:53 by eleclet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmalloc.so

CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC = ft_malloc.c 
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	echo "$(NAME) build"
	$(CC) -shared -o $(NAME) $(OBJ)

%.o: %.c 
	gcc -c $(CFLAGS) -fpic $<
clean : 
	rm -rf $(OBJ)
	make -C libft/ clean
fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean
re : fclean all


