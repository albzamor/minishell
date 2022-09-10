/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:16:16 by albzamor          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/04 15:31:16 by antonmar         ###   ########.fr       */
=======
/*   Updated: 2022/08/30 18:11:53 by albzamor         ###   ########.fr       */
>>>>>>> c697262eec52e2049e1a71d5fd510ed4bf1fd253
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sigint_handler(int sig)
{
	if ((sig == SIGINT || sig == SIGQUIT) && g_interactive != 2)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		printf("\n");
		rl_redisplay();
		errno = 1;
		return ;
	}
	else
	{
		printf("\33[2K\r");
		exit(1);
	}
}

void	sigquit_handler(int sig)
{
	char	*nbr;

	if (g_interactive == 0)
	{
		nbr = ft_itoa(sig);
		ft_putendl_fd(ft_strjoin("Quit: ", nbr), 2);
		g_interactive = 1;
		free(nbr);
		return ;
	}
	signal(SIGQUIT, SIG_IGN);
}

void	siguser_handler(int sig)
{
	(void)sig;
	signal(SIGQUIT, SIG_IGN);
}

void	signal_handler(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	signal(SIGUSR1, siguser_handler);
}
