# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dclark <dclark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 12:16:27 by dclark            #+#    #+#              #
#    Updated: 2021/04/21 16:06:15 by dclark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/ft_error.c \
			srcs/ft_empty_data.c \
			srcs/ft_save.c \
			srcs/free_win.c \
			srcs/free_img.c \
			srcs/free_map.c \
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
			srcs/init_map.c \
			srcs/parsing_master.c \
			srcs/pars_res.c \
			srcs/pars_xpm.c \
			srcs/pars_sprite.c \
			srcs/pars_floor.c \
			srcs/pars_ceil.c \
			srcs/pars_ply.c \
			srcs/pars_img.c \
			srcs/index_color.c \
			srcs/ceil_floor_to_img.c \
			srcs/my_put_pixel.c \
			srcs/trgb.c \
			srcs/draw_text_line.c \
			srcs/algo.c \
			srcs/algo_sprite.c \
			srcs/move.c \
			srcs/rotate_left.c \
			srcs/rotate_right.c \
			srcs/forward.c \
			srcs/backward.c \
			srcs/crabe_left.c \
			srcs/crabe_right.c \
			srcs/exec.c \

SRCS_B	=	bonus/ft_error_bonus.c \
			bonus/ft_empty_data_bonus.c \
			bonus/ft_save_bonus.c \
			bonus/free_win_bonus.c \
			bonus/free_img_bonus.c \
			bonus/free_map_bonus.c \
			bonus/free_ray_bonus.c \
			bonus/free_text_bonus.c \
			bonus/check_ac_av_bonus.c \
			bonus/file_line_gnl_bonus.c \
			bonus/get_next_line_bonus.c \
			bonus/get_next_line_utils_bonus.c \
			bonus/id_line_master_bonus.c \
			bonus/id_res_bonus.c \
			bonus/id_north_bonus.c \
			bonus/id_south_bonus.c \
			bonus/id_east_bonus.c \
			bonus/id_west_bonus.c \
			bonus/id_sprite_bonus.c \
			bonus/id_floor_bonus.c \
			bonus/id_ceil_bonus.c \
			bonus/id_map_bonus.c \
			bonus/init_data_bonus.c \
			bonus/check_master_bonus.c \
			bonus/check_res_bonus.c \
			bonus/check_xpm_bonus.c \
			bonus/check_floor_ceil_bonus.c \
			bonus/check_map1_bonus.c \
			bonus/check_map2_bonus.c \
			bonus/init_id_l_bonus.c \
			bonus/init_win_bonus.c \
			bonus/init_img_bonus.c \
			bonus/init_ply_bonus.c \
			bonus/init_ray_bonus.c \
			bonus/init_text_bonus.c \
			bonus/init_map_bonus.c \
			bonus/parsing_master_bonus.c \
			bonus/pars_res_bonus.c \
			bonus/pars_xpm_bonus.c \
			bonus/pars_sprite_bonus.c \
			bonus/pars_floor_bonus.c \
			bonus/pars_ceil_bonus.c \
			bonus/pars_ply_bonus.c \
			bonus/pars_img_bonus.c \
			bonus/index_color_bonus.c \
			bonus/ceil_floor_to_img_bonus.c \
			bonus/my_put_pixel_bonus.c \
			bonus/trgb_bonus.c \
			bonus/draw_text_line_bonus.c \
			bonus/draw_map_bonus.c \
			bonus/algo_bonus.c \
			bonus/algo_sprite_bonus.c \
			bonus/move_bonus.c \
			bonus/rotate_left_bonus.c \
			bonus/rotate_right_bonus.c \
			bonus/forward_bonus.c \
			bonus/backward_bonus.c \
			bonus/crabe_left_bonus.c \
			bonus/crabe_right_bonus.c \
			bonus/exec_bonus.c \
			bonus/floor_ceil_texture_bonus.c \

HEADER	=	includes/

NAME	=	cub3D

BONUS	=	cub3D_bonus

CFLAGS	+=	-Wall -Werror -Wextra -I $(HEADER)

CC		=	gcc

all:	libft.a $(NAME)

libft.a:
	make -C libft/

clean:
	make clean -C libft/

fclean:	clean
	make fclean -C libft/
	rm -f cub3D
	rm -f save.bmp
	rm -f save_bonus.bmp
	rm -f cub3D_bonus

re:		fclean
	make $(NAME)

$(NAME): $(SRCS) libft.a
	$(CC) main.c $(CFLAGS) $(SRCS) libft/libft.a -lm -lmlx -lXext -lX11 -o $(NAME)

bonus: $(SRCS_B) libft.a
	$(CC) main_bonus.c $(CFLAGS) $(SRCS_B) libft/libft.a -lm -lmlx -lXext -lX11 -o $(BONUS)
