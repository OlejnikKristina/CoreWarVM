/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 14:31:21 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/10 16:02:35 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_instruction(char *s)
{
	if (ft_strchr(s, LABEL_CHAR))
		return (0x00);
	if (ft_strequ(s, "live"))
		return (LIVE);
	else if (ft_strequ(s, "ld"))
		return (0x02);
	else if (ft_strequ(s, "st"))
		return (0x03);
	else if (ft_strequ(s, "add"))
		return (0x04);
	else if (ft_strequ(s, "sub"))
		return (0x05);
	else if (ft_strequ(s, "and"))
		return (0x06);
	else if (ft_strequ(s, "or"))
		return (0x07);
	else if (ft_strequ(s, "xor"))
		return (0x08);
	else if (ft_strequ(s, "zjmp"))
		return (0x09);
	else if (ft_strequ(s, "ldi"))
		return (0x0a);
	else if (ft_strequ(s, "sti"))
		return (0x0b);
	else if (ft_strequ(s, "fork"))
		return (0x0c);
	else if (ft_strequ(s, "lld"))
		return (0x0d);
	else if (ft_strequ(s, "lldi"))
		return (0x0e);
	else if (ft_strequ(s, "lfork"))
		return (0x0f);
	else if (ft_strequ(s, "aff"))
		return (0x10);
	return (0x00);
}

t_parts		*make_instruction(int token, int line)
{
	t_parts	*new;

	new = ft_memalloc(sizeof(t_parts));
	new->token = token;
	new->line = line;
	return (new);
}

void		add_instruction(t_asm *data, t_parts *new)
{
	t_parts	*curr;

	curr = data->parts;
	while (curr)
		curr = curr->next;
	curr = new;
}

int			get_argument(char *s)
{
	if (s[0] == 'r')
		return (0);
	return (-1);
}

int			get_token(char *s)
{
	int		ret;

	ret = check_instruction(s);
	if (ret)
		return (ret);
	else
		return (get_argument(s));
}


void		parse_instruction(t_asm *data, char **line)
{
	t_parts	*new;
	int		i;

	i = 0;
	while (line[i])
	{
		new = make_instruction(get_token(line[i]), data->lines);
		add_instruction(data, new);
		i++;
	}
}

void		parse_label(t_asm *data, char *s)
{
	char	**split;
	
	data->wfd = 0;
	split = NULL;
	split = ft_strsplit_ws(s);
	if (check_instruction(split[0]))
		parse_instruction(data, split);
	else
	{
		if (!ft_strchr(split[0], LABEL_CHAR))
			error("Not a valid instruction", data->lines);
		else
			ft_printf("label: [%s]\n", split[0]);
	}
	
}