NAME		= pushswap.a
APP			= push_swap
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I.

SRC	= $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME) run

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

run: 
	$(CC) -o $(APP) $(NAME)

clean:
	@rm -f *.o

fclean:	clean
	@rm -f $(NAME) $(APP)

re:	fclean all

bonus: all

.PHONY:	all clean fclean re bonus run
