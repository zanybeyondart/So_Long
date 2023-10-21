CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = game.a
SRC = ./src/game.c ./src/frees.c ./src/listmanager.c ./src/position_helpers.c ./src/displays.c ./src/loaders.c ./src/maps.c ./src/wall.c ./src/exit.c ./src/food.c ./src/players.c ./src/matrix.c ./src/errors.c ./src/checks.c
BONUS = ./bonus/game.c ./bonus/frees.c ./bonus/listmanager.c ./bonus/position_helpers.c ./bonus/displays.c ./bonus/loaders.c ./bonus/maps.c ./bonus/wall.c ./bonus/exit.c ./bonus/food.c ./bonus/players.c ./bonus/matrix.c ./bonus/errors.c ./bonus/checks.c
OBJ = $(SRC:.c=.o)
B_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)

bonus: $(NAME)

$(NAME): $(B_OBJ)
		ar -rcs $(NAME) $(B_OBJ)

clean:
		rm -f $(OBJ)

b_clean:
		rm -f $(B_OBJ)

re: clean all

fclean: clean
		rm -f $(NAME)

c: all clean
		cc ./src/maps.c game.a ./get_next_line/gnl.a -Lmlx -lmlx -framework OpenGL -framework AppKit
		# ./a.out

bc: bonus b_clean
		cc ./src/maps.c game.a ./get_next_line/gnl.a -Lmlx -lmlx -framework OpenGL -framework AppKit
		# ./a.out

