/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   findchr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 19:14:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/05 18:32:01 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		findchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}
