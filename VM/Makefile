# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/28 15:09:07 by krioliin       #+#    #+#                 #
#    Updated: 2020/01/02 21:27:19 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror -g -lncurses
LIB			= ft_printf/libftprintf.a
HEADER		= -I./ft_printf/includes -I includes/
NAME		= corewar

SRC			= main.c parse_argc.c parse_flags.c \
			get_champions_argc.c init_players.c vm_free.c \
			utilities/error_msg.c parse_champion.c cursor.c \
			utilities/introduction.c get_player_exec_code.c \
			decode_encoding_byte.c calculate_program_counter.c \
			init_battlefield.c

VISUAL		= visual/corewar_visual.c

all: $(NAME)

$(NAME):
	@clang  $(FLAGS) -o $(NAME) \
	$(SRC) $(VISUAL) $(HEADER) $(LIB)
	@echo "\033[0;32mVM successfully created\033[0m"

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
