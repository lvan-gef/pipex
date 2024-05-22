/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 16:01:04 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/04 23:17:21 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	add_to(char *str, char const *s, int str_index)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		str[str_index] = s[index];
		index++;
		str_index++;
	}
	return (str_index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		str_index;

	if (!s1 || !s2)
		return (NULL);
	str_index = 0;
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (0);
	str_index = add_to(str, s1, str_index);
	str_index = add_to(str, s2, str_index);
	str[str_index] = '\0';
	return (str);
}
