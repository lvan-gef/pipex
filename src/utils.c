/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/28 22:55:33 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/14 00:04:41 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

size_t	arr_len(char **arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (i);
	while (arr[i] != NULL)
		i++;
	return (i);
}

char	*join_path(const char *root, const char *cmd)
{
	size_t	len_root;
	size_t	len_cmd;
	size_t	new_len;
	char	*cmd_path;

	len_root = ft_strlen(root);
	len_cmd = ft_strlen(cmd);
	new_len = len_root + len_cmd + 1;
	cmd_path = ft_calloc(new_len + 1, sizeof(char));
	if (cmd_path == NULL)
		return (NULL);
	new_len = ft_strlcat(cmd_path, root, len_root + 1);
	new_len = ft_strlcat(cmd_path, "/", new_len + 2);
	if (len_cmd > 0)
		ft_strlcat(cmd_path, cmd, new_len + len_cmd + 1);
	return (cmd_path);
}

char	**single_to_double_p(const char *arr)
{
	char	**out_arr;

	out_arr = ft_calloc(2, sizeof(char *));
	if (out_arr == NULL)
		return (NULL);
	out_arr[0] = ft_calloc(ft_strlen(arr) + 1, sizeof(char));
	if (out_arr[0] == NULL)
	{
		free(out_arr);
		return (NULL);
	}
	ft_strlcpy(out_arr[0], arr, ft_strlen(arr) + 1);
	return (out_arr);
}
