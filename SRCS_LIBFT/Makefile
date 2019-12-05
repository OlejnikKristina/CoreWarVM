# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/25 13:40:40 by asulliva       #+#    #+#                 #
#    Updated: 2019/12/05 14:45:24 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
CFLAGS	= -Wall -Wextra -Werror
LIBFT	= ./libft/

SRCS = srcs/precision.c srcs/width.c srcs/extra.c srcs/modifier.c \
srcs/conversion.c srcs/go_print.c \
srcs/handle_d.c srcs/handle_c.c srcs/ft_printf.c srcs/handle_s.c \
srcs/handle_modulo.c srcs/handle_p.c \
srcs/handle_f.c srcs/make_fstr.c srcs/handle_u.c srcs/handle_sx.c \
srcs/handle_o.c srcs/defines.c \
srcs/handle_f1.c srcs/handle_o1.c srcs/handle_p1.c srcs/handle_s1.c \
srcs/handle_d1.c srcs/handle_d2.c srcs/handle_d3.c \

OBJS	:= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@gcc $(CFLAGS) -c $(SRCS) -I .
	@ar rcs $(NAME) $(OBJS) ./libft/*.o
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all
