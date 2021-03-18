/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:30:51 by dclark            #+#    #+#             */
/*   Updated: 2021/03/18 16:44:59 by dclark           ###   ########.fr       */
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

int	get_next_line(int fd, char **line);

#endif
