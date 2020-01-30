# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abumbier <abumbier@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/05 14:20:22 by asulliva       #+#    #+#                 #
#    Updated: 2020/01/30 15:21:43 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= asm
SRCS	= main error parse free name_comment label instruction check_syntax \
valid_oper_line label_util token create_cor swap_endian \
write_cor_file encoding_byte write_size write_champ_byte write_dir

CC		= gcc
FLAGS	= -Wall -Werror -Wextra
HEADER	= includes/asm.h -I ../ft_printf/includes
LIB		= ../ft_printf/libftprintf.a
OBJS	:= $(SRCS:%=%.o)
SRCS	:= $(SRCS:%=%.c)

all: $(OBJS) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $^ -o $(NAME) $(LIB)
	@echo "\033[0;32m[ + ] $(NAME) has been compiled\033[0m"

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c -o $@ $< -I $(HEADER) $(LIB)

clean:
	@rm -f $(OBJS)
	@echo "\033[0;33m[ - ] removed object files from asm\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;33m[ - ] removed $(NAME)\033[0m"

re: fclean all
