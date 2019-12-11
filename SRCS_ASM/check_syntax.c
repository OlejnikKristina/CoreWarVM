/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:06:37 by abumbier          #+#    #+#             */
/*   Updated: 2019/12/11 18:04:46 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


void		check_syntax(t_parts *file)
{
	t_parts *token;

	token = file;
	while (token)
	{
		if (token->token >= LIVE && token->token <= AFF)
			if (!valid_oper_line(&token))
				break ; // free stuff n exit
		//calculate label values?
		//token = token->next;
	}
}
