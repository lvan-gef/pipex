/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_doc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/17 15:30:33 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/06/17 15:30:35 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

static	void	write_fail(t_pipe *pipes, char *filename, char *line, int fd)
{
	print_error("write", true);
	close(fd);
	unlink(filename);
	free(filename);
	if (line != NULL)
		free(line);
	exit_pipex(pipes, 1);
}

static	void	pre_promt(t_pipe *pipes)
{
	size_t	counter;

	counter = 0;
	if (pipes->cmd_size - 1 > 0)
	{
		while (counter < pipes->cmd_size - 1)
		{
			if (write(1, "pipe ", 5) < 0)
				break ;
			counter++;
		}
	}
	write(1, "heredoc> ", 9);
}

static	void	read_input(t_pipe *pipes, char *filename, char **args, int fd)
{
	char	*line;

	pre_promt(pipes);
	line = get_next_line(0);
	while (line)
	{
		if (ft_strncmp(line, "\n\0", 2) && \
			!ft_strncmp(line, args[2], ft_strlen(line) - 1) && \
			!ft_strncmp(args[2], line, ft_strlen(args[2])))
		{
			free(line);
			break ;
		}
		if (write(fd, line, ft_strlen(line)) < 0)
			write_fail(pipes, filename, line, fd);
		pre_promt(pipes);
		free(line);
		line = get_next_line(0);
	}
}

static	void	user_input(t_pipe *pipes, char *filename, char **args)
{
	int		fd;

	fd = open(filename, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		free(filename);
		init_error(pipes, "here_doc", errno);
	}
	read_input(pipes, filename, args, fd);
	close(fd);
}

void	handle_doc(t_pipe *pipes, char **args)
{
	char	*filename;

	filename = get_filename();
	if (filename == NULL)
		init_error(pipes, "malloc", errno);
	pipes->infile = ft_calloc(ft_strlen(filename) + 1, sizeof(char));
	if (pipes->infile == NULL)
		path_error(pipes, NULL, "malloc", errno);
	ft_strlcpy(pipes->infile, filename, ft_strlen(filename) + 1);
	user_input(pipes, filename, args);
	free(filename);
}
