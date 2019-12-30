#ifndef __DSM_H
# define __DSM_H
# define MAX_INT 2147483647

# include <fcntl.h>
# include <unistd.h>
# include "../../LIBFT_SRCS/libft/libft.h"
# include "../../op.h"

# define LIVE 0x01
# define LD 0x02
# define ST 0x03
# define ADD 0x04
# define SUB 0x05
# define AND 0x06
# define OR 0x07
# define XOR 0x08
# define LLD 0x0d
# define AFF 0x10
# define ZJMP 0x09
# define LDI 0x0a
# define STI 0x0b
# define FORK 0x0c
# define LLDI 0x0e
# define LFORK 0x0f

typedef struct s_dsm	t_dsm;
struct					s_dsm
{
	int					rfd;
	int					wfd;
	int					size;
	char				*name;
	char				*comment;
};

void	error(char *message, int usage);
void	parse(t_dsm *data);
int 	convert(unsigned char *s, int size);
void	get_exec_code(t_dsm *data);
#endif