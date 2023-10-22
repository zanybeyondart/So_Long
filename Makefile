NAME = so_long
OBJ_DIR = ./obj
SRCS_DIR = ./src
SRCS = game.c frees.c listmanager.c position_helpers.c displays.c loaders.c maps.c wall.c exit.c food.c players.c matrix.c errors.c checks.c
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
$(shell mkdir -p $(OBJ_DIR))

CC = cc
FLAGS = -Wall -Wextra -Werror
START = cd mlx && make

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

all: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJ)
	@$(START)
	@$(CPRINT)
	@$(CC) ./get_next_line/gnl.a $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)
	make -C mlx clean

fclean:
	rm -rf $(NAME) $(OBJ)
	make -C mlx clean

re: fclean all

.PHONY: clean fclean all re
