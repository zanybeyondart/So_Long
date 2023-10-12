CC = cc
# CFLAGS = -Wall -Werror -Wextra
NAME = game.a
SRC = game.c frees.c listmanager.c position_helpers.c displays.c loaders.c maps.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

re: clean all

fclean: clean
		rm -f $(NAME)

c: all clean
		cc maps.c game.a ./get_next_line/gnl.a -Lmlx -lmlx -framework OpenGL -framework AppKit
		# ./a.out