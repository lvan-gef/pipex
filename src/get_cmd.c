/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cmd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 17:18:20 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/06/06 17:21:11 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	char	**is_empty(t_pipe *pipes, size_t cmd_index)
{
	char	*clean_cmd;
	char	**argv;

	clean_cmd = ft_strtrim(pipes->cmds[cmd_index], " \t\v\f\r\n");
	if (clean_cmd == NULL)
		path_error(pipes, NULL, "malloc", errno);
	else if (!ft_strncmp(clean_cmd, "", 1))
	{
		argv = single_to_double_p(clean_cmd);
		free(clean_cmd);
		return (argv);
	}
	free(clean_cmd);
	return (NULL);
}

static	char	**real_path(t_pipe *pipes, size_t cmd_index, size_t index)
{
	char	*path;
	char	**argv;

	argv = get_arg(pipes, pipes->cmds[cmd_index]);
	if (!ft_strncmp(argv[0], "/", 1))
		return (argv);
	path = join_path(pipes->paths[index], argv[0]);
	if (path == NULL)
	{
		free_char_arr(argv);
		return (NULL);
	}
	free(argv[0]);
	argv[0] = path;
	return (argv);
}

char	**get_cmd(t_pipe *pipes, size_t cmd_index)
{
	size_t	index;
	char	**argv;

	index = 0;
	while (index < pipes->path_size)
	{
		argv = is_empty(pipes, cmd_index);
		if (argv != NULL)
			return (argv);
		argv = real_path(pipes, cmd_index, index);
		if (access(argv[0], F_OK) < 0)
			free_char_arr(argv);
		else
			return (argv);
		index++;
	}
	return (get_arg(pipes, pipes->cmds[cmd_index]));
}
