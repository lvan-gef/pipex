/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/06 17:21:54 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/06/06 17:21:55 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

static	void	set_cmds(t_pipe *pipes, char **args)
{
	size_t	index;
	size_t	counter;

	pipes->cmds = ft_calloc(pipes->cmd_size + 1, sizeof(char *));
	if (pipes->cmds == NULL)
		init_error(pipes, "malloc", errno);
	index = 2;
	if (pipes->here_doc == true)
		index++;
	counter = 0;
	while (counter < pipes->cmd_size)
	{
		pipes->cmds[counter] = args[index];
		counter++;
		index++;
	}
}

static	void	set_paths(t_pipe *pipes, char **envp)
{
	size_t	index;
	char	**paths;

	paths = get_paths(pipes, envp);
	if (paths == NULL)
		init_error(pipes, "malloc", errno);
	if (!ft_strncmp(paths[0], "", 1))
	{
		free_char_arr(paths);
		return ;
	}
	pipes->path_size = arr_len(paths);
	pipes->paths = ft_calloc(pipes->path_size + 1, sizeof(char *));
	if (pipes->paths == NULL)
		path_error(pipes, paths, "malloc", errno);
	index = 0;
	while (index < pipes->path_size)
	{
		pipes->paths[index] = ft_strdup(paths[index]);
		if (pipes->paths[index] == NULL)
			path_error(pipes, paths, "malloc", errno);
		index++;
	}
	free_char_arr(paths);
}

static	void	create_cmd_pipes(t_pipe *pipes)
{
	pipes->pipes_cmd = create_pipes(pipes);
	if (pipes->pipes_cmd == NULL)
		init_error(pipes, NULL, errno);
}

t_pipe	*init(char **args, char **envp)
{
	t_pipe	*pipes;
	size_t	args_len;

	args_len = arr_len(args);
	pipes = ft_calloc(1, sizeof(t_pipe));
	if (pipes == NULL)
		init_error(pipes, "malloc", errno);
	pipes->cmd_size = args_len - 4;
	pipes->here_doc = true;
	if (ft_strncmp(args[1], "here_doc", 8))
	{
		pipes->infile = args[1];
		pipes->here_doc = false;
		pipes->cmd_size++;
	}
	pipes->outfile = args[args_len - 1];
	set_paths(pipes, envp);
	set_cmds(pipes, args);
	create_cmd_pipes(pipes);
	return (pipes);
}
