/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 16:05:34 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/04 23:17:22 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_pos;
	int		end_pos;
	int		len;

	if (!s1 || !set)
		return (NULL);
	start_pos = 0;
	end_pos = ft_strlen(s1);
	while (s1[start_pos] != '\0')
	{
		if (!ft_strchr(set, s1[start_pos]))
			break ;
		start_pos++;
	}
	while (end_pos != 0)
	{
		if (!ft_strchr(set, s1[end_pos]))
			break ;
		end_pos--;
	}
	len = end_pos - start_pos + 1;
	return (ft_substr(s1, start_pos, len));
}
