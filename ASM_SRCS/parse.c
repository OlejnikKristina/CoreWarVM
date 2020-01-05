/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 18:51:51 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/05 16:59:56 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

/*
**	@desc	- function trims a string split on comment_char
**	@param	- char **split, the split string to trim
**			- char *tmp, pointer to be freed
*/

static char	*set_trimmed(char **split, char *tmp)
{
	char	*line;
	char	*s;

	line = ft_strdup(split[0]);
	s = ft_strtrim(line);
	free(line);
	free_arr(&tmp, &split, 2);
	return (s);
}

/*
**	@desc	- function gets line out of file trims it from whitespace,
**			- checks for comment tags copies relevant data to pointer
**	@param	- int fd, file descriptor of the opened file
**			- char **s, pointer to string to write file content in
**	@return	- int ret, amount of bytes read out of the file
*/

int			get_line(t_asm *data, int fd, char **s, char **split)
{
	int		ret;
	char	*line;
	char	*tmp;

	ret = get_next_line(fd, &line);
	data->lines++;
	tmp = ft_strtrim(line);
	free(line);
	if (!tmp || !ft_strlen(tmp) ||
	tmp[0] == COMMENT_CHAR || tmp[0] == ALT_COMMENT_CHAR)
	{
		*s = ft_strnew(0);
		free(tmp);
		return (ret);
	}
	*s = tmp;
	if (ft_strchr(tmp, COMMENT_CHAR))
		split = ft_strsplit(tmp, COMMENT_CHAR);
	else if (ft_strchr(tmp, ALT_COMMENT_CHAR))
		split = ft_strsplit(tmp, ALT_COMMENT_CHAR);
	if (split)
		*s = set_trimmed(split, tmp);
	return (ret);
}

/*
**	@desc	- function picks which parsing function to call
**	@param	- t_asm *data, main struct
**			- char *s, line read from the file
*/

void		choose_parse(t_asm *data, char *s)
{
	if (s && ft_strlen(s) > 0)
	{
		if (!ft_strncmp(s, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			parse_nc(data, s, 0);
		else if (!ft_strncmp(s, COMMENT_CMD_STRING,\
		ft_strlen(COMMENT_CMD_STRING)))
			parse_nc(data, s, 1);
		else
			parse_label(data, s);
	}
}

/*
**	@desc	- main parsing function
**	@param	- t_asm *data, main struct
*/

void		parse(t_asm *data)
{
	char	*s;

	while (get_line(data, data->rfd, &s, NULL))
	{
		if (s && ft_strlen(s) > 0)
			choose_parse(data, s);
		free(s);
	}
	free(s);
}
