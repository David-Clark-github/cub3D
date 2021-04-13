/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:07:43 by dclark            #+#    #+#             */
/*   Updated: 2021/04/13 14:46:25 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "include.h"

static int	return_zero(char *tmp)
{
	free(tmp);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	bytes_read = 42;
	while (bytes_read && check_eol(tmp) != 1)
	{
		if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		tmp = ftft_strjoin(tmp, ft_strlen(tmp), buffer, bytes_read);
	}
	free(buffer);
	*line = get_line(tmp);
	tmp = get_after_eol(tmp);
	if (bytes_read == 0)
		return (return_zero(tmp));
	return (1);
}
