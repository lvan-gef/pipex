/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_arg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 17:50:47 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/14 00:04:25 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	ssize_t	pos_of_dubble(const char *raw_args)
{
	ssize_t	index;

	index = 0;
	if (raw_args == NULL)
		return (-1);
	while (raw_args[index] != '\0')
	{
		if (raw_args[index] == '"')
			return (index);
		index++;
	}
	return (-1);
}

static	ssize_t	pos_of_single(const char *raw_args)
{
	ssize_t	index;

	index = 0;
	if (raw_args == NULL)
		return (-1);
	while (raw_args[index] != '\0')
	{
		if (raw_args[index] == '\'')
			return (index);
		index++;
	}
	return (-1);
}

static	ssize_t	pos_of_ws(const char *raw_args)
{
	ssize_t	index;

	index = 0;
	if (raw_args == NULL)
		return (-1);
	while (raw_args[index] != '\0')
	{
		if (ft_strchr(" \t\v\f\r\n", raw_args[index]))
			return (index);
		index++;
	}
	return (-1);
}

static	char	**clean_arg(t_pipe *pipes, char **raw_args)
{
	char	*raw_arg;
	size_t	index;

	index = 0;
	while (raw_args[index] != NULL)
	{
		raw_arg = ft_strtrim(raw_args[index], " ");
		if (raw_args == NULL)
		{
			free_char_arr(raw_args);
			init_error(pipes, "malloc", errno);
		}
		free(raw_args[index]);
		raw_args[index] = raw_arg;
		index++;
	}
	return (raw_args);
}

char	**get_arg(t_pipe *pipes, char *raw_arg)
{
	ssize_t	d_qoute_pos;
	ssize_t	s_qoute_pos;
	ssize_t	ws_pos;
	char	**out_args;

	d_qoute_pos = pos_of_dubble(raw_arg);
	s_qoute_pos = pos_of_single(raw_arg);
	ws_pos = pos_of_ws(raw_arg);
	if (d_qoute_pos > -1 && s_qoute_pos == -1)
		out_args = ft_split(raw_arg, '"');
	else if (d_qoute_pos == -1 && s_qoute_pos > -1)
		out_args = ft_split(raw_arg, '\'');
	else if (d_qoute_pos < s_qoute_pos)
		out_args = ft_split(raw_arg, '"');
	else if (s_qoute_pos < d_qoute_pos)
		out_args = ft_split(raw_arg, '\'');
	else if (ws_pos > -1)
		out_args = ft_split_ws(raw_arg);
	else
		out_args = single_to_double_p(raw_arg);
	if (out_args == NULL)
		init_error(pipes, "malloc", errno);
	return (clean_arg(pipes, out_args));
}
