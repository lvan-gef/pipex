/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 21:52:56 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/06/15 15:51:53 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	bool	here_doc;	
}	t_pipe;

// free_it.c
void	free_char_arr(char **arr);
void	free_int_arr(int **arr);
void	close_and_free(int **arr);

// get_cmd.c
char	**get_cmd(t_pipe *pipes, size_t cmd_index);

// get_filename.c
char	*get_filename(void);

// handle_cmd.c
int		run_cmd(t_pipe *pipes, size_t index, char **envp);

// handle_doc.c
void	handle_doc(t_pipe *pipes, char **args);

// handle_exit.c
void	exit_pipex(t_pipe *pipes, int rtncode);
void	init_error(t_pipe *pipes, char *msg, int rtncode);
void	cmd_error(t_pipe *pipes, char **arr, char **arr1, int rtncode);
void	path_error(t_pipe *pipes, char **arr, char *msg, int rtncode);
void	exec_error(t_pipe *pipes, char **arr, char *msg, int rtncode);

// handle_print.c
void	print_error(char *what, bool found);

// init.c
t_pipe	*init(char **argv, char **envp);

// paths.c
char	**get_paths(t_pipe *pipes, char **envp);

// parse_args.c
char	**get_arg(t_pipe *pipes, char *raw_arg);

// pipes.c
int		**create_pipes(t_pipe *pipes);
void	close_all_pipes(t_pipe *pipes);
void	free_close_all_pipes(t_pipe *pipes);

// utils.c
size_t	arr_len(char **arr);
char	*join_path(char *root, char *cmd);
char	**single_to_double_p(char *arr);
#endif
