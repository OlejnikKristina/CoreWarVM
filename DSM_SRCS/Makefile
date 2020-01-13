# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abumbier <abumbier@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/05 14:20:22 by asulliva       #+#    #+#                 #
#    Updated: 2020/01/05 16:44:24 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= dsm
SRCS	= main parse convert exec_code utils args write free
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g
HEADER	= includes/dsm.h
LIBFTH	= ../LIBFT_SRCS/libft/
LIB		= ../LIBFT_SRCS/libft.a
OBJS	:= $(SRCS:%=%.o)
SRCS	:= $(SRCS:%=%.c)

all: $(OBJS) $(NAME)

$(NAME): $(OBJS)
	@make -C ../LIBFT_SRCS/
	@$(CC) $(FLAGS) $^ -o $(NAME) $(LIB)
	@echo "\033[0;32m[ + ] $(NAME) has been compiled\033[0m"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c -o $@ $< -I $(LIBFTH)

clean:
	@rm -f $(OBJS)
	@echo "\033[0;31m[ - ] removed object files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m[ - ] removed $(NAME)\033[0m"

re: fclean all
