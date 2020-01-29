/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 17:46:00 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/12 18:05:30 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*new_str;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (space(s[start]))
		start++;
	while (space(s[end]) && 0 <= end)
		end--;
	if (end < 0)
		return (ft_strsub(&s[0], 0, 0));
	new_str = ft_strsub(s, start, end - start + 1);
	if (!new_str)
		return (NULL);
	new_str[end + 1] = '\0';
	return (new_str);
}
