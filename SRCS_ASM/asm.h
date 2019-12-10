/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:15:46 by asulliva          #+#    #+#             */
/*   Updated: 2019/12/09 21:08:14 by abumbier         ###   ########.fr       */
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
typedef enum e_oper		t_oper;
typedef struct s_asm	t_asm;
typedef struct s_label	t_label;
typedef struct s_parts	t_parts;

enum					e_token {
	LABEL = -1, //if string but not operation
	MODULO = -2, //DIRECT_CHAR
	OPERATION, //one of the t_oper values; funct that checks the str.
	COMMA = -3, //SEPARATOR_CHAR
	NEW_LINE = -4,
	REGISTRY = -5, // r + number
	NUMBER = -6, // indirect arg
};

enum					e_oper {
	LIVE = 1,
	LD = 2,
	ST = 3,
	ADD = 4,
	SUB = 5,
	AND = 6,
	OR = 7,
	XOR = 8,
	ZJMP = 9,
	LDI = 10,
	STI = 11,
	FORK = 12,
	LLD = 13,
	LLDI = 14,
	LFORK = 15,
	AFF = 16
};

struct					s_parts {
	char				*str;
	int					token;
	int					line;
	t_parts				*next;
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
