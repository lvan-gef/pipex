/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/28 22:55:06 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/28 22:55:08 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	int	wait_for_finish(t_pipe *pipes)
{
	size_t	index;
	pid_t	result;
	int		status;

	index = 0;
	status = 0;
	while (index < pipes->cmd_size)
	{
		result = waitpid(pipes->pids[index], &status, 0);
		if (result == -1)
			print_error("waitpid", true);
		index++;
	}
	return (WEXITSTATUS(status));
}

static	int	parent(t_pipe *pipes, char **envp)
{
	size_t	index;

	pipes->pids = ft_calloc(pipes->cmd_size, sizeof(pid_t));
	if (pipes->pids == NULL)
		init_error(pipes, "malloc", errno);
	index = 0;
	while (index < pipes->cmd_size)
	{
		pipes->pids[index] = fork();
		if (pipes->pids[index] == -1)
		{
			perror("fork");
			exit_pipex(pipes, EXIT_FAILURE);
		}
		run_cmd(pipes, index, envp);
		index++;
	}
	close_all_pipes(pipes);
	return (wait_for_finish(pipes));
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipes;
	int		result;

	if (argc != 5)
	{
		ft_putstr_fd("Pipex expected 4 arguments. Got: ", 2);
		ft_putnbr_fd(argc - 1, 2);
		ft_putchar_fd('\n', 2);
		exit(1);
	}
	pipes = init(argv, envp);
	result = parent(pipes, envp);
	exit_pipex(pipes, result);
	return (result);
}
