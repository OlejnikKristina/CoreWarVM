/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit_ws.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 14:35:55 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/22 21:42:42 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"
#include <stdlib.h>

static int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int	ft_countwords(char const *s)
{
	int word_count;
	int i;

	word_count = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (!ft_iswhitespace(s[i]) &&\
		(ft_iswhitespace(s[i + 1]) || s[i + 1] == '\0'))
			word_count++;
		i++;
	}
	return (word_count);
}

static void	ft_cpychars(char const *s, char *word, int start, int stop)
{
	int i;

	i = 0;
	while (start < stop)
	{
		word[i] = s[start];
		start++;
		i++;
	}
	word[i] = '\0';
}

static char	**ft_cpwrds(char **words, char const *s)
{
	int i;
	int j;
	int start;
	int stop;

	i = -1;
	j = 0;
	start = 0;
	stop = 0;
	while (s[i] != '\0')
	{
		if (ft_iswhitespace(s[i]) || s[i] == '\0')
			start = i + 1;
		if (s[i] != '\0' && !ft_iswhitespace(s[i]) && (s[i + 1] == '\0' ||
			ft_iswhitespace(s[i + 1])))
		{
			stop = i + 1;
			words[j] = (char*)ft_memalloc(sizeof(char) * (stop - start + 1));
			ft_cpychars(s, words[j], start, stop);
			j++;
		}
		i++;
	}
	words[j] = 0;
	return (words);
}

char		**ft_strsplit_ws(char const *s)
{
	char	**words;
	int		w_count;

	if (s)
	{
		w_count = ft_countwords(s);
		words = (char**)ft_memalloc(sizeof(char*) * (w_count + 1));
		if (words)
			return (ft_cpwrds(words, s));
	}
	return (0);
}
