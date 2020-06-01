# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-der <rvan-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/29 00:37:35 by rvan-der          #+#    #+#              #
#    Updated: 2020/06/01 03:18:46 by rvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = btsp
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC = 	main.c \
		read_armies.c \
		utils.c \
		cleaning.c

OBJ = $(SRC:.c=.o)

.SUFFIXES:

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	$(CC) $(CFLAG) -I libft -c $(SRC)
	$(CC) $(OBJ) -Llibft -lft -o $(NAME)

vm:
	$(CC) $(CFLAG) battlespace.c -o battlespace

clean:
	make -C libft clean
	rm -f $(OBJ)
	rm -f battlespace.o

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	rm -f libft/libft.a
	rm -f battlespace

re: fclean all