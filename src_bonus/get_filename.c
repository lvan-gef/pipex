/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_filename.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/17 15:31:07 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/06/17 15:31:08 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/pipex_bonus.h"

static	size_t	len_of_nbr(void *ptr)
{
	size_t		size;
	long int	addr;

	addr = (long int)ptr;
	size = 0;
	while (addr > 0)
	{
		addr = addr / 10;
		size++;
	}
	return (size);
}

static	void	addr_as_str(void *ptr, char *filename, long int offset)
{
	size_t		size;
	int			remainder;
	long int	nbr;

	nbr = (long int)ptr + offset;
	size = len_of_nbr(ptr);
	while (size > 0)
	{
		remainder = nbr % 10;
		filename[size] = remainder + '0';
		size--;
		nbr = nbr / 10;
	}
}

char	*get_filename(void)
{
	char		*filename;
	long int	offset;
	size_t		new_size;

	offset = 0;
	while (1)
	{
		filename = ft_calloc(len_of_nbr(&filename) + 8, sizeof(char));
		if (filename == NULL)
			return (NULL);
		filename[0] = '.';
		addr_as_str(&filename, filename, offset);
		new_size = ft_strlen(filename) + ft_strlen(".pipex") + 1;
		ft_strlcat(filename, ".pipex", new_size);
		if (access(filename, F_OK) == 0)
		{
			offset++;
			free(filename);
		}
		else
			break ;
	}
	return (filename);
}
