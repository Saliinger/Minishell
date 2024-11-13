NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -g3 #-fsanitize=address
LIBS = -L./libft/compiled -lft -lprintf -lreadline
VALGRIND = valgrind --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all \
--gen-suppressions=yes --suppressions="./.valgrind.supp"

SRCD = ./src
UTILSD = ./src/utils
PARSD = ./src/parsing
SIGD = ./src/signals
EXED = ./src/exec
BINS = ./src/builtins

SRC = $(wildcard $(SRCD)/*.c)				\
	  $(wildcard $(UTILSD)/*.c)				\
	  $(wildcard $(PARSD)/*.c)				\
	  $(wildcard $(SIGD)/*.c)				\
	  $(wildcard $(SIGD)/old/*.c)			\
	  $(wildcard $(EXED)/*.c)				\
	  $(wildcard $(EXED)/*/*.c)			    \
      $(wildcard $(EXED)/*/*/*.c)	   		\
	  $(wildcard $(BINS)/*.c)				\
	  $(wildcard $(UTILSD)/env_utility/*.c) \
	  $(wildcard $(UTILSD)/destructors/*.c) \


OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re libft

all: libft $(NAME)

$(NAME): $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "\n$(CC) $(CFLAGS) \$$(OBJ) $(LIBS) -o $(NAME)\n"

libft:
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) -C ./libft clean
	rm -f $(OBJ)
	clear

fclean: clean
	@$(MAKE) -C ./libft fclean
	rm -f $(NAME)
	clear

re: fclean all

project_re:
	rm -f $(OBJ)
	rm -f $(NAME)
	clear
	make $(NAME)

exec_re: 
	rm -f $(EXED)/*.o
	rm -f $(EXED)/*/*.o
	rm -f $(EXED)/*/*/*.o
	rm -f $(EXED)/*/*/*/*.o
	rm -f $(NAME)
	clear
	make $(NAME)

test: project_re
	clear
	./$(NAME) || lldb $(NAME)

lldb:
	lldb $(NAME)

valgrind:
	clear
	$(VALGRIND) ./$(NAME)
