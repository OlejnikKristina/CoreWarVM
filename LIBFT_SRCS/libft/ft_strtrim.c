/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: awehlbur <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:33:40 by awehlbur      #+#    #+#                 */
/*   Updated: 2019/01/17 15:33:43 by awehlbur      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	k = i;
	while (s[k] != '\0')
		k++;
	k--;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k--;
	return (ft_strsub(s, i, k - i + 1));
}
