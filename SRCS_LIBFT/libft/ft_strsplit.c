/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 13:41:09 by asulliva       #+#    #+#                */
/*   Updated: 2019/07/11 17:07:15 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_words(const char *s, char c)
{
	int		words;
	int		flag;

	flag = 0;
	words = 0;
	if (!s || !c)
		return (0);
	while (*s != '\0')
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			words++;
		}
		s++;
	}
	return (words);
}

static int		ft_word_len(const char *s, char c)
{
	int		len;

	len = 0;
	if (!s || !c)
		return (0);
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	words = ft_words(s, c);
	if (!s || !c)
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * ft_words(s, c) + 1);
	if (!tab)
		return (NULL);
	while (words)
	{
		words--;
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_strsub(s, 0, ft_word_len(s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + ft_word_len(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
