/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dsm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: asulliva <asulliva@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 20:09:35 by asulliva       #+#    #+#                */
/*   Updated: 2020/01/02 20:42:42 by asulliva      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DSM_H
# define __DSM_H
# define MAX_INT 2147483647

# include <fcntl.h>
# include <unistd.h>
# include "../../LIBFT_SRCS/libft/libft.h"
# include "../../op.h"

# define LIVE		0x01
# define LD			0x02
# define ST			0x03
# define ADD		0x04
# define SUB		0x05
# define AND		0x06
# define OR			0x07
# define XOR		0x08
# define LLD		0x0d
# define AFF		0x10
# define ZJMP		0x09
# define LDI		0x0a
# define STI		0x0b
# define FORK		0x0c
# define LLDI		0x0e
# define LFORK		0x0f
# define NB_OPS		0x0f

typedef struct s_dsm	t_dsm;
typedef struct s_op		t_op;

struct		s_dsm
{
	int		rfd;
	int		wfd;
	int		size;
	char	*name;
	char	*comment;
	t_op	*ops;
};

struct		s_op
{
	char	*op_name;
	char	**args;
	t_op	*next;
};

void		error(char *message, int usage);
void		parse(t_dsm *data);
int			convert(unsigned char *s, int size);
void		get_exec_code(t_dsm *data);
int			enc_byte(int op);
int			dir_size(int op);
int			arg_amnt(int op);
void		free_arr(char **arr1, char ***arr2, int flag);
#endif
