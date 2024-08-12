#include "../../include/minishell.h"

void display_prompt(char **prompt)
{
    char buffer[4096 + 1];
    char *path;
    char *usr;
    char *pc;

    path = getcwd(buffer, 4096);
    usr = getenv("LOGNAME");
    pc = getenv("USER");
    *prompt = ft_strjoin(usr, "@");
    *prompt = ft_strjoin(*prompt, "Femboys");
    *prompt = ft_strjoin(*prompt, ":~");
    *prompt = ft_strjoin(*prompt, path);
    *prompt = ft_strjoin(*prompt, " ");
}
