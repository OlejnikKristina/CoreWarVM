/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_msg.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 16:33:18 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/29 15:16:56 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/includes/ft_printf.h"

bool	error_msg(unsigned short erro_num)
{
	ft_printf("%{RED_B}Error");
	if (erro_num == 1)
		ft_printf(" in magic file\n");
	if (erro_num == 2)
		ft_printf(". Can't read file: ");
	if (erro_num == 3)
		ft_printf(". file is too small. Incorrect champion name");
	if (erro_num == 4)
		ft_printf(". Champion name should be a null termineted\n");
	if (erro_num == 5)
	{
		ft_printf(" in player executable code size is too big\n");
		ft_printf("Your player is just too fat\n");
	}
	if (erro_num == 6)
		ft_printf(". Champion's comment is too small\n");
	if (erro_num == 7)
	{
		ft_printf(" in player executable code, size is too small\n");
		ft_printf("Your player weight nothing and this is a problem\n");
	}
	if (erro_num == 8)
		ft_printf(" in champion's code. Regestir number is too big\n");
	ft_printf("%{RESET}");
	return (true);
}
