# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/21 19:23:26 by asulliva       #+#    #+#                 #
#    Updated: 2020/01/26 17:14:42 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror -g -lncurses
LIB			= ft_printf/libftprintf.a
HEADER		= -I./ft_printf/includes -I includes/
NAME		= corewar

SRC			= main.c\
			parse/parse.c parse/check_champs.c parse/flag.c parse/get_champ.c\
			parse/champs.c\
			utils/error.c utils/get_player.c utils/swap32.c utils/arg_size.c\
			utils/dump64.c utils/wait_cycles.c\
			utils/get_bytes.c utils/get_index.c utils/put_value.c utils/op.c\
			utils/format_check.c\
			init_game/init_game.c init_game/cursor.c\
			game/start_game.c game/execute.c game/get_args.c\
			ops/op.c ops/store.c ops/misc.c ops/fork.c ops/load.c ops/math.c\
			ops/bitwise.c

all: $(NAME)

$(NAME):
	@gcc  $(FLAGS) -o $(NAME) $(SRC) $(HEADER) $(LIB)
	@echo "\033[0;32mVM successfully created\033[0m"

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@rm -rf *.dSYM

re: fclean $(NAME)
