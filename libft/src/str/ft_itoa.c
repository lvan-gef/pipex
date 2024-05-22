/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 17:19:26 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/04 23:17:17 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	get_len(int c)
{
	int	counter;
	int	base;

	counter = 0;
	base = 10;
	if (c < 0)
	{
		c *= -1;
		counter++;
	}
	if (c == 0)
		counter++;
	while (c != 0)
	{
		c = c / base;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	int		l;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = get_len(n);
	str = ft_calloc(l + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	l--;
	while (n != 0)
	{
		str[l] = (n % 10) + '0';
		n = n / 10;
		l--;
	}
	return (str);
}
