CLIENT_NAME = client
SERVER_NAME = server

CLIENT_NAME_BONUS = b_client
SERVER_NAME_BONUS = b_server

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

$(CLIENT_NAME_BONUS): 
	make -C bonus client
	cp bonus/$(CLIENT_NAME_BONUS) .
	rm bonus/$(CLIENT_NAME_BONUS)

$(SERVER_NAME_BONUS):
	make -C bonus server
	cp bonus/$(SERVER_NAME_BONUS) .
	rm bonus/$(SERVER_NAME_BONUS)

bonus: $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

clean:
	make -C lib clean
	make -C bonus clean
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_OBJS)

fclean: clean
	make -C lib fclean
	make -C bonus fclean
	rm -f $(CLIENT_NAME)
	rm -f $(SERVER_NAME)
	rm -f $(CLIENT_NAME_BONUS)
	rm -f $(SERVER_NAME_BONUS)

re: fclean all

norme: 
	norminette -R CheckForbiddenSourcesHeader

.PHONY: all clean fclean re norme
