/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:50:24 by dclark            #+#    #+#             */
/*   Updated: 2021/03/12 14:13:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"
# include "id_line.h"
# include "check_err.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	**file_line_gnl(char *av);
void	print_split_l(char **sp_line);
int		get_next_line(int fd, char **line);

/*
****************	Check_error				****************
*/

#endif
