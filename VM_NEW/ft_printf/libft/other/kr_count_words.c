/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kr_count_words.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 19:15:11 by krioliin       #+#    #+#                */
/*   Updated: 2019/04/05 18:30:39 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		kr_count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}
