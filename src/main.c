#include "../include/minishell.h"

static void get_line(char **line, char *prompt)
{
    *line = readline(prompt);
}

//test
static void get_command(char *line)
{
    int i = 0;
    char *exit = "exit";

    while (line[i])
    {
        if (line[i] == exit[i])
            i++;
        else
            return;
    }
	if (i == ft_strlen(exit))
		exit_shell(false);
}

int main(int ac, char **av, char **env)
{
    char *line;
    char *prompt;
    t_minishell *minishell;

    minishell = (t_minishell *)malloc(sizeof(t_minishell));
    if (!minishell)
        return 1;
    minishell->env = get_env(env);
    while (1)
    {
        display_prompt(&prompt);
        signal(SIGINT,sighandler);
        get_line(&line, prompt);
        free(prompt);
        using_history();
        if (!line)
        {
            free(line);
            continue;
        }
        if(*line)
        {
            add_history(line);
            get_command(line);
			parsing(line);
			//printf("%s\n", line);
        }
    }
    exit_shell(false);
}
