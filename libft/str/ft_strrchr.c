/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 17:24:01 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/03/02 16:57:09 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

// searches for the last occurrence of the character c

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	int		last_index;
	char	*str_ptr;
	char	cc;

	index = 0;
	last_index = -1;
	str_ptr = (char *)s;
	cc = c;
	if (cc == '\0')
	{
		return (ft_strchr(s, c));
	}
	while (str_ptr[index] != '\0')
	{
		if (ft_strchr(&str_ptr[index], c) != NULL)
			last_index = index;
		index++;
	}
	if (last_index > -1)
		return (&str_ptr[last_index]);
	return (NULL);
}
