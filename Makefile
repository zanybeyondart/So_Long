CC = cc
# CFLAGS = -Wall -Werror -Wextra
NAME = game.a
SRC = main.c frees.c listmanager.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

re: clean all

fclean: clean
		rm -f $(NAME)