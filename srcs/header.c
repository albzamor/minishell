/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 21:00:57 by albzamor          #+#    #+#             */
/*   Updated: 2021/12/29 19:49:59 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	header(void)
{
	char *user;

	user = getenv("USER");//get user
	printf(YELLOW"%s", user);
	printf(GREEN " bienvenido a nuestra:\n");
	printf(CYAN"█▀▄▀█ █ █▄░█ █ █▀ █░█ █▀▀ █░░ █░░\n");
	printf(YELLOW"█░▀░█ █ █░▀█ █ ▄█ █▀█ ██▄ █▄▄ █▄\n");
	printf(GREEN"     by Antonmar🐔 and Albzamor🏴‍☠️\n");
}

