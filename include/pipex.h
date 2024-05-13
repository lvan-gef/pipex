/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 21:52:56 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/14 00:13:20 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/headers/libft.h"

typedef struct s_pipe
{
	char	*infile;
	size_t	cmd_size;
	char	**cmds;
	int		**pipes_cmd;
	char	*outfile;
	size_t	path_size;
	char	**paths;
	pid_t	*pids;
}	t_pipe;

// free_it.c
void	free_char_arr(char **arr);
void	free_int_arr(int **arr);
void	close_and_free(int **arr);

// get_cmd.c
char	**get_cmd(t_pipe *pipes, size_t cmd_index);

// handle_cmd.c
int		run_cmd(t_pipe *pipes, size_t index, char **envp);

// handle_exit.c
void	exit_pipex(t_pipe *pipes, int rtncode);
void	init_error(t_pipe *pipes, const char *msg, int rtncode);
void	cmd_error(t_pipe *pipes, char **arr, char **arr1, int rtncode);
void	path_error(t_pipe *pipes, char **arr, const char *msg, int rtncode);
void	exec_error(t_pipe *pipes, char **arr, const char *msg, int rtncode);

// handle_print.c
void	print_error(const char *what, bool found);

// init.c
t_pipe	*init(char **argv, char **envp);

// paths.c
char	**get_paths(t_pipe *pipes, char **envp);

// parse_args.c
char	**get_arg(t_pipe *pipes, const char *raw_arg);

// pipes.c
int		**create_pipes(const t_pipe *pipes);
void	close_all_pipes(t_pipe *pipes);
void	free_close_all_pipes(t_pipe *pipes);

// utils.c
size_t	arr_len(char **arr);
char	*join_path(const char *root, const char *cmd);
char	**single_to_double_p(const char *arr);
#endif
