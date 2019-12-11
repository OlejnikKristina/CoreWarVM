/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:15:46 by asulliva          #+#    #+#             */
/*   Updated: 2019/12/11 18:01:02 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ASM_H
# define __ASM_H
# define MAX_INT 2147483647

# include <fcntl.h>
# include <unistd.h>
# include "../SRCS_LIBFT/libft/libft.h"
# include "../op.h"

typedef enum e_arg		t_arg;
typedef enum e_oper		t_oper;
typedef struct s_asm	t_asm;
typedef struct s_label	t_label;
typedef struct s_parts	t_parts;

enum					e_arg {
	DIR = -2, //DIRECT_CHAR + num
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
	t_label				*labels;
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
**	instruction.c
*/
void					parse_instruction(t_asm *data, char **line);

/*
**	label.c
*/
void					parse_label(t_asm *data, char *s);
int						check_instruction(char *s);

/*
**	name_comment.c
*/
void					parse_nc(t_asm *data, char *s, int type);

/*
**	parse.c
*/
void					parse(t_asm *data);
int						get_line(t_asm *data, int fd, char **s, char **split);
#endif

void					check_syntax(t_parts *file);
int						valid_oper_line(t_parts **oper);
