/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:15:46 by asulliva          #+#    #+#             */
/*   Updated: 2019/12/10 15:56:09 by abumbier         ###   ########.fr       */
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
	DIR = -2, //DIRECT_CHAR + num
	OPERATION, //one of the t_oper values; funct that checks the str.
	COMMA = -3, //SEPARATOR_CHAR
	NEW_LINE = -4,
	REGISTRY = -5, // r + number
	IND = -6, // indirect arg
};

enum					e_oper {
	LIVE = 0x01,
	LD = 0x02,
	ST = 0x03,
	ADD = 0x04,
	SUB = 0x05,
	AND = 0x06,
	OR = 0x07,
	XOR = 0x08,
	ZJMP = 0x09,
	LDI = 0x0a,
	STI = 0x0b,
	FORK = 0x0c,
	LLD = 0x0d,
	LLDI = 0x0e,
	LFORK = 0x0f,
	AFF = 0x10
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
