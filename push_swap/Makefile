NAME		= pushswap.a
APP			= push_swap
NAME_B		= checker.a
APP_B		= checker
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I.

SRC	= $(wildcard *.c)
SRC_B = $(wildcard ../bonus/*.c)
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME_B) run_b

all: $(NAME) run

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

$(NAME_B): $(OBJ_B)
	@ar -rcs $(NAME_B) $(OBJ_B)

run_b:
	$(CC) -o $(APP_B) $(NAME_B)

run:
	$(CC) -o $(APP) $(NAME)

clean:
	@rm -f *.o
	@rm -f ../bonus/*.o

fclean:	clean
	@rm -f $(NAME) $(APP)
	@rm -f $(NAME_B) $(APP_B)

re:	fclean all

bonus: all_b

.PHONY:	all clean fclean re bonus run all_b
