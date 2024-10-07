#ifndef BUILTINS_H
# define BUILTINS_H

# include "imports.h"
# include "structure.h"

// Builtins
void					ft_pwd(t_minishell *minishell);
void					ft_env(t_minishell *minishell);
void					ft_echo(t_minishell *minishell, t_command *command);
void					ft_cd(t_command *command, t_minishell *minishell);
void					ft_export(t_command *command, t_minishell *minishell);
void					ft_unset(t_command *command, t_minishell *minishell);
void					ft_heredoc(t_command *command, t_minishell *minishell);
void					exit_shell(t_minishell *minishell, t_command *command, bool fail);
void					ft_expand(t_command *command, t_minishell *minishell);

#endif
