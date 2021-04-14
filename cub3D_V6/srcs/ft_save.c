/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:36:36 by dclark            #+#    #+#             */
/*   Updated: 2021/04/14 15:48:46 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static void	ft_header(int fd, t_data *data)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 54 + (4 * data->win.height * data->win.width);
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &data->win.width, 4);
	write(fd, &data->win.height, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &data->img.bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

static void	ft_fill_save(int fd, t_data *data)
{
	int	y;
	int	x;

	y = data->win.height;
	while (--y >= 0)
	{
		x = -1;
		while (++x < data->win.width)
			write(fd, &data->img.addr[y * data->img.line_l +\
			(x * data->img.bpp / 8)], 4);
	}
}

void	ft_save(t_data *data)
{
	int	fd;

	fd = open("save.bmp", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	ft_header(fd, data);
	ft_fill_save(fd, data);
	close(fd);
	ft_error("Image sauvée dans save.bmp", 0, data);	
}
