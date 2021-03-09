# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/07 16:49:01 by dclark            #+#    #+#              #
#    Updated: 2021/03/08 13:54:53 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CFLAGS		+=	-Wall -Werror -Wextra -I includes
LDFLAGS		+=	-L/usr/local/lib -lft -lmlx_Linux -lXext -lX11
CC			=	gcc

all:
	$(CC) $(CFLAGS) main.c check_error/*.c check_exist/*.c src/*.c 
