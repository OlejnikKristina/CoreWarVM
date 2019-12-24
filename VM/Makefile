# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: asulliva <asulliva@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/24 12:26:22 by asulliva       #+#    #+#                 #
#    Updated: 2019/12/24 12:26:24 by asulliva      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror
LIB			= ft_printf/libftprintf.a
HEADER		= -I./ft_printf/includes -I includes/
NAME		= corewar

SRC			= main.c parse_argc.c parse_flags.c \
			get_champions_argc.c init_players.c vm_free.c \
			utilities/error_msg.c parse_champion.c

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
