/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:04:20 by dclark            #+#    #+#             */
/*   Updated: 2021/03/10 11:46:49 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*get_line(char *tmp);
char	*get_after_eol(char *tmp);
char	*ft_strjoins(char *tmp, int tmp_sz, char *buffer, int bytes_read);
int		check_eol(char *tmp);
int		ft_strllen(char *str);
int		return_zero(char *tmp);

#endif
