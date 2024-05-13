/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_print.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 17:43:54 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/14 00:03:14 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static	void	join_msg(char *outstr, const char *str, const char *str1, size_t size)
{
	ft_strlcat(outstr, str, size);
	ft_strlcat(outstr, str1, size);
}

void	print_error(char *what, bool found)
{
	char	*out_msg;
	size_t	new_size;

	if (found)
	{
		new_size = 7 + ft_strlen(what);
		out_msg = ft_calloc(new_size + 1, sizeof(char));
		if (out_msg == NULL)
			return ;
		join_msg(out_msg, "pipex: ", what, new_size + 1);
		perror(out_msg);
	}
	else
	{
		new_size = 7 + ft_strlen(what) + 2 + ft_strlen("command not found") + 1;
		out_msg = ft_calloc(new_size + 1, sizeof(char));
		if (out_msg == NULL)
			return ;
		join_msg(out_msg, "pipex: ", what, new_size + 1);
		join_msg(out_msg, ": ", "command not found\n", new_size + 1);
		write(2, out_msg, new_size);
	}
	free(out_msg);
}
