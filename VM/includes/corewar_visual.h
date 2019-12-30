/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   corewar_visual.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 14:19:39 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/30 18:50:36 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VISUAL_H
# define COREWAR_VISUAL_H

# define HEIGHT 55
# define WIDTH 150
# define OFFSETX 5
# define OFFSETY 5

# include "vm_arena.h"
# include "corewar_vs_colors.h"
# include <ncurses.h>

bool	visual_corawar(t_vm *vm);

#endif
