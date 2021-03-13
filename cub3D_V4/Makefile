# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 12:03:51 by dclark            #+#    #+#              #
#    Updated: 2021/03/13 14:20:48 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CFLAGS		=	-Wall -Werror -Wextra -I includes
LDFLAGS		=	-L /usr/lib -lft -lmlx_Linux -lXext -lX11
CC			=	gcc

all:
	$(CC) $(CFLAGS) main.c check_exist/*.c check_error/*.c parsing/*.c \
		src/*.c $(LDFLAGS) -o $(NAME)
