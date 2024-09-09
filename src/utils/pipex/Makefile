AR = libft/libft.a
NAME = pipex
NAME_BONUS = pipex_bonus
RUBBISH =	out.valgrind	\
			out_1.t	\
			out_1.m	\
			out_2.t \
			out_2.m \
			out_3.t \
			out_3.m \
			out_4.t	\
			out_4.m \
			out_5.t \
			out_5.m \
			out_6.t \
			out_6.m \
			out_7.t \
			out_7.m \
			out_8.t \
			out_8.m \
			out_9.t \
			out_9.m \
			out_10.t \
			out_10.m \
			out_11.t \
			out_11.m \
			out_12.t \
			out_12.m \

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address #-D VERBOSE=100

SRCS = 	src/main.c	\
		\
		src/ft_init_p.c			\
		src/ft_pipex.c			\
		src/ft_exec_command.c	\
		src/ft_parent_waits.c	\
		src/ft_custom_split.c	\
		\
		src/ft_open_fds_io.c	\
		src/ft_close_fds_io.c	\
		\
		src/ft_close_fd.c		\
		src/ft_free_args.c		\
		src/ft_free_paths.c		\
		src/ft_free_tab.c		\
		\
		src/ft_error.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS =	src_bonus/main_bonus.c	\
				\
				src/ft_init_p.c			\
				src/ft_pipex.c			\
				src/ft_exec_command.c	\
				src/ft_parent_waits.c	\
				src/ft_custom_split.c	\
				\
				src/ft_open_fds_io.c	\
				src/ft_close_fds_io.c	\
				\
				src/ft_close_fd.c		\
				src/ft_free_args.c		\
				src/ft_free_paths.c		\
				src/ft_free_tab.c		\
				\
				src/ft_error.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

VALGRIND = valgrind --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS) $(AR)
	$(CC) $(OBJS_BONUS) $(CFLAGS) -o $(NAME_BONUS) $(AR)

$(AR) :
	make all -C ./libft

$(NAME): $(OBJS) $(AR)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(AR)
	

valgrind : project_re
	clear
	$(VALGRIND) ./pipex Makefile ls "cat -e" out.valgrind

tests : project_re
	clear
	@touch inp_OK inp_IL out_IL
	@cat Makefile > inp_OK
	@cat Makefile > inp_IL

	@chmod 000 inp_IL
	@chmod 000 out_IL

	make tests_input_UN
	@echo "##############################################################################"
	@echo "##############################################################################"
	make tests_input_IL
	@echo "##############################################################################"
	@echo "##############################################################################"
	make tests_input_OK

	@chmod 777 inp_IL
	@chmod 777 out_IL
	@rm -f inp_IL out_IL inp_OK
	
tests_input_OK : 
	@echo "\t\t\t\ttests ipunt_OK :"
	@echo "________________________________________________________"
	< inp_OK ls | cat > out_1.t && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_OK ls cat out_1.m && echo "success $$?\n\n" || echo "failure $$?\n\n"
	@echo "________________________________________________________"
	< inp_OK ls | cat > out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_OK ls cat out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"

	@echo "\t\t\t\tcmd2_KO"
	@echo "________________________________________________________"
	< inp_OK ls | cmd2_KO > out_2.t && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_OK ls cmd2_KO out_2.m && echo "success $$?\n\n" || echo "failure $$?\n\n"
	@echo "________________________________________________________"
	< inp_OK ls | cmd2_KO > out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_OK ls cmd2_KO out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"

	@echo "\t\t\t\tcmd1_KO"
	@echo "________________________________________________________"
	< inp_OK cmd1_KO | cat > out_3.t && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_OK cmd1_KO cat out_3.m && echo "success $$?\n\n" || echo "failure $$?\n\n"
	@echo "________________________________________________________"
	< inp_OK cmd1_KO | cat > out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_OK cmd1_KO cat out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"

	@echo "\t\t\t\tcmd1_KO ++ cmd2_KO"
	@echo "________________________________________________________"
	< inp_OK cmd1_KO | cmd2_KO > out_4.t && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_OK cmd1_KO cmd2_KO out_4.m && echo "success $$?\n\n" || echo "failure $$?\n\n"
	@echo "________________________________________________________"
	< inp_OK cmd1_KO | cmd2_KO > out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_OK cmd1_KO cmd2_KO out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"

tests_input_IL : 
	@echo  "\t\t\t\ttests ipunt_IL :"
	@echo "________________________________________________________"
	< inp_IL ls | cat > out_5.t && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_IL ls cat out_5.m && echo "success $$?\n\n" || echo "failure $$?\n\n"
	@echo "________________________________________________________"
	< inp_IL ls | cat > out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_IL ls cat out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"

	@echo "\t\t\t\tcmd2_KO"
	@echo "________________________________________________________"
	< inp_IL ls | cmd2_KO > out_6.t && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_IL ls cmd2_KO out_6.m && echo "success $$?\n\n" || echo "failure $$?\n\n"
	@echo "________________________________________________________"
	< inp_IL ls | cmd2_KO > out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_IL ls cmd2_KO out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"

	@echo "\t\t\t\tcmd1_KO"
	@echo "________________________________________________________"
	< inp_IL cmd1_KO | cat > out_7.t && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_IL cmd1_KO cat out_7.m && echo "success $$?\n\n" || echo "failure $$?\n\n"
	@echo "________________________________________________________"
	< inp_IL cmd1_KO | cat > out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_IL cmd1_KO cat out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"

	@echo "\t\t\t\tcmd1_KO ++ cmd2_KO"
	@echo "________________________________________________________"
	< inp_IL cmd1_KO | cmd2_KO > out_8.t && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_IL cmd1_KO cmd2_KO out_8.m && echo "success $$?\n\n" || echo "failure $$?\n\n"
	@echo "________________________________________________________"
	< inp_IL cmd1_KO | cmd2_KO > out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_IL cmd1_KO cmd2_KO out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"

tests_input_UN :
	@echo  "\t\t\t\ttests ipunt_UN :"
	@echo "________________________________________________________"
	< inp_UN ls | cat > out_9.t && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_UN ls cat out_9.m && echo "success $$?\n\n" || echo "failure $$?\n\n"
	@echo "________________________________________________________"
	< inp_UN ls | cat > out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_UN ls cat out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"

	@echo "\t\t\t\tcmd2_KO"
	@echo "________________________________________________________"
	< inp_UN ls | cmd2_KO > out_10.t && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_UN ls cmd2_KO out_10.m && echo "success $$?\n\n" || echo "failure $$?\n\n"
	@echo "________________________________________________________"
	< inp_UN ls | cmd2_KO > out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_UN ls cmd2_KO out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"

	@echo "\t\t\t\tcmd1_KO"
	@echo "________________________________________________________"
	< inp_UN cmd1_KO | cat > out_11.t && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_UN cmd1_KO cat out_11.m && echo "success $$?\n\n" || echo "failure $$?\n\n"
	@echo "________________________________________________________"
	< inp_UN cmd1_KO | cat > out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_UN cmd1_KO cat out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"

	@echo "\t\t\t\tcmd1_KO ++ cmd2_KO"
	@echo "________________________________________________________"
	< inp_UN cmd1_KO | cmd2_KO > out_12.t && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_UN cmd1_KO cmd2_KO out_12.m && echo "success $$?\n\n" || echo "failure $$?\n\n"
	@echo "________________________________________________________"
	< inp_UN cmd1_KO | cmd2_KO > out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"
	./pipex inp_UN cmd1_KO cmd2_KO out_IL && echo "success $$?\n\n" || echo "failure $$?\n\n"

clean:
	make clean -C ./libft
	rm -rf $(RUBBISH)
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

project_re:
	rm -rf $(OBJS)
	rm -rf $(NAME)
	make all

re: fclean all

.PHONY: all clean fclean re valgrind project_re lldb
