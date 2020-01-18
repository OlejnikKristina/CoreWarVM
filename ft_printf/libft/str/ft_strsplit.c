/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 16:04:09 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/14 16:28:58 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_strsplit_end(char **arr, int y)
{
	arr[y] = NULL;
	return (arr);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	int		y;
	char	**arr;
	int		end;

	y = 0;
	i = 0;
	arr = s ? (char **)malloc(kr_count_words(s, c) * sizeof(char *) + 1) : 0;
	if (arr == NULL || arr == 0)
		return (NULL);
	while (s[i] && y < kr_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		end = -1;
		end = findchr(&s[i], c);
		if ((end > -1)
			|| ((end = findchr(&s[i], '\0')) > -1))
		{
			arr[y] = ft_strsub(s, i, end);
			y++;
			i += end;
		}
	}
	return (ft_strsplit_end(arr, y));
}
