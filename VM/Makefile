# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/20 15:30:36 by krioliin       #+#    #+#                 #
#    Updated: 2019/12/22 11:35:51 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror -g
LIB			= ft_printf/libftprintf.a
HEADER		= -I./ft_printf/includes -I includes/
NAME		= corewar

SRC			= main.c parse_argc.c parse_flags.c \
			parse_champions.c init_players.c vm_free.c

all: $(NAME)

$(NAME):
	@clang $(FLAGS) -o $(NAME) \
	$(SRC) $(HEADER) $(LIB)
	@echo "\033[0;32mVM successfully created\033[0m"

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
