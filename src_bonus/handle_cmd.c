/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_cmd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/28 22:54:19 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/28 22:54:21 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

static	void	handle_infile(t_pipe *pipes)
{
	int	fd;

	fd = open(pipes->infile, O_RDONLY);
	if (fd < 0)
	{
		print_error(pipes->infile, true);
		if (dup2(STDIN_FILENO, pipes->pipes_cmd[0][0]) == -1)
		{
			print_error("dup2", true);
			exit_pipex(pipes, EXIT_FAILURE);
		}
		exit_pipex(pipes, EXIT_FAILURE);
	}
	else
	{
		if (dup2(fd, STDIN_FILENO) == -1)
		{
			print_error("dup2", true);
			close(fd);
			exit_pipex(pipes, EXIT_FAILURE);
		}
		close(fd);
	}
}

static	void	handle_outfile(t_pipe *pipes)
{
	int	fd;

	fd = open(pipes->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		print_error(pipes->outfile, true);
		exit_pipex(pipes, EXIT_FAILURE);
	}
	else
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
		{
			print_error("dup2", true);
			close(fd);
			exit_pipex(pipes, EXIT_FAILURE);
		}
		close(fd);
	}
}

static	void	handle_middle_cmd(t_pipe *pipes, size_t index)
{
	if (dup2(pipes->pipes_cmd[index][1], STDOUT_FILENO) == -1)
	{
		print_error("dup2", true);
		exit_pipex(pipes, EXIT_FAILURE);
	}
	close(pipes->pipes_cmd[index][0]);
	close(pipes->pipes_cmd[index][1]);
}

static	char	**init_cmd(t_pipe *pipes, size_t index)
{
	char	**cmd_path;

	if (index == 0)
		handle_infile(pipes);
	else
	{
		if (dup2(pipes->pipes_cmd[index - 1][0], STDIN_FILENO) == -1)
		{
			print_error("dup2", true);
			exit_pipex(pipes, EXIT_FAILURE);
		}
		close(pipes->pipes_cmd[index - 1][0]);
	}
	if (index < pipes->cmd_size - 1)
		handle_middle_cmd(pipes, index);
	else
		handle_outfile(pipes);
	close_all_pipes(pipes);
	cmd_path = get_cmd(pipes, index);
	if (cmd_path == NULL)
		cmd_error(pipes, NULL, NULL, errno);
	return (cmd_path);
}

int	run_cmd(t_pipe *pipes, size_t index, char **envp)
{
	char	**cmd_path;

	cmd_path = NULL;
	if (pipes->pids[index] == 0)
	{
		cmd_path = init_cmd(pipes, index);
		execve(cmd_path[0], cmd_path, envp);
		if (errno == 2)
			exec_error(pipes, cmd_path, cmd_path[0], 127);
		else if (errno == 13)
			exec_error(pipes, cmd_path, cmd_path[0], 126);
		else
			exec_error(pipes, cmd_path, cmd_path[0], errno);
	}
	free_char_arr(cmd_path);
	return (EXIT_SUCCESS);
}
