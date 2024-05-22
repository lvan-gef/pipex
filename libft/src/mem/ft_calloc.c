/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 17:50:33 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/04 23:16:58 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	index;

	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	index = 0;
	while (index < (count * size))
	{
		((char *)mem)[index] = 0;
		index++;
	}
	return (mem);
}
