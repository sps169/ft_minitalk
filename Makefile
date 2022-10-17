CLIENT_NAME = client
SERVER_NAME = server

CLIENT_SRC_DIR = ./src/client/
SERVER_SRC_DIR = ./src/server/

LIBFT_LIB = ./lib/libftprintf.a

CLIENT_SRC =	$(CLIENT_SRC_DIR)client_main.c		\
				$(CLIENT_SRC_DIR)client_functions.c

SERVER_SRC =	$(SERVER_SRC_DIR)server_main.c

CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)

INCLUDE = -Iinclude

CFLAGS = -Wextra -Wall -Werror

CC = gcc

all: $(CLIENT_NAME) $(SERVER_NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

CSANITIZE = -fsanitize=address -g3

$(CLIENT_NAME): $(LIBFT_LIB) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L./lib/ -lftprintf $(CLIENT_OBJS) -o $(CLIENT_NAME)

$(SERVER_NAME): $(LIBFT_LIB) $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -L./lib/ -lftprintf $(SERVER_OBJS) -o $(SERVER_NAME)

$(LIBFT_LIB):
	make -C lib


clean:
	make -C lib clean
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_OBJS)

fclean: clean
	make -C lib fclean
	rm -f $(CLIENT_NAME)
	rm -f $(SERVER_NAME)

re: fclean all

run: $(CLIENT_NAME) $(SERVER_NAME)
	./$(SERVER_NAME)
	./$(CLIENT_NAME)

rerun: fclean run

norme: 
	norminette -R CheckForbiddenSourcesHeader

.PHONY: all clean fclean re run rerun norme
