/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 22:22:49 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/05 00:29:00 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	free_me(char **words, int len)
{
	int	index;

	index = 0;
	while (index < len)
	{
		if (words[index])
			free(words[index]);
		index++;
	}
	free(words);
}

int	word_counter(const char *s, char c)
{
	int	index;
	int	counter;
	int	delim;

	index = 0;
	counter = 0;
	delim = 1;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			delim = 1;
		else
		{
			if (delim)
			{
				delim = 0;
				counter++;
			}
		}
		index++;
	}
	return (counter);
}

int	add_me(const char *s, int start, int stop, char **words)
{
	int	index;

	index = 0;
	while (words[index])
		index++;
	words[index] = ft_substr(s, start, stop - start);
	if (!words[index])
		return (0);
	return (1);
}

int	find_words(const char *s, char c, char **words, int len)
{
	int	index;
	int	fc;

	index = 0;
	while (index < len)
	{
		while (index < len)
		{
			if (s[index] != c)
				break ;
			index++;
		}
		fc = index;
		while (index < len)
		{
			if (s[index] == c)
				break ;
			index++;
		}
		if (index > fc)
			if (!add_me(s, fc, index, words))
				return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	int		len;
	char	**words;

	if (!s)
		return (NULL);
	wc = word_counter(s, c) + 1;
	len = (int)ft_strlen(s);
	words = ft_calloc(wc, sizeof(char *));
	if (!words)
		return (NULL);
	if (!find_words(s, c, words, len))
	{
		free_me(words, wc);
		return (NULL);
	}
	return (words);
}
