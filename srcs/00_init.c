/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:33:27 by antonmar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/10 11:25:23 by albzamor         ###   ########.fr       */
=======
/*   Updated: 2022/08/30 18:10:47 by albzamor         ###   ########.fr       */
>>>>>>> c697262eec52e2049e1a71d5fd510ed4bf1fd253
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_path	*init_path(t_shell *shell)
{
	shell->path->user = ft_strdup(getenv("USER"));
	shell->path->home_user = ft_strjoin("/Users/", shell->path->user);
	return (shell->path);
}

/**
 * It initializes the list of commands.
 * 
 * @param shell the shell structure
 */
void	init_list_command(t_shell *shell)
{
	shell->size_c = 9;
	shell->list_commands = malloc(sizeof(char *) * shell->size_c);
	shell->list_commands[0] = "export";
	shell->list_commands[1] = "env";
	shell->list_commands[2] = "unset";
	shell->list_commands[3] = "hello";
	shell->list_commands[4] = "exit";
	shell->list_commands[5] = "help";
	shell->list_commands[6] = "pwd";
	shell->list_commands[7] = "cd";
	shell->list_commands[8] = "echo";
}

/* Initializing the shell structure. */
t_shell	*initialice(char **envp)
{
	t_shell	*shell;

	(void)envp;
	shell = malloc(sizeof(t_shell));
	ft_memset(shell, 0, sizeof(t_shell));
	shell->path = malloc(sizeof(t_path));
	ft_memset(shell->path, 0, sizeof(t_path));
	shell->path = init_path(shell);
	shell->aux_p = malloc(sizeof(t_aux_p));
	ft_memset(shell->aux_p, 0, sizeof(t_aux_p));
	shell->env_list = init_list_env(shell, envp);
	init_list_command(shell);
	shell->pipes_struct = malloc(sizeof(t_pipes));
	ft_memset(shell->pipes_struct, 0, sizeof(t_pipes));
	return (shell);
}

/* Creating a new node for the linked list. */
t_env_list	*env_var_list_new(char *env_var)
{
	t_env_list	*env_list;

	env_list = (t_env_list *)malloc(sizeof(t_env_list));
	if (!env_list)
		return (NULL);
	env_list->var_name = cut_env_var_name(env_var);
	env_list->var_content = cut_env_var_content(env_var);
	env_list->next = NULL;
	return (env_list);
}

<<<<<<< HEAD
/* Counting the number of nodes in the linked list. */
=======
>>>>>>> c697262eec52e2049e1a71d5fd510ed4bf1fd253
int	ft_lst_env_size(t_env_list *lst)

{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
