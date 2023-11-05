# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvakil <zvakil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/06 14:42:25 by zvakil            #+#    #+#              #
#    Updated: 2023/09/07 05:52:12 by zvakil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf_utils.c ft_prinftf_utils_2.c ft_printf_utils_3.c ft_printf.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
		rm -f $(OBJ) $(OBJ_B)

re: fclean all

fclean: clean
		rm -f $(NAME)