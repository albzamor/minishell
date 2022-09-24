/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_evaluate_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:28:58 by albzamor          #+#    #+#             */
/*   Updated: 2022/09/22 22:01:59 by antonmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_new_line(t_shell *shell)
{
	g_interactive = 1;
	if (errno == 130)
		printf("\33[2K\r");
	if (shell->sig_int_line && *shell->sig_int_line)
	{
		shell->line = ft_strdup(shell->sig_int_line);
		new_free(&shell->sig_int_line);
	}
	else
		shell->line = readline(CYAN"AlicornioPrompt$ "RESET);
	if (errno == 1)
		shell->exit_return = 1;
	g_interactive = 0;
	signal(SIGQUIT, sigquit_handler);
}

int	find_enviro_command(t_shell *shell)
{
	int	i;

	i = -1;
	if (!shell->command || shell->has_pipes)
		return (0);
	while (++i < 8)
	{
		if (ft_strcmp(shell->command, shell->list_commands[i]) == 0)
		{
			execute_command(shell, i);
			return (1);
		}
	}
	return (0);
}

int	find_command(t_shell *shell)
{
	int	i;

	i = -1;
	while (++i < shell->size_c)
	{
		if (!shell->command)
			return (0);
		if (ft_strcmp(shell->command, shell->list_commands[i]) == 0)
		{
			execute_command(shell, i);
			return (1);
		}
	}
	return (0);
}

void	execute_command(t_shell *shell, int i)
{
	if (i == 0)
		export(shell);
	else if (i == 1)
		env(shell);
	else if (i == 2)
		unset(shell);
	else if (i == 3)
		wellcome_header(shell);
	else if (i == 4)
		exit_minishell(shell);
	else if (i == 5)
		help(shell);
	else if (i == 6)
		print_pwd(shell);
	else if (i == 7)
		cd(shell);
	else if (i == 8)
		echo(shell);
}

int	system_commmand(t_shell *shell, char **envp)
{
	int			ex_res;
	char		**env_aux;
	char		**paths_list;

	env_aux = envp;
	while (*env_aux && ft_strncmp(*env_aux, "PATH", 4))
		env_aux++;
	if (!*env_aux)
		command_error(shell, shell->command);
	*env_aux += 5;
	paths_list = ft_split(*env_aux, ':');
	ex_res = 0;
	while (*shell->command_plus_args && *paths_list)
	{
		ex_res = execve (shell->command, shell->command_plus_args, envp);
		if (ex_res < 0)
			ex_res = execve (ft_strjoin(ft_strjoin(*paths_list, "/"),
						shell->command), shell->command_plus_args, envp);
		paths_list++;
	}
	if (ex_res)
		return (0);
	return (1);
}