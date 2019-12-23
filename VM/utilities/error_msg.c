/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_msg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 16:33:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/23 17:46:52 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/ft_printf.h"
// #include "ft_printf.h"

bool	error_msg(unsigned short erro_num)
{
	ft_printf("%{RED_B} Error");
	if (erro_num == 1)
		ft_printf(" in magic file\n");
	if (erro_num == 2)
		ft_printf(". Can't read file: ");
	if (erro_num == 3)
		ft_printf(". file is too small. Incorrect champion name");
	if (erro_num == 4)
		ft_printf(". Champion name should be a null termineted\n");
	if (erro_num == 5)
		ft_printf("in player code size\n");
	if (erro_num == 6)
		ft_printf(". Champion's comment is too small\n");
	ft_printf("%{RESET}");
	return (true);
}
