# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/05 14:20:22 by asulliva       #+#    #+#                 #
#    Updated: 2019/12/05 18:09:19 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= asm
SRCS	= main error file
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
HEADER	= asm.h
LIBFTH	= ../SRCS_LIBFT/libft/
LIB		= ../SRCS_LIBFT/libft.a
OBJS	:= $(SRCS:%=%.o)
SRCS	:= $(SRCS:%=%.c)

all: $(OBJS) $(NAME)

$(NAME): $(OBJS)
	@make -C ../SRCS_LIBFT/
	@$(CC) $(FLAGS) $^ -o $(NAME) $(LIB)
	@echo "[ + ] $(NAME) has been compiled"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c -o $@ $< -I $(LIBFTH)

clean:
	@rm -f $(OBJS)
	@echo "[ - ] removed object files"

fclean: clean
	@rm -f $(NAME)
	@echo "[ - ] removed $(NAME)"

re: fclean all
