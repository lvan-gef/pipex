/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_ws.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 21:51:10 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/05/29 21:51:12 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static	void	free_me(char **words, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		if (words[index])
			free(words[index]);
		index++;
	}
	free(words);
}

static	size_t	word_counter(const char *s)
{
	size_t	index;
	size_t	counter;
	size_t	delim;

	index = 0;
	counter = 0;
	delim = 1;
	while (s[index] != '\0')
	{
		if (ft_is_whitespace(s[index]))
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

static	size_t	add_me(const char *s, size_t start, size_t stop, char **words)
{
	size_t	index;

	index = 0;
	while (words[index])
		index++;
	words[index] = ft_substr(s, start, stop - start);
	if (words[index] == NULL)
		return (0);
	return (1);
}

static	size_t	find_words(const char *s, char **words, size_t len)
{
	size_t	index;
	size_t	start_word;

	start_word = 0;
	index = 0;
	while (index < len)
	{
		while (index < len)
		{
			if (ft_is_whitespace(s[index]) == false)
				break ;
			index++;
		}
		start_word = index;
		while (index < len)
		{
			if (ft_is_whitespace(s[index]))
				break ;
			index++;
		}
		if (index > start_word)
			if (!add_me(s, start_word, index, words))
				return (0);
	}
	return (1);
}

char	**ft_split_ws(char const *s)
{
	size_t	wc;
	size_t	len;
	char	**words;

	if (!s)
		return (NULL);
	wc = word_counter(s) + 1;
	len = ft_strlen(s);
	words = ft_calloc(wc + 1, sizeof(char *));
	if (words == NULL)
		return (NULL);
	if (!find_words(s, words, len))
	{
		free_me(words, wc);
		return (NULL);
	}
	return (words);
}
