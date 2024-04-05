CLIENT	= client

SERVER = server

CFLAGS = -g -Wall -Werror -Wextra

OBJS	= $(SRCS:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT) :
	cc $(CFLAGS) client.c ft_atoi.c ft_isdigit.c ft_putnbr_fd.c ft_putchar_fd.c -o $(CLIENT)

$(SERVER) :
	cc $(CFLAGS) server.c ft_atoi.c ft_isdigit.c ft_putnbr_fd.c ft_putchar_fd.c -o $(SERVER)

.PHONY: all clean fclean re

clean:
	rm -f $(CLIENT) $(SERVER)

re: fclean all