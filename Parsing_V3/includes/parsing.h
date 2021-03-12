/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:25:16 by user42            #+#    #+#             */
/*   Updated: 2021/03/12 15:03:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "mlx.h"
# include "libft.h"

typedef struct	s_resolution {
	int	x;
	int	y;
}				t_res;

typedef struct	s_north {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		height;
	int		width;
	int		endian;
}				t_north;

typedef struct	s_south {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		height;
	int		width;
	int		endian;
}				t_south;

typedef struct	s_west {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		height;
	int		width;
	int		endian;
}				t_west;

typedef struct	s_east {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		height;
	int		width;
	int		endian;
}				t_east;

typedef struct	s_sprite {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		height;
	int		width;
	int		endian;
}				t_sprite;

typedef struct	s_ceiling {
	int	R;
	int	G;
	int	B;
}				t_ceil;

typedef struct	s_floor {
	int	R;
	int	G;
	int	B;
}				t_floor;

typedef struct	s_map {
	int		height;
	int		width;
	char	*map;
}				t_map;

typedef struct	s_pars {
	t_res		res;
	t_north		north;
	t_south		south;
	t_west		west;
	t_east		east;
	t_sprite	sprite;
	t_ceil		ceil;
	t_floor		floor;
}				t_pars;
