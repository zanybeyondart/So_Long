CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = gnl.a
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

re: clean all

fclean: clean
		rm -f $(NAME)
