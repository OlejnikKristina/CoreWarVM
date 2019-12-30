# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abumbier <abumbier@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/05 14:20:22 by asulliva       #+#    #+#                 #
#    Updated: 2019/12/30 16:36:36 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= dsm
SRCS	= main error parse convert
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g
HEADER	= includes/dsm.h
LIBFTH	= ../SRCS_LIBFT/libft/
LIB		= ../SRCS_LIBFT/libft.a
OBJS	:= $(SRCS:%=%.o)
SRCS	:= $(SRCS:%=%.c)

all: $(OBJS) $(NAME)

$(NAME): $(OBJS)
	@make -C ../SRCS_LIBFT/
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
