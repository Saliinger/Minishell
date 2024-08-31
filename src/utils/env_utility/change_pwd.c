#include "../../../include/minishell.h"

void	change_pwd(t_minishell *minishell)
{
	int		pwd_line;
	int		oldpwd_line;
	char	cwd[PATH_MAX];

	pwd_line = get_env_var(minishell, "PWD=");
	oldpwd_line = get_env_var(minishell, "OLPDPWD=");

	free(minishell->old_pwd);
	minishell->old_pwd = ft_strdup(minishell->pwd);
	free(minishell->pwd);
	getcwd(cwd, sizeof(cwd));
	minishell->pwd = ft_strjoin("PWD=", cwd);
	free(minishell->env[pwd_line]);
	minishell->env[pwd_line] = ft_strdup(minishell->pwd);
	free(minishell->env[oldpwd_line]);
	minishell->env[oldpwd_line] = ft_strdup(minishell->old_pwd);
}
