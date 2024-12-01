NAME 		=	minishell
CC = cc
CFLAGS_MAC = -Wall -Wextra -g3 -I/opt/homebrew/opt/readline/include -fsanitize=address
LIBS_MAC = -L/opt/homebrew/opt/readline/lib -lreadline -L./libft/compiled -lft -lprintf
CFLAGS = -Wall -Wextra -g3
LIBS = -lreadline -L./libft/compiled -lft -lprintf
LIBFT_A		=	libft/libft/libft.a
PRINTF_A	=	libft/printf/libprintf.a
VALGRIND = valgrind --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all \
--gen-suppressions=yes --suppressions="./.valgrind.supp"

GREEN = \033[0;32m
RESET = \033[0m

SRCD = ./src
UTILSD = ./src/utils
PARSD = ./src/parsing
SIGD = ./src/signals
EXED = ./src/exec
BINS = ./src/builtins

SRC =	$(wildcard $(SRCD)/*.c)				\
		$(wildcard $(UTILSD)/*.c)			\
		$(wildcard $(UTILSD)/*/*.c)			\
		$(wildcard $(PARSD)/*.c)			\
		$(wildcard $(SIGD)/*.c)				\
		$(wildcard $(EXED)/*.c)				\
		$(wildcard $(EXED)/*/*.c)			\
    	$(wildcard $(EXED)/*/*/*.c)	   		\
		$(wildcard $(BINS)/*.c)				\
		$(wildcard $(BINS)/*/*.c)			\

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re libft

all: $(LIBFT_A) $(PRINTF_A) $(NAME)


$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ)  -o $(NAME) $(LIBS)
	@echo "$(CC) $(CFLAGS) \$$(OBJ)  -o $(NAME) $(LIBS)"
	@echo "\n$(GREEN)\t$(NAME) compiled successfully$(RESET)\n"

$(LIBFT_A):
	echo "test"
	@$(MAKE) all -C ./libft

$(PRINTF_A):
	echo "test2"
	@$(MAKE) all -C ./libft

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
	make $(NAME) -j

exec_re: 
	rm -f $(EXED)/*.o
	rm -f $(EXED)/*/*.o
	rm -f $(EXED)/*/*/*.o
	rm -f $(EXED)/*/*/*/*.o
	rm -f $(NAME)
	clear
	make $(NAME) -j

utils_re:
	rm -f $(UTILSD)/*.o
	rm -f $(UTILSD)/*/*.o
	rm -f $(NAME)
	clear
	make $(NAME) -j

parsing_re:
	rm -f $(PARSD)/*.o
	rm -f $(NAME)
	clear
	make $(NAME) -j

builtins_re:
	rm -f $(BINS)/*/*.o
	rm -f $(NAME)
	clear
	make $(NAME) -j

test: project_re
	clear
	./$(NAME) || lldb $(NAME)

lldb:
	lldb $(NAME)

valgrind:
	clear
	$(VALGRIND) ./$(NAME)
