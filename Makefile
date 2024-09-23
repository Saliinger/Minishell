NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -g3 #-fsanitize=address
LIBS = -L./libft/compiled -lft -lprintf -lreadline
VALGRIND = valgrind --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all

SRCD = ./src
UTILSD = ./src/utils
PARSD = ./src/parsing
EXED = ./src/exec
BINS = ./src/builtins


SRC = $(wildcard $(SRCD)/*.c)				\
	  $(wildcard $(UTILSD)/*.c)				\
	  $(wildcard $(PARSD)/*.c)				\
	  $(wildcard $(EXED)/*.c)				\
	  $(wildcard $(EXED)/old/*.c)			\
	  $(wildcard $(EXED)/t_pids/*.c)		\
	  $(wildcard $(BINS)/*.c)				\
	  $(wildcard $(UTILSD)/env_utility/*.c) \
	  $(wildcard $(UTILSD)/destructors/*.c) \


OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re libft

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

libft:
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) -C ./libft clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all

project_re:
	rm -f $(OBJ)
	rm -f $(NAME)
	clear
	make $(NAME)

test: project_re
	clear
	./$(NAME) || lldb $(NAME)

test_valgrind: project_re
	clear
	$(VALGRIND) $(NAME)

