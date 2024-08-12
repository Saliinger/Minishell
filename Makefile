NAME = minishell
CC = cc
CFLAG = -Wall -Werror -Wextra -g3 #-fsanitize=address
LIBS = -L./libft/compiled -lft -lprintf -lreadline
SRCD = ./src
UTILSD = ./src/utils
PARSD = ./src/parsing
EXED = ./src/exec

SRC = $(wildcard $(SRCD)/*.c) \
	  $(wildcard $(UTILSD)/*.c) \
	  $(wildcard $(PARSD)/*.c) \
	  $(wildcard $(EXED)/*.c)

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re libft

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $(LIBS) -o $(NAME)

libft:
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) -C ./libft clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all
