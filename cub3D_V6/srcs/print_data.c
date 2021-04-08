/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:40:38 by dclark            #+#    #+#             */
/*   Updated: 2021/04/08 15:28:32 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	print_id_l(t_id_l *id_l)
{
	printf("\nres = %d\n", id_l->res);
	printf("north = %d\n", id_l->north);
	printf("south = %d\n", id_l->south);
	printf("east = %d\n", id_l->east);
	printf("west = %d\n", id_l->west);
	printf("sprite = %d\n", id_l->sprite);
	printf("floor = %d\n", id_l->floor);
	printf("ceil = %d\n", id_l->ceil);
	printf("map = %d\n", id_l->map);
}

static void	print_win(t_win *win)
{
	printf("\nmlx = %p\n", win->mlx);
	printf("win = %p\n", win->win);
	printf("win_w = %d\n", win->width);
	printf("win_h = %d\n", win->height);
}

static void	print_xpm(t_text *text)
{
	printf("\nimg = %p\n", text->img);
	printf("addr = %p\n", text->addr);
	printf("bpp = %d\n", text->bpp);
	printf("line_l = %d\n", text->line_l);
	printf("width = %d\n", text->width);
	printf("height = %d\n", text->height);
	printf("endian = %d\n", text->endian);
}

static void	print_ceil(t_ceil *ceil)
{
	printf("\nceil\n");
	printf("r = %d\n", ceil->r);
	printf("g = %d\n", ceil->g);
	printf("b = %d\n", ceil->b);
}

static void	print_floor(t_floor *floor)
{
	printf("\nfloor\n");
	printf("r = %d\n", floor->r);
	printf("g = %d\n", floor->g);
	printf("b = %d\n", floor->b);
}

static void	print_mapou(t_mapou *map)
{
	printf("\nmap_width = %d\n", map->map_w);
	printf("map_height = %d\n", map->map_h);
	//ft_print_split(map->map);
}

void		print_data(t_data *data)
{
	ft_print_split(data->raw_cub);
	print_id_l(&data->id_l);
	print_win(&data->win);
	print_xpm(&data->text[0]);
	print_xpm(&data->text[1]);
	print_xpm(&data->text[2]);
	print_xpm(&data->text[3]);
	print_xpm(&data->text[4]);
	print_floor(&data->floor);
	print_ceil(&data->ceil);
	print_mapou(&data->map);
}
