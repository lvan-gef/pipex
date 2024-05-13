/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipes.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/28 22:55:23 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/14 00:04:25 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	bool	init_pipes(const t_pipe *pipes, int **cmd_pipes)
{
	size_t	index;

	index = 0;
	while (index < pipes->cmd_size)
	{
		cmd_pipes[index] = ft_calloc(2, sizeof(int));
		if (cmd_pipes[index] == NULL)
		{
			perror("malloc");
			close_and_free(cmd_pipes);
			return (false);
		}
		if (pipe(cmd_pipes[index]) == -1)
		{
			perror("pipe");
			close_and_free(cmd_pipes);
			return (false);
		}
		index++;
	}
	return (true);
}

int	**create_pipes(t_pipe *pipes)
{
	int	**cmd_pipes;

	cmd_pipes = ft_calloc(pipes->cmd_size + 1, sizeof(int *));
	if (cmd_pipes == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	if (init_pipes(pipes, cmd_pipes) == false)
		return (NULL);
	return (cmd_pipes);
}

void	close_all_pipes(t_pipe *pipes)
{
	size_t	index;

	index = 0;
	while (index < pipes->cmd_size)
	{
		close(pipes->pipes_cmd[index][0]);
		close(pipes->pipes_cmd[index][1]);
		index++;
	}
}

void	free_close_all_pipes(t_pipe *pipes)
{
	size_t	index;

	index = 0;
	while (index < pipes->cmd_size)
	{
		close(pipes->pipes_cmd[index][0]);
		close(pipes->pipes_cmd[index][1]);
		free(pipes->pipes_cmd[index]);
		index++;
	}
	free(pipes->pipes_cmd);
}
