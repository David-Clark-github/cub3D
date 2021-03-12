# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/12 12:15:42 by user42            #+#    #+#              #
#    Updated: 2021/03/12 12:19:42 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
CFLAGS		+=	-Wall -Werror -Wextra -I includes
LDFLAGS		+=	-L /usr/lib -lft -lmlx_Linux -lXext -lX11
CC			= gcc

all:
	$(CC) $(CFLAGS) main.c parsing/*.c $(LDFLAGS) -o $(NAME)
