CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = ./src/game.c\
./src/frees.c\
./src/listmanager.c\
./src/position_helpers.c\
./src/displays.c\
./src/loaders.c\
./src/maps.c\
./src/wall.c\
./src/exit.c\
./src/food.c\
./src/players.c\
./src/matrix.c\
./src/errors.c\
./src/checks.c\
./src/utilites.c\

B_SRC = ./bonus/game_bonus.c\
./bonus/utilites/frees_bonus.c\
./bonus/utilites/frees_2_bonus.c\
./bonus/utilites/restart_bonus.c\
./bonus/position_helpers_bonus.c\
./bonus/displays_bonus.c\
./bonus/loaders_bonus.c\
./bonus/maps/maps_bonus.c\
./bonus/maps/map_checks_bonus.c\
./bonus/wall_bonus.c\
./bonus/exit/exit_bonus.c\
./bonus/exit/exit_init_bonus.c\
./bonus/exit/exit_rend_bonus.c\
./bonus/food_bonus.c\
./bonus/player/player_bonus.c\
./bonus/player/player_init_bonus.c\
./bonus/player/player_texture_loader_bonus.c\
./bonus/player/player_rend_bonus.c\
./bonus/player/player_death_bonus.c\
./bonus/player/player_win_bonus.c\
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
./bonus/game_screen/game_screen_bonus.c\
./bonus/game_screen/moves_bonus.c\
./bonus/start_screen/start_screen_bonus.c\
./bonus/start_screen/start_screen_textures_bonus.c\
./bonus/start_screen/start_screen_rend_bonus.c\
./bonus/pause_screen/pause_screen_bonus.c\
./bonus/pause_screen/pause_screen_textures_bonus.c\
./bonus/pause_screen/pause_screen_rend_bonus.c\
./bonus/end_win_screen/end_win_screen_bonus.c\
./bonus/end_win_screen/end_win_screen_textures_bonus.c\
./bonus/end_win_screen/end_win_screen_rend_bonus.c\
./bonus/end_lose_screen/end_lose_screen_bonus.c\
./bonus/end_lose_screen/end_lose_screen_textures_bonus.c\
./bonus/end_lose_screen/end_lose_screen_rend_bonus.c\
./bonus/easteregg_screen/easteregg_screen_bonus.c\
./bonus/easteregg_screen/easteregg_screen_textures_bonus.c\
./bonus/easteregg_screen/easteregg_screen_rend_bonus.c\
./bonus/easteregg_screen/easteregg_text_bonus.c\




NAME = so_long
LIB = so_long.a
OBJ = $(SRC:.c=.o)

all: $(LIB)
	cd mlx && make
	cd get_next_line && make
	cd printf && make
	@$(CC) $(CFLAGS) ./src/maps.c $(LIB) ./get_next_line/gnl.a ./printf/libftprintf.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIB): $(OBJ)
	@ar -rcs $(LIB) $(OBJ)




B_NAME = so_long_bonus
B_LIB = so_long_bonus.a
B_OBJ = $(B_SRC:.c=.o)

bonus: $(B_LIB)
	cd mlx && make
	cd get_next_line && make
	cd printf && make
	@$(CC) $(CFLAGS) ./bonus/maps/maps_bonus.c $(B_LIB) ./get_next_line/gnl.a ./printf/libftprintf.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(B_NAME)

$(B_LIB): $(B_OBJ)
	@ar -rcs $(B_LIB) $(B_OBJ)




clean:
		rm -f $(OBJ) $(B_OBJ)

re: fclean all

fclean: clean
	rm -f $(NAME) $(B_NAME) $(LIB) $(B_LIB)
	make -C mlx clean
	make -C get_next_line fclean
	make -C printf fclean