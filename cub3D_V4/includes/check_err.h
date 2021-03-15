/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:45:54 by user42            #+#    #+#             */
/*   Updated: 2021/03/15 12:10:51 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ERR_H
# define CHECK_ERR_H

# include "include.h"
# include "libft.h"
# include "mlx.h"
# include "id_line.h"

typedef struct	s_element_error {
	int	res;
	int	north;
	int	south;
	int	west;
	int	east;
	int	sprit;
	int	floor;
	int	ceil;
	int	map;
}				t_elem_err;

typedef struct	s_map_error {
	int		y_max;
	int		x_max;
	int		player;
	char	**map;
}				t_map_err;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		width;
	int		height;
	int		endian;
}				t_img;

void	print_elem_err(t_elem_err *elem_check);

void	init_elem_err(t_elem_err *el_err, t_elem_l *el_l, char **line_s);
int		check_error(t_elem_err *el_err);

int		res_check_err(char *line_res);
int		floor_check_err(char *line_res);
int		ceiling_check_err(char *line_res);
int		path_check_error(char *line);

int		map_check_err(t_map_err *map_err, char **line_s, int map_st);
int		check_map(char **map);
int		one_player_map(char **map);
int		empty_line_map(char **map);
int		caract_map(char **map);
int		cara_voisin(t_map_err *map_err);

#endif
