/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_it.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/28 22:54:05 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/28 22:54:08 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_char_arr(char **arr)
{
	size_t	index;

	index = 0;
	if (arr == NULL)
		return ;
	while (arr[index] != NULL)
	{
		free(arr[index]);
		index++;
	}
	free(arr);
}

void	free_int_arr(int **arr)
{
	size_t	index;

	index = 0;
	if (arr == NULL)
		return ;
	while (arr[index] != NULL)
	{
		free(arr[index]);
		index++;
	}
	free(arr);
}

void	close_and_free(int **arr)
{
	size_t	index;

	index = 0;
	if (arr == NULL)
		return ;
	while (arr[index] != NULL)
	{
		close(arr[index][0]);
		close(arr[index][1]);
		free(arr[index]);
		index++;
	}
	free(arr);
}
