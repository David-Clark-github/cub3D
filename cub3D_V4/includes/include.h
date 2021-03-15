/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:50:24 by dclark            #+#    #+#             */
/*   Updated: 2021/03/15 11:10:35 by dclark           ###   ########.fr       */
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
# include "map_to_image.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_map_img {
	void	*img;
	char	*addr;
	int		line_l;
	int		bpp;
	int		height;
	int		width;
	int		endian;
}				t_map_img;

typedef struct	s_window {
	void	*mlx;
	void	*win;
}				t_win;

char	**file_line_gnl(char *av);
void	print_split_l(char **sp_line);
int		get_next_line(int fd, char **line);
int		create_trgb(int t, int r, int g, int b);

#endif
