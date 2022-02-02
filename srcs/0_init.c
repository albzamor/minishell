/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:33:27 by antonmar          #+#    #+#             */
/*   Updated: 2022/02/01 21:28:21 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_path *init_path(t_shell *shell)
{

	shell->path->user = ft_strdup(getenv("USER"));
	shell->path->home = ft_strdup("/Users/");
	shell->path->home_user = ft_strjoin(shell->path->home, shell->path->user);
	return(shell->path);
}

t_shell *initialice(char** envp)
{
	t_shell *shell;

	shell = malloc(sizeof(t_shell));
	shell->exit = 0;
	shell->path = malloc(sizeof(t_path));
	shell->path = init_path(shell);
	shell->env_list = init_list_env(shell, envp);
	shell->line = NULL;
	shell->line_walker = NULL;
	shell->line_args = NULL;
	shell->size_c = 7;//Numero de comandos actualizar al final
	shell->list_commands = malloc(sizeof(char*) * shell->size_c);
	shell->list_commands[0]="pwd";
	shell->list_commands[1]="exit";
	shell->list_commands[2]="hello";
	shell->list_commands[3]="help";
	shell->list_commands[4]="cd";
	shell->list_commands[5]="echo";
	shell->list_commands[6]="clear";
	return (shell);
}

t_env_list	*init_list_env(t_shell *shell, char** envp)
{
	t_env_list *init;
	t_env_list	*this_list_var;
	int size_envp;
	int i;



	this_list_var = env_var_list_new(envp[0]);
	//env_var_add_back(&shell->env_list, this_list_var);
	init = this_list_var;

	i = 0;

	size_envp = sizeof(envp) / sizeof(char *);

	while (++i < size_envp)
	{
		this_list_var = env_var_list_new(envp[i]);
		env_var_add_back(&shell->env_list, this_list_var);
	}
	return (init);


}

t_env_list	*env_var_list_new(char* env_var)
{
	t_env_list	*env_list;

	env_list = (t_env_list *)malloc(sizeof(t_env_list));
	if (!env_list)
		return (NULL);
	env_list->var_content = env_var;
	env_list->next = NULL;
	return (env_list);
}

void	env_var_add_back(t_env_list **env_list, t_env_list *new)
{
	t_env_list	*aux;

	aux = *env_list;
	if (!new)
		return ;
	if (!*env_list)
	{
		*env_list = new;
		return ;
	}
	while ((*env_list)->next)
		*env_list = (*env_list)->next;
	(*env_list)->next = new;
	*env_list = aux;
}




t_arglist	*arg_node_new(char *first_arg)
{
	t_arglist	*arg_list;

	arg_list = (t_arglist *)malloc(sizeof(t_arglist));
	if (!arg_list)
		return (NULL);
	arg_list->content = first_arg;
	arg_list->next = NULL;
	return (arg_list);
}

void	arglstadd_back(t_arglist **arg_lst, t_arglist *new)
{
	t_arglist	*aux;

	aux = *arg_lst;
	if (!new)
		return ;
	if (!*arg_lst)
	{
		*arg_lst = new;
		return ;
	}
	while ((*arg_lst)->next)
		*arg_lst = (*arg_lst)->next;
	(*arg_lst)->next = new;
	*arg_lst = aux;
}