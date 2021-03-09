/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftft_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:51:35 by dclark            #+#    #+#             */
/*   Updated: 2021/03/08 14:18:14 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int		strlenlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		count_word(char *line, char c)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			res++;
		i++;
	}
	return (res);
}

char	*copy(char *str)
{
	int		str_l;
	int		str_i;
	char	*dst;

	str_l = strlenlen(str);
	str_i = 0;
	dst = malloc(sizeof(char) * str_l + 1);
	while (str_l > 0)
	{
		dst[str_i] = str[str_i];
		str_l--;
	}
	dst[str_i] = '\0';
	return (dst);
}

char	**ftft_split(char *line, char c)
{
	char	**dst;
	int		dst_i;
	int		line_i;

	line_i = 0;
	dst_i = 0;
	dst = malloc(sizeof(char*) * count_word(line, '\n') + 1);
	while (dst_i < count_word(line, '\n'))
	{
		dst[dst_i] = copy(&line[line_i]);
		line_i += strlenlen(&line[line_i]);
		dst_i++;
	}
}
