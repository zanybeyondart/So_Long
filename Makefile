CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = game.a
SRC = ./src/game.c ./src/frees.c ./src/listmanager.c ./src/position_helpers.c ./src/displays.c ./src/loaders.c ./src/maps.c ./src/wall.c ./src/exit.c ./src/food.c ./src/players.c ./src/matrix.c ./src/errors.c ./src/checks.c ./src/utilites.c
B_SRC = ./bonus/game_bonus.c\
./bonus/utilites/frees_bonus.c\
./bonus/utilites/frees_2_bonus.c\
./bonus/position_helpers_bonus.c\
./bonus/displays_bonus.c\
./bonus/loaders_bonus.c\
./bonus/maps/maps_bonus.c\
./bonus/maps/map_checks.c\
./bonus/wall_bonus.c\
./bonus/exit/exit_bonus.c\
./bonus/exit/exit_init_bonus.c\
./bonus/exit/exit_rend_bonus.c\
./bonus/food_bonus.c\
./bonus/player/player_bonus.c\
./bonus/player/player_init_bonus.c\
./bonus/player/player_texture_loader_bonus.c\
./bonus/matrix_bonus.c\
./bonus/errors_bonus.c\
./bonus/checks_bonus.c\
./bonus/utilites/utilites_bonus.c\
./bonus/enemy/enemy_bonus.c\
./bonus/enemy/enemy_init_bonus.c\
./bonus/enemy/enemy_texture_load_bonus.c\
./bonus/enemy/enemy_rend_bonus.c\
./bonus/power/power_bonus.c\
./bonus/power/kill_init_bonus.c\
./bonus/power/kill_rend_bonus.c\
./bonus/power/power_rend_bonus.c\
./bonus/power/power_init_bonus.c\
./bonus/start_window_bonus.c\
./bonus/game_screen/game_screen_bonus.c\

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

b: fclean bonus
		cc ./bonus/maps/maps_bonus.c game.a ./get_next_line/gnl.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o so_long