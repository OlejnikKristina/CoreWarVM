/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:15:46 by asulliva          #+#    #+#             */
/*   Updated: 2019/12/08 22:56:21 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ASM_H
# define __ASM_H
# define MAX_INT 2147483647

# include <fcntl.h>
# include <unistd.h>
# include "../SRCS_LIBFT/libft/libft.h"
# include "../op.h"

typedef enum e_token	t_token;
typedef struct s_asm	t_asm;
typedef struct s_label	t_label;

enum					e_token {
	LABEL; //if string but not operation
	MODULO; //DIRECT_CHAR
	OPERATION; //make op funct that checks for possible op strings
	COMMA; //SEPARATOR_CHAR
	NEW_LINE;
	REGISTRY; //r
	NUMBER;
};

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
**	free.c
*/
void					free_arr(char **arr1, char ***arr2, int flag);
void					free_data(t_asm *data);

/*
**	name_comment.c
*/
void					parse_nc(t_asm *data, char *s, int type);

/*
**	parse.c
*/
void					parse(t_asm *data);
void					get_name_comment(t_asm *data);
#endif
