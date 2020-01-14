# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/28 15:09:07 by krioliin       #+#    #+#                 #
#    Updated: 2020/01/14 18:53:45 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror -g -lncurses
LIB			= ft_printf/libftprintf.a
HEADER		= -I./ft_printf/includes -I includes/
NAME		= corewar

SRC			= main.c parse_argc.c parse_flags.c \
			get_champions_argc.c init_players.c utilities/vm_free.c \
			utilities/error_msg.c parse_champion.c utilities/cursor.c \
			utilities/introduction.c get_player_exec_code.c \
			decode_encoding_byte.c calculate_program_counter.c \
			init_battlefield.c init_cursors.c start_game.c \
			execute_cursor.c operations/encode_match_opcode.c \
			display_arena.c \
			operations/encode_match_opcode2.c execute_operation.c \
			operations/op_add.c operations/op_aff.c operations/op_and.c \
			operations/op_fork.c operations/op_lfork.c operations/op_ld.c \
			operations/op_ldi.c operations/op_lldi.c operations/op_lld.c \
			operations/op_live.c operations/op_or.c operations/op_sub.c \
			operations/op_st.c operations/op_sti.c operations/op_xor.c \
			operations/op_zjmp.c utilities/convert.c

VISUAL		= visual/corewar_visual.c visual/set_colors_to_players.c \
			utilities/get_player_by_id.c visual/display_info.c \
			visual/vinit_cursors.c visual/refresh_arena.c \
			visual/visual_sti.c visual/display_live_calls.c

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
