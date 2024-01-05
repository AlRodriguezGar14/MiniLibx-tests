CC = cc
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
CFLAGS = -fsanitize=address -g3

NAME = minilibfx.out
CFILES = main.c
LIBRARY = libmlx.a

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(CFILES) $(LIBRARY) -framework OPENGL -framework AppKit -o $(NAME)

run: $(NAME)
	./$(NAME)

fclean:
	rm -rf $(NAME)

re: fclean $(NAME) run

