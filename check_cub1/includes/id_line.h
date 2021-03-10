/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_line.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:06:21 by dclark            #+#    #+#             */
/*   Updated: 2021/03/10 21:15:38 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ID_LINE_H
# define ID_LINE_H

# include "libft.h"
# include <stdio.h>

typedef struct	s_element_line {
	int	res;
	int	north;
	int	south;
	int	west;
	int	east;
	int	sprit;
	int	floor;
	int	ceil;
	int	map;
}				t_elem_l;

int		identify_lines(char **sp_line, t_elem_l *elem_l);
void	init_elem_line(t_elem_l *elem_l);
void    print_elem_l(t_elem_l *elem_l);
void	res_line(char **line_s, t_elem_l *elem_l);
void	north_line(char **sp_line, t_elem_l *elem_l);
void	south_line(char **sp_line, t_elem_l *elem_l);
void	west_line(char **sp_line, t_elem_l *elem_l);
void	east_line(char **sp_line, t_elem_l *elem_l);
void	sprit_line(char **sp_line, t_elem_l *elem_l);
void	floor_line(char **sp_line, t_elem_l *elem_l);
void	ceil_line(char **sp_line, t_elem_l *elem_l);
void	map_line(char **sp_line, t_elem_l *elem_l);
int		check_exist(t_elem_l *elem_l);

#endif
