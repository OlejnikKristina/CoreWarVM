/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_champions_argc.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 17:43:08 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/27 16:37:06 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm_arena.h"

char	**safe_players_files(char *file)
{
	static char	**players_files;
	static int	i;

	if (i == 0)
		players_files = (char **)ft_memalloc(sizeof(char *) * MAX_PLAYERS);
	if (file && !ft_strcmp((const char *)file, "free it"))
	{
		while (0 < i)
		{
			i--;
			ft_strdel(&players_files[i]);
		}
		free(players_files);
	}
	else if (file)
	{
		players_files[i] = (char *)ft_memalloc(ft_strlen(file));
		players_files[i] = (char *)ft_strcpy(players_files[i], file);
		i++;
	}
	return (players_files);
}

bool	check_champion(char *file_name)
{
	int		len;

	len = ft_strlen(file_name);
	if (5 <= len && ft_strstr(&file_name[len - 4], ".cor"))
		return (true);
	return (false);
}

bool	check_champ_file_name(char *file_name)
{
	int		len;
	int		fd;
	char	c;

	len = ft_strlen(file_name);
	if (5 <= len && ft_strstr(&file_name[len - 4], ".cor"))
	{
		fd = open(file_name, O_RDONLY);
		if (fd <= 0)
		{
			ft_printf("%{RED_B}Can't open file [%s]\n", file_name);
			ft_printf("%{RESET}");
			return (false);
		}
		else if (read(fd, &c, 0) < 0)
		{
			ft_printf("%{RED_B}Can't read from file [%s]\n", file_name);
			ft_printf("%{RESET}");
			return (false);
		}
		safe_players_files(file_name);
		close(fd);
		return (true);
	}
	return (false);
}
