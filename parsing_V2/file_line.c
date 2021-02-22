/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:20:42 by dclark            #+#    #+#             */
/*   Updated: 2021/02/22 11:16:43 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	str_len(char *str)
{
	int	res;

	res = 0;
	while(str[res])
		res++;
	return (res);
}

static char	*str_join(char *s1, int	s1_sz, char *s2, int s2_sz)
{
	char	*dst;
	int		s1_sz_st;
	int		i_s;
	int		i_d;

	dst = malloc(sizeof(char) * (s1_sz + s2_sz + 1));
	i_s = 0;
	i_d = 0;
	s1_sz_st = s1_sz;
	while (0 < s1_sz--)
		dst[i_d++] = s1[i_s++];
	i_s = 0;
	while (0 < s2_sz--)
		dst[i_d++] = s2[i_s++];
	dst[i_d] = '\0';
	if (s1_sz_st > 0)
		free(s1);
	return (dst);
}

char	*file_line(int fd)
{
	int		bytes_read;
	char	*buffer;
	int		dst_sz;
	char	*dst;

	bytes_read = 1;
	dst_sz = 0;
	buffer = malloc(sizeof(char) * 1000001);
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, 1000000);
		if (bytes_read > 0)
			dst = str_join(dst, dst_sz, buffer, bytes_read);
		dst_sz = str_len(dst);
	}
	free(buffer);
	return (dst);
}
