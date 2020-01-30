# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abumbier <abumbier@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/05 14:20:22 by asulliva       #+#    #+#                 #
#    Updated: 2020/01/30 15:21:56 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= dsm
SRCS	= main parse convert exec_code utils args write free
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g
HEADER	= includes/dsm.h
LIB		= ../ft_printf/libftprintf.a
OBJS	:= $(SRCS:%=%.o)
SRCS	:= $(SRCS:%=%.c)

all: $(OBJS) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $^ -o $(NAME) $(LIB)
	@echo "\033[0;32m[ + ] $(NAME) has been compiled\033[0m"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c -o $@ $< -I $(LIB)

clean:
	@rm -f $(OBJS)
	@echo "\033[0;33m[ - ] removed dsm files\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all
