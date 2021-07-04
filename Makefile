CC	= gcc
FLAGS = -Werror -Wextra -Wall
RM = rm -f
NAME = compile
LIBRARY = lib

client:
	$(CC) -g $(FLAGS) client.c -o client -Llibft/ -lft -Ilibft/

server:
	$(CC) -g $(FLAGS) server.c -o server -Llibft/ -lft -Ilibft/

$(NAME): $(LIBRARY)
	make client server

all: $(NAME)

clean:
	find . ! \( -name "*.c" -o -name "Makefile" -o -name "libft" -o -name "*.h" \)  -delete

re: clean all

$(LIBRARY):
	make -C ./libft

