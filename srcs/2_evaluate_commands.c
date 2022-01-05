#include "../includes/minishell.h"

void find_command(t_shell *shell)
{
	int i;

	i = -1;

	while (++i < shell->size_c)
	{
		if (ft_strcmp(shell->command, shell->list_commands[i]) == 0)
		{
			execute_command(shell, i);
			return;
		} // comparar para cada comando. Hacer una tabla con todos¿?¿?
	}
	command_error(shell);
}

void execute_command(t_shell *shell, int i)
{
	if (i == 0)
		print_pwd();
	else if (i == 1)
		exit_minishell(shell);
	else if (i == 2)
		header(shell);
	else if (i == 3)
		help(shell);
	else if (i == 4)
		cd(shell);
	else if (i == 5)
		echo(shell);
}