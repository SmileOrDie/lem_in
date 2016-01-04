/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_m_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamdani <shamdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:53:21 by shamdani          #+#    #+#             */
/*   Updated: 2016/01/04 17:34:08 by shamdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int				ft_word_counter(const char *s, char c)
{
	int					counter;
	int					in_substr;

	in_substr = 0;
	counter = 0;
	while (*s == c && *s != '\0')
		s++;
	while (*s != '\0')
	{
		if (in_substr == 1 && *s == c)
			in_substr = 0;
		if (in_substr == 0 && *s != c)
		{
			in_substr = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}

static int				ft_word_len(const char *s, char c)
{
	int					len;

	len = 0;
	while (*s == c && *s != '\0')
	{
		len++;
		s++;
	}
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char					**sp_split(const char *s)
{
	char				**t;
	int					nb_word;
	int					index;
	int					n;

	if (!s)
		return ((char **)s);
	index = 0;
	nb_word = ft_word_counter((const char *)s, ' ');
	t = (char **)malloc(sizeof(*t) * (nb_word + 1));
	if (t == NULL)
		return (NULL);
	while (nb_word--)
	{
		n = ft_word_len((const char *)s, ' ');
		t[index] = ft_strsub((const char *)s, 0, n);
		if (t[index] == NULL)
			return (NULL);
		s = s + n + 1;
		index++;
	}
	t[index] = NULL;
	return (t);
}

char					**m_split(const char *s)
{
	char				**t;
	int					nb_word;
	int					index;
	int					n;

	if (!s)
		return ((char **)s);
	index = 0;
	nb_word = ft_word_counter((const char *)s, '-');
	t = (char **)malloc(sizeof(*t) * (nb_word + 1));
	if (t == NULL)
		return (NULL);
	while (nb_word--)
	{
		n = ft_word_len((const char *)s, '-');
		t[index] = ft_strsub((const char *)s, 0, n);
		if (t[index] == NULL)
			return (NULL);
		s = s + n + 1;
		index++;
	}
	t[index] = NULL;
	return (t);
}
