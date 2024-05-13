/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 17:26:59 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/03/04 21:26:29 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_;
	const char	*src_;
	int			flag;

	dst_ = (char *)dst;
	src_ = (const char *)src;
	flag = 0;
	if (!dst_ && !src_)
		return (NULL);
	if (dst_ >= src_)
	{
		flag = 1;
		src_ += len - 1;
		dst_ += len - 1;
	}
	while (len)
	{
		if (flag > 0)
			*dst_-- = *src_--;
		else
			*dst_++ = *src_++;
		len--;
	}
	return (dst);
}
