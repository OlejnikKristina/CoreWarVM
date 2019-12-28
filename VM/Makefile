# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/28 15:09:07 by krioliin       #+#    #+#                 #
#    Updated: 2019/12/28 15:26:07 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror -g
LIB			= ft_printf/libftprintf.a
HEADER		= -I./ft_printf/includes -I includes/
NAME		= corewar

SRC			= main.c parse_argc.c parse_flags.c \
			get_champions_argc.c init_players.c vm_free.c \
			utilities/error_msg.c parse_champion.c cursor.c \
			utilities/introduction.c get_player_exec_code.c

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
