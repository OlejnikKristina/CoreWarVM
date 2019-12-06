/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 18:51:51 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/06 15:02:52 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_line(int fd, char **s)
{
	int		ret;
	char	*tmp;
	char	**split;

	ret = get_next_line(fd, s);
	tmp = ft_strtrim(*s);
	if (!tmp || !ft_strlen(tmp) || tmp[0] == '#' || tmp[0] == ';')
	{
		*s = ft_strdup("");
		free(tmp);
		return (ret);
	}
	*s = tmp;
	split = NULL;
	if (ft_strchr(tmp, '#'))
		split = ft_strsplit(tmp, '#');
	else if (ft_strchr(tmp, ';'))
		split = ft_strsplit(tmp, ';');
	if (split)
	{
		*s = ft_strtrim(ft_strdup(split[0]));
		free(split);
	}
	free(tmp);
	return (ret);
}

void		parse(t_asm *data, char **s)
{
	while (get_line(data->rfd, s))
	{
		ft_printf("[%s]\n", *s);
		// if (ft_strlen(*s) > 0)
		// 	choose_parse(data, s);
	}
}
