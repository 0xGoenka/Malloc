# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleclet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 16:28:13 by eleclet           #+#    #+#              #
#    Updated: 2017/07/08 17:05:35 by eleclet          ###   ########.fr        #
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


