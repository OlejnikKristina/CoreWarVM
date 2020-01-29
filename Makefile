# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/29 17:45:05 by krioliin       #+#    #+#                 #
#    Updated: 2020/01/29 20:13:31 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ASM		:=	asm
PATH_VM	:=	vm/
PATH_ASM:=	asm_/
PATH_DSM:=	dsm_/
LIB		:=	ft_printf/

all:
	@make -C $(LIB)
	@make -C $(PATH_ASM)
	@make -C $(PATH_VM)
	# @make -C $(PATH_DSM)
	@ ln -fs $(PATH_ASM)asm asm
	@ ln -fs $(PATH_VM)corewar corewar
	# @ ln -fs $(PATH_DSM)dsm dsm
	@chmod 744 asm
	@chmod 744 corewar

mre:
	@ make mre -C $(PATH_ASM)
	@ make mre -C $(PATH_VM)
	@ ln -fs $(PATH_ASM)asm asm
	@ ln -fs $(PATH_VM)corewar corewar
	@ chmod 744 asm corewar

clean:
	@make -C $(LIB) clean
	@make -C $(PATH_ASM) clean
	@make -C $(PATH_VM) clean
	# @make -C $(PATH_DSM) clean

fclean: clean
	@rm -f asm

re: fclean all

