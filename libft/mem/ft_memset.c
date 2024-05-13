/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:27:27 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/03/02 16:52:41 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*a;

	a = b;
	while (len)
	{
		*a++ = (unsigned char)c;
		len--;
	}
	return (b);
}
