/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_evaluate_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albzamor <albzamor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:11:21 by antonmar          #+#    #+#             */
/*   Updated: 2022/09/10 13:13:14 by albzamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Checking if there is a character in the string. */
int	check_char(char *str, char char_tofind)
{
	while (str && *str)
	{
		if (*str && *str == char_tofind)
			return (1);
		str++;
	}
	return (0);
}

void	ignore_quotes(char **line)
{
	char		quotes;

	quotes = check_allquotes(*line);
	if (quotes)
	{
		(*line)++;
		while (**line && **line != quotes)
			(*line)++;
		if (*line)
			(*line)++;
	}
}

/* Checking if there is a pipe in the command line. */
int	check_pipe_syntax(t_shell *shell)
{
	char		*checker;

	checker = shell->line;
	while (*checker)
	{
		ignore_quotes(&checker);
		if (*checker == '|')
		{
			shell->has_pipes = 1;
			checker++;
			while (*checker && *checker == ' ')
				checker++;
			if (!*checker || *checker == '|')
				return (1);
		}
		checker++;
	}
	return (0);
}

int	check_quotes_syntax(char *line)
{
	char	*checker;
	char	quotes;

	checker = line;
	if (!*line)
		return (0);
	while (line && *checker)
	{
		if (*checker == '\"' || *checker == '\'')
		{
			quotes = check_allquotes(checker);
			if (!quotes)
				return (1);
			checker++;
			while (*checker && *checker != quotes)
				checker++;
		}
		checker++;
	}
	return (0);
}

int	check_arrow_syntax(char *line, char arrow)
{
	char		*checker;

	checker = line;
	while (*checker)
	{
		ignore_quotes(&checker);
		if (*checker == arrow)
		{
			checker++;
			if (*checker == arrow)
				checker++;
			while (*checker && *checker == ' ')
			{
				if (*checker == arrow)
					return (1);
				checker++;
			}
			if (!*checker || *checker == arrow)
				return (1);
		}
		checker++;
	}
	return (0);
}
