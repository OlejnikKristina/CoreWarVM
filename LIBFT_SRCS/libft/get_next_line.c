/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 11:54:03 by asulliva       #+#    #+#                */
/*   Updated: 2019/08/06 17:17:28 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static int			ft_copytill(char **line, char *src, char c)
{
	int		i;
	int		j;
	int		pos;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			break ;
		i++;
	}
	pos = i;
	j = 0;
	while (src[j] != c && src[j])
	{
		*line = ft_strjoinone(*line, src[j]);
		j++;
	}
	return (pos);
}

static t_list		*get_correct_file(t_list **file, int fd)
{
	t_list	*temp;

	temp = *file;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", 1);
	temp->content_size = fd;
	ft_lstadd(file, temp);
	return (temp);
}

static int			ft_read(int fd, t_list *current, char *buf)
{
	int		ret;
	char	*temp;

	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		temp = current->content;
		current->content = ft_strjoin(temp, buf);
		VALIDATE((current->content));
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*list;
	char			*buf;
	int				ret;
	t_list			*current;
	char			*temp;

	buf = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	VALIDATE(buf);
	if (fd < 0 || line == NULL || (read(fd, buf, 0) < 0))
		return (-1);
	current = get_correct_file(&list, fd);
	*line = ft_strnew(0);
	ret = ft_read(fd, current, buf);
	if (ret < BUFF_SIZE && !ft_strlen(current->content))
		return (0);
	ret = ft_copytill(line, current->content, '\n');
	if (ret < (int)ft_strlen(current->content))
	{
		temp = current->content;
		current->content = ft_strdup(current->content + ret + 1);
		free(temp);
	}
	else
		ft_strclr(current->content);
	return (1);
}
