/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 12:54:18 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/03/02 16:57:03 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

// find substring of len x in string aka needle in a haystack

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	li_index;
	size_t	check_point;

	index = 0;
	li_index = 0;
	check_point = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	if (!*haystack)
		return (NULL);
	while (haystack[index] != '\0' && index < len)
	{
		check_point = index;
		while (haystack[index] == needle[li_index] && index < len)
		{
			li_index++;
			index++;
			if (needle[li_index] == '\0')
				return ((char *)&haystack[check_point]);
		}
		index = check_point + 1;
		li_index = 0;
	}
	return (NULL);
}
