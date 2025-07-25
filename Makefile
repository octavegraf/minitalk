CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g
CLIENT			=	client
SERVER			=	server
HEADER			=	minitalk.h
LIBFT_FOLDER	=	libft/
LIBFT_LIB		=	$(LIBFT_FOLDER)libft.a
LIBS			=	$(LIBFT_LIB)
OBJ				=	minitalk__$(SERVER).o minitalk__$(CLIENT).o 

all				:	$(CLIENT) $(SERVER)

submodules		:
	@git submodule update --init --recursive
	@$(MAKE) -C $(LIBFT_FOLDER)

$(CLIENT)		:	minitalk__$(CLIENT).o $(LIBS)
	$(CC) minitalk__$(CLIENT).o $(LIBS) -o $(CLIENT)

$(SERVER)		:	minitalk__$(SERVER).o $(LIBS)
	$(CC) minitalk__$(SERVER).o $(LIBS) -o $(SERVER)

$(LIBS)			:	submodules

%.o				:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean			:
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_FOLDER) clean

fclean			:	clean
	@rm -f $(CLIENT) $(SERVER) $(LIBFT_LIB)

re				:	fclean all


.PHONY: all clean fclean re submodules