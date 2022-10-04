CLIENT	= client
SERVER	= server
FT_PRINTF	= libftprintf.a
FT_PRINTF_PATH	= ./ft_printf/
CLIENT_SRCS	= client.c
SERVER_SRCS = server.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJS)
	make -C $(FT_PRINTF_PATH)
	cp $(FT_PRINTF_PATH)$(FT_PRINTF) .
	$(CC) $(CFLAGS) $(FT_PRINTF) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT) : $(CLIENT_OBJS)
	cp $(FT_PRINTF_PATH)$(FT_PRINTF) .
	$(CC) $(CFLAGS) $(FT_PRINTF) $(CLIENT_OBJS) -o $(CLIENT)

clean :
	make clean -C $(FT_PRINTF_PATH)
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(FT_PRINTF)

fclean : clean
	make fclean -C $(FT_PRINTF_PATH)
	rm -f $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all clean fclean re
