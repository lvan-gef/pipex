/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:27:27 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/04 23:16:58 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*a;

	a = b;
	while (len--)
	{
		*a++ = (unsigned char)c;
	}
	return (b);
}
