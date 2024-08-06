#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>

// EXEC
// PARSING
// UTILS
void display_prompt(void);
void    sighandler(int sig);
void exit_shell(bool fail);

#endif