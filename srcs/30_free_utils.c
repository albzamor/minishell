/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 11:02:23 by albzamor          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/04 16:14:19 by antonmar         ###   ########.fr       */
=======
/*   Updated: 2022/08/29 21:29:14 by albzamor         ###   ########.fr       */
>>>>>>> c697262eec52e2049e1a71d5fd510ed4bf1fd253
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	new_free(char **ptr)
{
	free (*ptr);
	*ptr = NULL;
}

void	free_matrix(char **array)
{
	char	**array_walker;
	char	**array_aux;

	array_walker = array;
	while (array_walker && *array_walker)
	{
		array_aux = array_walker;
		new_free(array_aux);
		array_walker++;
<<<<<<< HEAD
	}
	if (array)
	{
		new_free(array);
		new_free(array_walker);
=======
>>>>>>> c697262eec52e2049e1a71d5fd510ed4bf1fd253
	}
}

void	free_all_struct(t_shell *shell, char **envp)
{
	int	i;

	i = 0;
	(void)envp;
	if (shell->line)
		new_free(&shell->line);
	shell->line = NULL;
	shell->has_pipes = 0;
	new_free(&shell->env_list_plus->next->var_content);
	free_parent(shell);
	shell->command_args = shell->command_plus_args;
	free_matrix(shell->command_plus_args);
	free(shell->command_plus_args);
	shell->command_plus_args = NULL;
}

void	free_parent(t_shell *shell)
{
	free_arg_list(&shell->arg_list);
	shell->size_com_args = 0;
	if (shell->command)
		new_free(&shell->command);
	if (shell->command_flag)
	{
		new_free(&shell->free_aux_list);
		shell->command_flag = NULL;
	}
}

void	free_arg_list(t_arglist **arg_lst)
{
	t_arglist	*cleaner;
	t_arglist	*aux;

	cleaner = *arg_lst;
	while (cleaner)
	{
		aux = cleaner->next;
		free(cleaner->content);
		free(cleaner);
		cleaner = aux;
	}
	*arg_lst = NULL;
}
