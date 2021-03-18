/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:30:51 by dclark            #+#    #+#             */
/*   Updated: 2021/03/18 16:50:50 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
** Return the line of the element, -1 if not found
*/

/*
** Check each elements of the .cub file, return -1 if found an error, 1 is return
** oterwise
*/

int	check_exist(t_elem_l, *elem_l);

/*
** ---- PARSING ----
*/

/*
** ---- UTILS ----
*/

int	get_next_line(int fd, char **line);

#endif
