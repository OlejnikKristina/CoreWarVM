/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:15:46 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/06 16:17:21 by asulliva      ########   odam.nl         */
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
typedef struct s_label	t_label;

struct					s_label {
	char				*name;
	int					id;
	t_label				*next;
};

struct					s_asm {
	int					rfd;
	int					wfd;
	char				*name;
	char				*comment;
};

/*
**  error.c
*/
void					error(char *message);

/*
**	parse.c
*/
void					parse(t_asm *data);
void					get_name_comment(t_asm *data);
#endif
