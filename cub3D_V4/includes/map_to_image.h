/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:31:43 by dclark            #+#    #+#             */
/*   Updated: 2021/03/15 11:16:06 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TO_IMAGE_H
# define MAP_TO_IMAGE_H

# include "include.h"

# define SPACE 0,255,255,255
# define WALL 0,255,100,0
# define EMPTY 0,123,123,123
# define CARA 0,0,0,255
# define SPRITE 0,0,255,0

t_map_img	*map_to_img(t_map *map, t_win *win);

