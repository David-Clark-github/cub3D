# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 16:34:17 by dclark            #+#    #+#              #
#    Updated: 2021/03/18 16:37:52 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
CFLAGS	+=	-Wall -Werror -Wextra -I includes
LDFLAGS	+=	-L /usr/lib -lft -lmlx_Linux -lXext -lX11 -lm
CC		=	gcc

all:
	$(CC) $(CFLAGS) main.c src/*.c $(LDFLAGS) -o $(NAME)
