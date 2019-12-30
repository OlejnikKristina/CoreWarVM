/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_dir_sizes.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: krioliin <krioliin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/28 15:40:03 by krioliin       #+#    #+#                */
/*   Updated: 2019/12/28 17:07:50 by krioliin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DIR_SIZE_H
# define T_DIR_SIZE_H

/* Ops with size T_DIR 4 bytes */

#define LIVE 0x01
#define LD 0x02
#define ST 0x03
#define ADD 0x04
#define SUB 0x05
#define AND 0x06
#define OR 0x07
#define XOR 0x08
#define LLD 0x0d
#define AFF 0x10

/* Ops with size T_DIR 2 bytes */

#define ZJMP 0x09
#define LDI 0x0a
#define STI 0x0b
#define FORK 0x0c
#define LLDI 0x0e
#define LFORK 0x0f

#endif
