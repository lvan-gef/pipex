/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/28 22:55:17 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/28 22:55:19 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

static	char	**no_path(t_pipe *pipes)
{
	char	**empty;
	size_t	index;
	size_t	size;

	size = 1;
	index = 0;
	empty = ft_calloc(size + 1, sizeof(char *));
	if (empty == NULL)
		init_error(pipes, "malloc", errno);
	while (index < size)
	{
		empty[index] = ft_calloc(1, sizeof(char));
		if (empty[index] == NULL)
		{
			free_char_arr(empty);
			init_error(pipes, "malloc", errno);
		}
		index++;
	}
	return (empty);
}

char	**get_paths(t_pipe *pipes, char **envp)
{
	size_t	i;
	char	**raw_path;
	char	**paths;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
		{
			raw_path = ft_split(envp[i], '=');
			if (raw_path == NULL)
				return (NULL);
			paths = ft_split(raw_path[1], ':');
			if (paths == NULL)
			{
				free_char_arr(raw_path);
				return (NULL);
			}
			free_char_arr(raw_path);
			return (paths);
		}
		i++;
	}
	return (no_path(pipes));
}
