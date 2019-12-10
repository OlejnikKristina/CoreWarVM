/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 14:31:21 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/10 17:11:12 by asulliva      ########   odam.nl         */
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
		return (LD);
	else if (ft_strequ(s, "st"))
		return (ST);
	else if (ft_strequ(s, "add"))
		return (ADD);
	else if (ft_strequ(s, "sub"))
		return (SUB);
	else if (ft_strequ(s, "and"))
		return (AND);
	else if (ft_strequ(s, "or"))
		return (OR);
	else if (ft_strequ(s, "xor"))
		return (XOR);
	else if (ft_strequ(s, "zjmp"))
		return (ZJMP);
	else if (ft_strequ(s, "ldi"))
		return (LDI);
	else if (ft_strequ(s, "sti"))
		return (STI);
	else if (ft_strequ(s, "fork"))
		return (FORK);
	else if (ft_strequ(s, "lld"))
		return (LLD);
	else if (ft_strequ(s, "lldi"))
		return (LLDI);
	else if (ft_strequ(s, "lfork"))
		return (LFORK);
	else if (ft_strequ(s, "aff"))
		return (AFF);
	return (0x00);
}

t_parts		*make_instruction(int token, int line)
{
	t_parts	*new;

	new = malloc(sizeof(t_parts));
	new->str = NULL;
	new->token = token;
	new->line = line;
	new->next = NULL;
	return (new);
}

void		add_instruction(t_asm *data, t_parts *new)
{
	t_parts	*curr;

	curr = data->parts;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

int			get_argument(char *s)
{
	if (s[0] == 'r')
		return (REG);
	else if (s[0] == DIRECT_CHAR)
		return (DIR);
	else
		return (IND);
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
			parse_label();
	}
}