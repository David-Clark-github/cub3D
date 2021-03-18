/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:50:24 by dclark            #+#    #+#             */
/*   Updated: 2021/03/18 15:39:58 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include "id_line.h"
# include "check_err.h"
# include "parsing.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define SPACE 0,255,255,255
# define WALL 0,150,150,150
# define EMPTY 0,50,50,50
# define CARA 0,255,0,0
# define SPRITE 0,0,255,0

char	**file_line_gnl(char *av);
void	print_split_l(char **sp_line);
int		get_next_line(int fd, char **line);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel(t_img_a *map_a, int x, int y, int color);
void	draw_square(t_img_a *map_a, int x, int y, int size, int color);
void	map_to_image(t_img_a *img_a, t_map *map, t_win *win);
int	func(int keycode, void *param);

#endif
