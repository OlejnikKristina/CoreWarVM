/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 18:51:51 by asulliva       #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/12/06 16:16:10 by asulliva      ########   odam.nl         */
=======
/*   Updated: 2019/12/06 17:25:54 by asulliva      ########   odam.nl         */
>>>>>>> aidan
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(*arr);
}

/*
**	@desc	- function gets line out of file trims it from whitespace,
**			- checks for comment tags copies relevant data to pointer
**	@param	- int fd, file descriptor of the opened file
**			- char **s, pointer to string to write file content in
**	@return	- int ret, amount of bytes read out of the file
*/

static int	get_line(int fd, char **s)
{
	int		ret;
	char	*line;
	char	*tmp;
	char	**split;

	ret = get_next_line(fd, &line);
	tmp = ft_strtrim(line);
	free(line);
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
		free(tmp);
		free_arr(split);
	}
	return (ret);
}

<<<<<<< HEAD
=======
/*
**	@desc	- function parses the .name and .comment commands
**	@param	- t_asm *data, main struct
**			- char *s, line read from the file
*/

void		parse_nc(t_asm *data, char *s)
{
	char	**split;

	ft_printf("line: %s\n", s);
	split = ft_strsplit(s, '"');
	data->wfd = 0;
}

/*
**	@desc	- function picks which parsing function to call
**	@param	- t_asm *data, main struct
**			- char *s, line read from the file
*/

>>>>>>> aidan
void		choose_parse(t_asm *data, char *s)
{
	if (s && ft_strlen(s) > 0)
	{
		if (!ft_strncmp(s, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			parse_nc(data, s);
		else if (!ft_strncmp(s, COMMENT_CMD_STRING,\
		ft_strlen(COMMENT_CMD_STRING)))
			parse_nc(data, s);
		else
			ft_putendl("faka");
	}
}

/*
**	@desc	- main parsing function
**	@param	- t_asm *data, main struct
*/

void		parse(t_asm *data)
{
	char	*s;

	while (get_line(data->rfd, &s))
	{
		if (s && ft_strlen(s) > 0)
			choose_parse(data, s);
		free(s);
	}
}
