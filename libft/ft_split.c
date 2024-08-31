/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:42:14 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/29 22:05:27 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*copy;
	size_t	i;

	copy = malloc(n + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n && *s != '\0')
	{
		copy[i] = *s;
		i++;
		s++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	const char	*word_start;
	char		**tab;
	size_t		i;

	tab = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!s || !tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_start = s;
			while (*s && *s != c)
				s++;
			tab[i] = ft_strndup(word_start, s - word_start);
			if (!tab[i])
				return (NULL);
			i++;
		}
		else
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
