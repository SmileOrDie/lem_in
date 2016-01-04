
NAME=lem-in
VERSION=1.0.5
CFLAGS= -Wall -Werror -Wextra
INCLUDES=-I ./libft/includes
LIBS=-L ./libft -l ft

SRC=	./srcs/main.c \
		./srcs/space_-_split.c \
		./srcs/pars.c \
		./srcs/browse.c \
		./srcs/link_cab.c

OBJ=$(SRC:.c=.o)

all: build $(NAME) finish

build:
	@($(MAKE) -C ./libft)

$(NAME): $(OBJ) ./libft/libft.a
	@gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c lemmin.h ./libft/includes
	@gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))
	@($(MAKE) -C ./libft fclean)

re: fclean all

rego: fclean all
	@./srcs/map.sh

v:
	@(echo "version: $(VERSION)")

finish:
	@(echo "[\033[32m$(NAME)\033[00m]")

.PHONY: all build clean fclean re v

