#ifndef __DSM_H
# define __DSM_H
# define MAX_INT 2147483647

# include <fcntl.h>
# include <unistd.h>
# include "../../SRCS_LIBFT/libft/libft.h"
# include "../../op.h"

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
#endif