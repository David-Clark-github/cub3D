# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 12:16:27 by dclark            #+#    #+#              #
#    Updated: 2021/04/05 15:01:43 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_error.c \
			srcs/check_ac_av.c \
			srcs/file_line_gnl.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \
			srcs/id_line_master.c \
			srcs/id_res.c \
			srcs/id_north.c \
			srcs/id_south.c \
			srcs/id_east.c \
			srcs/id_west.c \
			srcs/id_sprite.c \
			srcs/id_floor.c \
			srcs/id_ceil.c \
			srcs/id_map.c \

OBJS	=	$(SRCS:.c=.o)

HEADER	=	includes/

NAME	=	cub3D

CFLAGS	+=	-Wall -Werror -Wextra -I $(HEADER)

CC		=	gcc

all:	libft.a $(NAME)

libft.a:
	make -C libft/

$(NAME): $(SRCS) libft.a
	$(CC) main.c $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME)

