#include "../../../include/minishell.h"

void	change_pwd(t_minishell *minishell)
{
	char *pwd;
	char *oldpwd;
	char	cwd[PATH_MAX];

	pwd = get_env_var(minishell, "PWD=");
	oldpwd = get_env_var(minishell, "OLPDPWD=");

	free(minishell->old_pwd);
	minishell->old_pwd = ft_strdup(minishell->pwd);
	free(minishell->pwd);
	getcwd(cwd, sizeof(cwd));
	minishell->pwd = ft_strjoin("PWD=", cwd);
	free(pwd);
	free(oldpwd);
	pwd = ft_strdup(minishell->pwd);
	oldpwd = ft_strdup(minishell->old_pwd);
}
