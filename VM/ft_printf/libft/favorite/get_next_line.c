/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/16 18:12:29 by krioliin      #+#    #+#                 */
/*   Updated: 2019/04/16 18:12:30 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_fd_list	*creat_elem(int fd)
{
	t_fd_list *new_elem;

	new_elem = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!new_elem)
		return (NULL);
	new_elem->fd = fd;
	new_elem->tail = ft_strnew(0);
	new_elem->next = NULL;
	return (new_elem);
}

t_fd_list	*find_fd(t_fd_list **top, int fd)
{
	t_fd_list *head;

	if (!(*top))
	{
		*top = creat_elem(fd);
		return (*top);
	}
	head = *top;
	while (head->next != NULL)
	{
		if (head->fd == fd)
			return (head);
		head = head->next;
	}
	if (head->fd == fd)
		return (head);
	head->next = creat_elem(fd);
	return (head->next);
}

int			fd_read(t_fd_list **elem, ssize_t size)
{
	ssize_t	byte;
	char	buff[size + 1];
	char	*temp;

	ft_bzero(buff, size + 1);
	if (findchr((*elem)->tail, '\n') > -1)
		return (1);
	while ((byte = read((*elem)->fd, buff, BUFF_SIZE)) >= 0)
	{
		if (buff[0] != '\0')
		{
			if (byte < BUFF_SIZE)
				buff[byte] = '\0';
			temp = (*elem)->tail;
			(*elem)->tail = ft_strjoin((*elem)->tail, buff);
			free(temp);
			if (ft_strchr(buff, '\n') || byte == 0)
				return (1);
		}
		if (ft_strlen((*elem)->tail) && byte == 0)
			return (1);
		if (byte == 0)
			return (0);
	}
	return (-1);
}

int			gnl_concat(const int fd, char **line)
{
	static t_fd_list	*top;
	t_fd_list			*elem;
	int					end;
	int					ret;
	int					len;

	elem = find_fd(&top, fd);
	if ((ret = fd_read(&elem, BUFF_SIZE)) > -1)
	{
		if ((end = findchr(elem->tail, '\n')) > -1)
		{
			*line = ft_strsub(elem->tail, 0, end);
			end += 1;
			len = ft_strlen(&elem->tail[end]);
			ft_memmove((void *)elem->tail, (const void *)elem->tail + end, len);
			elem->tail[len] = '\0';
		}
		else if ((end = findchr(elem->tail, '\0')) > -1)
		{
			*line = ft_strsub(elem->tail, 0, end);
			if (elem->tail)
				ft_bzero(elem->tail, ft_strlen(elem->tail));
		}
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	return (gnl_concat(fd, line));
}
