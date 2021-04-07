# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 12:16:27 by dclark            #+#    #+#              #
#    Updated: 2021/04/07 15:00:23 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/print_data.c \
			srcs/ft_error.c \
			srcs/ft_empty_data.c \
			srcs/free_win.c \
			srcs/free_img.c \
			srcs/free_ray.c \
			srcs/free_text.c \
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
			srcs/init_data.c \
			srcs/check_master.c \
			srcs/check_res.c \
			srcs/check_xpm.c \
			srcs/check_floor_ceil.c \
			srcs/check_map1.c \
			srcs/check_map2.c \
			srcs/init_id_l.c \
			srcs/init_win.c \
			srcs/init_img.c \
			srcs/init_ply.c \
			srcs/init_ray.c \
			srcs/init_text.c \
			srcs/parsing_master.c \
			srcs/pars_res.c \
			srcs/pars_xpm.c \

OBJS	=	$(SRCS:.c=.o)

HEADER	=	includes/

NAME	=	cub3D

CFLAGS	+=	-Wall -Werror -Wextra -I $(HEADER)

CC		=	gcc

all:	libft.a $(NAME)

libft.a:
	make -C libft/

$(NAME): $(SRCS) libft.a
	$(CC) main.c $(CFLAGS) $(SRCS) libft/libft.a -lm -lmlx -lXext -lX11 -o $(NAME)

