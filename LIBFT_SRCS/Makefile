# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/25 13:40:40 by asulliva       #+#    #+#                 #
#    Updated: 2019/12/06 18:18:02 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
CFLAGS	= -Wall -Wextra -Werror
LIBFT	= ./libft/

SRCS = precision.c width.c extra.c modifier.c \
conversion.c go_print.c \
handle_d.c handle_c.c ft_printf.c handle_s.c \
handle_modulo.c handle_p.c \
handle_f.c make_fstr.c handle_u.c handle_sx.c \
handle_o.c defines.c \
handle_f1.c handle_o1.c handle_p1.c handle_s1.c \
handle_d1.c handle_d2.c handle_d3.c \

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
