/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_exit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 19:15:02 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/06/11 19:15:13 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

void	exit_pipex(t_pipe *pipes, int rtncode)
{
	free_char_arr(pipes->paths);
	free(pipes->cmds);
	close_and_free(pipes->pipes_cmd);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	if (pipes->here_doc)
	{
		if (unlink(pipes->infile) < 0)
			print_error("unlink", true);
		free(pipes->infile);
	}
	if (pipes->pids)
		free(pipes->pids);
	free(pipes);
	exit(rtncode);
}

void	init_error(t_pipe *pipes, char *msg, int rtncode)
{
	if (msg)
		perror(msg);
	rtncode = EXIT_FAILURE;
	exit_pipex(pipes, rtncode);
}

void	cmd_error(t_pipe *pipes, char **arr, char **arr1, int rtncode)
{
	if (arr)
		free_char_arr(arr);
	if (arr1)
		free_char_arr(arr1);
	init_error(pipes, "command error", rtncode);
}

void	path_error(t_pipe *pipes, char **arr, char *msg, int rtncode)
{
	if (arr)
		free_char_arr(arr);
	init_error(pipes, msg, rtncode);
}

void	exec_error(t_pipe *pipes, char **arr, char *msg, int rtncode)
{
	if (arr)
	{
		print_error(msg, false);
		free_char_arr(arr);
	}
	else
		print_error(msg, true);
	exit_pipex(pipes, rtncode);
}
