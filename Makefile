CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = game.a
SRC = ./src/game.c ./src/frees.c ./src/listmanager.c ./src/position_helpers.c ./src/displays.c ./src/loaders.c ./src/maps.c ./src/wall.c ./src/exit.c ./src/food.c ./src/players.c ./src/matrix.c ./src/errors.c ./src/checks.c ./src/utilites.c
B_SRC = ./bonus/game_bonus.c ./bonus/frees_bonus.c ./bonus/listmanager_bonus.c ./bonus/position_helpers_bonus.c ./bonus/displays_bonus.c ./bonus/loaders_bonus.c ./bonus/maps_bonus.c ./bonus/wall_bonus.c ./bonus/exit_bonus.c ./bonus/food_bonus.c ./bonus/players_bonus.c ./bonus/matrix_bonus.c ./bonus/errors_bonus.c ./bonus/checks_bonus.c ./bonus/utilites_bonus.c ./bonus/enemy_bonus.c
OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ) $(B_OBJ)

re: clean all

fclean: clean
		rm -f $(NAME)

bonus: $(B_OBJ)
		ar -rcs game.a $(B_OBJ)

c: all clean
		cc ./src/maps.c game.a ./get_next_line/gnl.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o so_long

b: bonus clean
		cc ./bonus/maps_bonus.c game.a ./get_next_line/gnl.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o so_long