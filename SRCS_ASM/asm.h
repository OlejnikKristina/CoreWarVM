/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <abumbier@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 14:15:46 by asulliva       #+#    #+#                */
/*   Updated: 2019/12/10 17:08:41 by asulliva      ########   odam.nl         */
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
	REG = -5, // r + number
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
	int					value; // if 0 no value
	t_parts				*next;
};

struct					s_label {
	char				*name;
	int					line;
	t_label				*next;
};

struct					s_asm {
	int					rfd;
	int					wfd;
	int					lines;
	char				*name;
	char				*comment;
	t_parts				*parts;
};

/*
**  error.c
*/
void					error(char *message, int line);

/*
**	free.c
*/
void					free_arr(char **arr1, char ***arr2, int flag);
void					free_data(t_asm *data);

/*
**	label.c
*/
void					parse_label(t_asm *data, char *s);
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
