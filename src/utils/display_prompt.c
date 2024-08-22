#include "../../include/minishell.h"

void display_prompt(char **prompt, t_minishell *minishell)
{
    char buffer[4096 + 1];
    char *path;
    char *usr;
    char *pc;

    path = minishell->pwd;
    usr = getenv("LOGNAME");
    *prompt = ft_strjoin(usr, "@");
    *prompt = ft_strjoin_frees1(*prompt, "Femboys");
    *prompt = ft_strjoin_frees1(*prompt, ":~");
    *prompt = ft_strjoin_frees1(*prompt, path);
    *prompt = ft_strjoin_frees1(*prompt, " ");
}
