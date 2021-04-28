/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:07:16 by dclark            #+#    #+#             */
/*   Updated: 2021/04/28 15:16:47 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	res;

	if (!str)
		return (0);
	res = 0;
	while (str[res] != '\0')
	{
		res++;
	}
	return (res);
}

int		check_eol(char *tmp)
{
	int	i;

	i = 0;
	if (tmp == NULL)
		return (0);
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *tmp)
{
	char	*dest;
	int		i_n;
	int		i_d;

	i_n = 0;
	i_d = 0;
	if (!tmp)
		return (NULL);
	while (tmp[i_n] != '\n' && tmp[i_n])
		i_n++;
	if (!(dest = malloc(sizeof(char) * (i_n + 1))))
		return (NULL);
	while (i_n--)
	{
		dest[i_d] = tmp[i_d];
		i_d++;
	}
	dest[i_d] = '\0';
	return (dest);
}

char	*get_after_eol(char *tmp)
{
	char	*dest;
	int		i_t;
	int		i_d;

	i_t = 0;
	i_d = 0;
	if (!tmp)
		return (NULL);
	while (tmp[i_t] && tmp[i_t] != '\n')
		i_t++;
	if (tmp[i_t] == '\0' || tmp[i_t + 1] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	while (tmp[i_t + i_d])
		i_d++;
	if (!(dest = malloc(sizeof(char) * i_d)))
		return (NULL);
	i_d = -1;
	while (tmp[(i_t + 1) + ++i_d])
		dest[i_d] = tmp[(i_t + 1) + i_d];
	dest[i_d] = '\0';
	free(tmp);
	return (dest);
}

char	*ftft_strjoin(char *tmp, int tmp_sz, char *buffer, int bytes_read)
{
	char	*dest;
	int		i_d;
	int		i_s;

	i_d = 0;
	i_s = 0;
	if (tmp == NULL && bytes_read == 0)
		return (NULL);
	if (!(dest = malloc(sizeof(char) * (tmp_sz + bytes_read + 1))))
		return (NULL);
	while (0 < tmp_sz--)
		dest[i_d++] = tmp[i_s++];
	i_s = 0;
	while (0 < bytes_read--)
		dest[i_d++] = buffer[i_s++];
	dest[i_d] = '\0';
	free(tmp);
	return (dest);
}
