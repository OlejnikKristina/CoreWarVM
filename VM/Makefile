# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/21 19:23:26 by asulliva       #+#    #+#                 #
#    Updated: 2020/01/30 15:23:07 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror -g -lncurses
LIB			= ../ft_printf/libftprintf.a
HEADER		= -I../ft_printf/includes -I includes/
NAME		= corewar

SRC			= main.c\
			parse/parse.c parse/check_champs.c parse/flag.c parse/get_champ.c\
			parse/champs.c\
			utils/error.c utils/get_player.c utils/swap32.c utils/arg_size.c\
			utils/dump64.c utils/wait_cycles.c\
			utils/get_bytes.c utils/get_index.c utils/put_value.c utils/op.c\
			utils/format_check.c utils/free.c\
			init_game/init_game.c init_game/cursor.c\
			game/start_game.c game/execute.c game/get_args.c\
			ops/op.c ops/store.c ops/misc.c ops/fork.c ops/load.c ops/math.c\
			ops/bitwise.c
VISUAL		= visual/init_windows.c visual/init_color_pairs.c \
			visual/init_info_field.c \
			visual/display_game_params.c visual/add_pause.c \
			visual/refresh_arena.c \
			visual/visual_store.c visual/display_live_calls.c \
			visual/congrats_to_champion.c visual/display_players.c \
			visual/rm_prev_cursor_position.c

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(VISUAL) $(HEADER) $(LIB)
	@echo "\033[0;32m[ + ] VM successfully created\033[0m"

clean:
	@rm -f *.o
	@echo "\033[0;33m[ - ] removed vm's files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -rf *.dSYM
	@echo "\033[0;31m[ - ] removed vm compiling files\033[0m"

re: fclean $(NAME)
