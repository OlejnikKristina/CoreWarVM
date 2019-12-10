/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:06:37 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/10 15:45:38 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


void		test(t_parts *file)
{
	t_parts *token;

	token = file;
	while (token)
	{
		if (token->token == LABEL)
			valid_label(&token);
		else if (token->token >= LIVE && token->token <= AFF)
			valid_oper(&token);
		token = token->next;
	}
}

int			valid_oper(t_parts **oper)
{
	*oper->token 
}

