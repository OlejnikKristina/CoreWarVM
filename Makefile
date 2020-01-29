# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/29 17:45:05 by krioliin       #+#    #+#                 #
#    Updated: 2020/01/29 19:24:31 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PATH_VM	:=	vm/
PATH_ASM:=	asm/
PATH_DSM:=	dsm/
LIB		:=	ft_printf/

all:
	make -C $(LIB)
	make -C $(PATH_ASM)
	make -C $(PATH_VM)
	make -C $(PATH_DSM)
	chmod 744 $(ASM)asm
	chmod 744 $(VM)corewar

clean:
	make -C $(LIB) clean
	make -C $(PATH_ASM) clean
	make -C $(PATH_VM) clean
	make -C $(PATH_DSM) clean

fclean:
	make -C $(LIB) fclean
	make -C $(PATH_ASM) fclean
	make -C $(PATH_VM) fclean
	make -C $(PATH_DSM) fclean

re: fclean all

