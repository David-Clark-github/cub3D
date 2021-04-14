/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:36:36 by dclark            #+#    #+#             */
/*   Updated: 2021/04/14 10:13:26 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_save(t_data *data)
{
	(void)data;
	int	fd;

	fd = open("save.bmp", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	write(fd, "BM", 2);
	close(fd);
	ft_error("Image sauvée dans save.bmp", 0, data);	
}
