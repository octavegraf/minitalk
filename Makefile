CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g
CLIENT			=	client
SERVER			=	server
HEADER			=	minitalk.h
LIBFT_FOLDER	=	libft/
LIBFT_LIB		=	$(LIBFT_FOLDER)libft.a
LIBS			=	$(LIBFT_LIB)
OBJ				=	minitalk__$(SERVER).o minitalk__$(CLIENT).o 

all				:	submodules client server

submodules		:
	@git submodule update --init --recursive
	@$(MAKE) -C $(LIBFT_FOLDER)

client			:	minitalk__$(CLIENT).o
	$(CC) minitalk__$(CLIENT).o $(LIBS) -o $(CLIENT)

server			:	minitalk__$(SERVER).o
	$(CC) minitalk__$(SERVER).o $(LIBS) -o $(SERVER)

%.o				:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean			:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_FOLDER) clean

fclean			:	clean
	@rm -f $(CLIENT) $(SERVER) $(LIBFT_LIB)

re				:	fclean all


.PHONY: all clean fclean re submodules client server