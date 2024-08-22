// cd navigation
// issue it update the path even with an error
// need also to fix the env update

#include "../../include/minishell.h"

static void	change_env_pwd(t_minishell *minishell)
{
	int i = 0;
	while (minishell->env[i])
	{
		if (ft_strncmp(minishell->env[i], "PWD=", 4) == 0)
		{
			//free(minishell->env[i]);
			minishell->env[i] = ft_strjoin("PWD=", minishell->pwd);
		}
		else if (ft_strncmp(minishell->env[i], "OLDPWD=", 7) == 0)
		{
			//free(minishell->env[i]);
			minishell->env[i] = ft_strjoin("OLDPWD=", minishell->old_pwd);
		}
		i++;
	}
}

static void	cd_up(t_minishell *minishell)
{
	int i = ft_strlen(minishell->pwd) - 1;

	while (i > 0 && minishell->pwd[i] != '/')
		i--;
	if (i == 0)
		i = 1; // Special case: root directory
	char *new_pwd = ft_substr(minishell->pwd, 0, i);
	if (!new_pwd)
		return;
	free(minishell->pwd);
	minishell->pwd = new_pwd;
}

static void	adjust_path(char *path, t_minishell *minishell)
{
	char **dirs;
	char *new_path;
	int i;

	dirs = ft_split(path, '/');
	if (!dirs)
		return;

	new_path = ft_strdup(minishell->pwd);
	while (dirs[i])
	{
		if (ft_strncmp(dirs[i], "..", 2) == 0)
		{
			// Go up one directory
			cd_up(minishell);
		}
		else if (ft_strncmp(dirs[i], ".", 1) != 0)
		{
			// Add directory to the path
			new_path = ft_strjoin(new_path, "/");
			new_path = ft_strjoin(new_path, dirs[i]);
		}
		i++;
	}
	//free(minishell->pwd);
	minishell->pwd = new_path;

	// Free split array
	i = 0;
	while (dirs[i])
		free(dirs[i++]);
	free(dirs);
}

void	ft_cd(t_command *command, t_minishell *minishell)
{
	int error;
	char *path;

	// Handle special case with no arguments (cd to HOME)
	if (!command->arg[1] || ft_strncmp(command->arg[1], "~", 1) == 0)
	{
		path = minishell->pwd;
		if (!path)
		{
			perror("HOME not set");
			return;
		}
		minishell->pwd = ft_strdup(path);
	}
	else
	{
		path = ft_strdup(command->arg[1]);
		adjust_path(path, minishell);
		free(path);
	}

	error = chdir(minishell->pwd);
	if (error == 0)
	{
		printf("Changed dir to %s\n", minishell->pwd);
		//change_env_pwd(minishell);
	}
	else
	{
		perror("Error changing directory");
	}
}

