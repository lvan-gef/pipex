/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_is_whitespace.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 21:50:55 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/29 21:50:56 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

bool	ft_is_whitespace(char c)
{
	if (c == 32)
		return (true);
	else if (c >= 9 && c <= 13)
		return (true);
	return (false);
}
