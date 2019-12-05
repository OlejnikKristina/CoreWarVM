/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:15:46 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/05 18:10:25 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ASM_H
# define __ASM_H
# define MAX_INT 2147483647

# include <fcntl.h>
# include <unistd.h>
# include "../SRCS_LIBFT/libft/libft.h"
# include "../op.h"

typedef struct s_asm	t_asm;
typedef struct s_lines	t_lines;
typedef struct s_label	t_label;

struct					s_lines {
	char				*line;
	t_lines				*next;
};

struct					s_asm {
	int					rfd;
	int					wfd;
	char				*content;
	t_lines				*file;
};

/*
**  error.c
*/
void	    			error(char *message);

/*
**	file.c
*/
void					readfile(t_asm *data);
#endif